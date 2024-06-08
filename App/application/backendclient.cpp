#include "backendclient.h"

/**
 * @brief Получить экземпляр бэкэнд процессора.
 * @return Указатель на экземпляр BackendClient.
 */
BackendClient* BackendClient::getclient()
{
    if (!client)
    {
        client = new BackendClient();
        destroyer.initialize(client);
    }
    return client;
}

/**
 * @brief Инициализация BackendClient. Вызывается в @getclient().
 * @param parent Указатель на родительский QObject.
 */
BackendClient::BackendClient(QObject* parent) : QObject(parent)
{
    open_entering_window();

    TcpSocket = new QTcpSocket(this);
    TcpSocket->connectToHost("127.0.0.1", 33333);
    connect(TcpSocket, &QTcpSocket::readyRead, this, &BackendClient::slotServerRead);
}

/**
 * @brief Деструктор для BackendClient.
 */
BackendClient::~BackendClient() {
    if (TcpSocket->isOpen()) TcpSocket->close();
    if (!authorization_state) {
        delete enteringWindow;
        delete registerWindow;
    }
    delete mainWindow;
    delete menuWindow;
    delete bookingWindow;
    delete basketWindow;
    delete profileWindow;
}

/**
 * @brief Сравнить хэш с сервера с локальным.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 * @return True, если авторизация успешна, иначе false.
 */
bool BackendClient::authorization_server_responce(QString login, QString password) {
    QString hashed_pass = Hash(password.toStdString()).get_hash();

    qDebug() << "Проверка корректности пароля";

    QJsonObject json;
    json.insert("type", "authorization");
    json.insert("login", login);
    json.insert("hashed_pass", hashed_pass);
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    TcpSocket->write(strJson.toUtf8());
    TcpSocket->flush();

    while (TcpSocket->waitForReadyRead(5000)) {
        QByteArray response = TcpSocket->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();
        qDebug() << jsonObject["auth_status"].toBool();
        qDebug() << jsonObject;

        if (jsonObject["auth_status"].toBool()) {
            return true;
        }
        else {
            return false;
        }
    }
    qDebug() << "Ошибка: время ожидания ответа истекло\n";
    return false;
}

/**
 * @brief Авторизация пользователя с использованием логина и пароля.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 */
void BackendClient::authentificate(QString login, QString password) {
    QMessageBox message_box;
    message_box.setText("Авторизация не удалась");

    if (login.isEmpty() || password.isEmpty()) {
        message_box.setInformativeText(QString("Некоторые поля пусты"));
        message_box.exec();
    }
    else {
        if (client->authorization_server_responce(login, password)) {
            qDebug() << QString("Авторизован как " + login);

            open_main_window();

            authorization_state = true;
            delete enteringWindow;
            delete registerWindow;
        }
        else {
            message_box.setInformativeText(QString("Попробуйте другую комбинацию логина и пароля"));
            message_box.exec();
        }
    }
}

/**
 * @brief Отправить данные регистрации на сервер.
 * @param name Имя пользователя.
 * @param login Логин пользователя.
 * @param email Email пользователя.
 * @param hashed_pass Хэшированный пароль.
 * @return True, если данные регистрации успешно отправлены.
 */
bool BackendClient::registration_server_responce(QString name, QString login, QString email, QString hashed_pass) {
    QJsonObject json;
    json.insert("type", "registration");
    json.insert("name", name);
    json.insert("login", login);
    json.insert("email", email);
    json.insert("hashed_pass", hashed_pass);
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    TcpSocket->write(strJson.toUtf8());
    TcpSocket->flush();
    return true;
}

/**
 * @brief Зарегистрировать нового пользователя.
 * @param name Имя пользователя.
 * @param login Логин пользователя.
 * @param email Email пользователя.
 * @param password Пароль пользователя.
 * @param password_repeat Повторенный пароль пользователя для подтверждения.
 */
void BackendClient::registration(QString name, QString login, QString email, QString password, QString password_repeat) {
    QMessageBox message_box;
    message_box.setText("Регистрация не удалась");

    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = regex.match(email);

    if (password.isEmpty() || name.isEmpty() || login.isEmpty() || email.isEmpty() || password_repeat.isEmpty()) {
        message_box.setInformativeText(QString("Некоторые поля пусты"));
        message_box.exec();
    }
    else if (!match.hasMatch()) {
        message_box.setInformativeText(QString("Неверный формат email"));
        message_box.exec();
    }
    else if (password == password_repeat) {
        QString hashed_pass = Hash(password.toStdString()).get_hash();

        qDebug() << "\nОтправка информации на сервер";
        if (client->registration_server_responce(name, login, email, hashed_pass)) {
            qDebug() << ("Успешная регистрация с именем: " + name + "; логином: " +  login + "; email: " + email);

            open_main_window();

            authorization_state = true;
            delete enteringWindow;
            delete registerWindow;
        }
        else {
            qDebug() << ("Ошибка: не удалось зарегистрироваться с именем: " + name + "; логином: " + login + "; email: " + email);
        }
    }
    else {
        message_box.setInformativeText(QString("Пароли не совпадают"));
        message_box.exec();
    }
}

/**
 * @brief Отправить базовое сообщение на сервер.
 * @param query Сообщение, которое нужно отправить на сервер.
 */
void BackendClient::send_message_to_server(QString query)
{
    TcpSocket->write(query.toUtf8());
}

/**
 * @brief Слот для обработки ответов от сервера.
 */
void BackendClient::slotServerRead()
{
    QString message = "";
    while (TcpSocket->bytesAvailable()>0)
    {
        QByteArray array = TcpSocket->readAll

();
        message.append(array);
    }
    qDebug() << message;
    emit message_from_server(message);
}

/**
 * @brief Показать окно входа.
 */
void BackendClient::open_entering_window()
{
    if (!enteringWindow) {
        enteringWindow = new entering_window();
    }
    enteringWindow->show();
}

/**
 * @brief Показать окно регистрации.
 */
void BackendClient::open_register_window()
{
    if (!registerWindow) {
        registerWindow = new register_window();
    }
    registerWindow->show();
}

/**
 * @brief Показать главное окно.
 */
void BackendClient::open_main_window()
{
    if (!mainWindow) {
        mainWindow = new MainWindow();
        basketWindow = new BasketWindow();
    }
    mainWindow->show();
}

/**
 * @brief Показать окно меню.
 */
void BackendClient::open_menu_window()
{
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
}

/**
 * @brief Показать окно бронирования.
 */
void BackendClient::open_booking_window()
{
    if (!bookingWindow) {
        bookingWindow = new BookingWindow();
    }
    bookingWindow->show();
}

/**
 * @brief Показать окно корзины.
 */
void BackendClient::open_basket_window()
{
    if (!basketWindow) {
        basketWindow = new BasketWindow();
    }
    basketWindow->show();
}

/**
 * @brief Показать окно профиля.
 */
void BackendClient::open_profile_window()
{
    if (!profileWindow) {
        profileWindow = new ProfileWindow();
    }
    profileWindow->show();
}

/**
 * @brief Реализация паттерна Singleton для BackendClient.
 */
BackendClient* BackendClient::client;

/**
 * @brief Экземпляр BackendClientDestroyer для безопасного удаления единственного экземпляра BackendClient.
 */
BackendClientDestroyer BackendClient::destroyer;

/**
 * @brief Флаг состояния авторизации.
 */
bool BackendClient::authorization_state = false;

/**
 * @brief Указатель на главное окно.
 */
MainWindow* BackendClient::mainWindow;

/**
 * @brief Указатель на окно меню.
 */
MenuWindow* BackendClient::menuWindow;

/**
 * @brief Указатель на окно входа.
 */
entering_window* BackendClient::enteringWindow;

/**
 * @brief Указатель на окно регистрации.
 */
register_window* BackendClient::registerWindow;

/**
 * @brief Указатель на окно бронирования.
 */
BookingWindow* BackendClient::bookingWindow;

/**
 * @brief Указатель на окно корзины.
 */
BasketWindow* BackendClient::basketWindow;

/**
 * @brief Указатель на окно профиля.
 */
ProfileWindow* BackendClient::profileWindow;

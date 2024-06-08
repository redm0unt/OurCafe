#ifndef BACKENDCLIENT_H
#define BACKENDCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>

#include "entering_window.h"
#include "register_window.h"
#include "mainwindow.h"
#include "menuwindow.h"
#include "hash.h"
#include "bookingwindow.h"
#include "basketwindow.h"
#include "profilewindow.h"

/**
 * @brief Класс BackendClient представляет собой клиентскую часть приложения,
 * которая устанавливает соединение с сервером и обрабатывает коммуникацию с ним.
 */
class BackendClient;

/**
 * @brief Класс BackendClientDestroyer используется для уничтожения экземпляра BackendClient.
 */
class BackendClientDestroyer
{
private:
    BackendClient *client;
public:
    ~BackendClientDestroyer() { delete client; }
    void initialize(BackendClient *p) { client = p; }
};

/**
 * @brief Класс BackendClient представляет собой клиентскую часть приложения,
 * которая устанавливает соединение с сервером и обрабатывает коммуникацию с ним.
 */
class BackendClient : public QObject
{
    Q_OBJECT
private:
    static BackendClient *client;
    static BackendClientDestroyer destroyer;

    // Сокет для связи с сервером
    QTcpSocket* TcpSocket;

    static bool authorization_state;

    // Окна приложения
    static entering_window* enteringWindow;
    static register_window* registerWindow;
    static MainWindow* mainWindow;
    static BookingWindow* bookingWindow;
    static ProfileWindow* profileWindow;

protected:
    /**
     * @brief Конструктор класса BackendClient.
     * @param parent Указатель на родительский QObject.
     */
    explicit BackendClient(QObject* parent = nullptr);
    BackendClient(BackendClient&) = delete;
    BackendClient& operator=(BackendClient&) = delete;

    /**
     * @brief Деструктор класса BackendClient.
     */
    ~BackendClient();
    friend class BackendClientDestroyer;

public:
    /**
     * @brief Получить экземпляр класса BackendClient.
     * @return Указатель на экземпляр BackendClient.
     */
    static BackendClient* getclient();

    static BasketWindow* basketWindow;
    static MenuWindow* menuWindow;

    /**
     * @brief Отправить сообщение на сервер.
     * @param query Сообщение для отправки.
     */
    void send_message_to_server(QString query);

    /**
     * @brief Получить состояние авторизации.
     * @return True, если авторизация выполнена, иначе false.
     */
    bool get_auth_state() { return authorization_state; }

    /**
     * @brief Отправить запрос авторизации на сервер.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @return True, если запрос выполнен успешно, иначе false.
     */
    bool authorization_server_responce(QString, QString);

    /**
     * @brief Отправить запрос регистрации на сервер.
     * @param name Имя пользователя.
     * @param login Логин пользователя.
     * @param email Email пользователя.
     * @param hashed_pass Хэшированный пароль пользователя.
     * @return True, если запрос выполнен успешно, иначе false.
     */
    bool registration_server_responce(QString, QString, QString, QString);

    /**
     * @brief Аутентификация пользователя.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     */
    static void authentificate(QString, QString);

    /**
     * @brief Регистрация нового пользователя.
     * @param name Имя пользователя.
     * @param login Логин пользователя.
     * @param email Email пользователя.
     * @param password Пароль пользователя.
     * @param password_repeat Повторение пароля пользователя для подтверждения.
     */
    static void registration(QString, QString, QString, QString, QString);

    /**
     * @brief Запустить приложение.
     */
    static void start_application();

    /**
     * @brief Показать окно входа.
     */
    static void open_entering_window();

    /**
     * @brief Показать окно регистрации.
     */
    static void open_register_window();

    /**
     * @brief Показать главное окно.
     */
    static void open_main_window();

    /**
     * @brief Показать окно меню.
     */
    static void open_menu_window();

    /**
     * @brief Показать окно брониров

    /**
     * @brief Показать окно бронирования.
     */
    static void open_booking_window();

    /**
     * @brief Показать окно корзины.
     */
    static void open_basket_window();

    /**
     * @brief Показать окно профиля.
     */
    static void open_profile_window();

signals:
    /**
     * @brief Сигнал, отправляемый при получении сообщения от сервера.
     * @param message Полученное сообщение.
     */
    void message_from_server(QString message);

public slots:
    /**
     * @brief Слот для обработки данных, полученных от сервера.
     */
    void slotServerRead();
};

#endif // BACKENDCLIENT_H

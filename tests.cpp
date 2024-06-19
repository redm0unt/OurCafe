#include <QtTest>
// Импорт тестируемых фукнций (если необходимо)
// #include "functions.cpp"


// Пример функции
double summ(double num1, double num2) { return num1 + num2; }


// Класс unit-тестирования
class functions_test : public QObject
{
    Q_OBJECT

public:
    functions_test();
    ~functions_test();

// Объявление тест кейсов
private slots:
    void test_case_1();
    void test_case_2();
};


functions_test::functions_test() {}
functions_test::~functions_test() {}

// Так нужно прописывать тест кейсы, в которых проверяются функции
void functions_test::test_case_1(){
    QVERIFY2(summ(0, 1) == 1, "summ(0, 1) != 1");   // вторым аргументом указывается то что покажется в случае если тест не будет пройден
}
void functions_test::test_case_2() {
    QVERIFY2(summ(5, 5) == 10, "summ(5, 5) != 10");
}


// Запуск проверки
QTEST_APPLESS_MAIN(functions_test)

// обязательный #include с именем файла в котором происходит тестирование и расширением .moc (если что название этого файла tests.cpp)
#include "tests.moc"

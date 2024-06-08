/**
 * @file hash.h
 * @brief Заголовочный файл с описанием класса Hash для вычисления хэш-значения пароля.
 */

#ifndef HASH_H
#define HASH_H

#include <QString>

class Hash {
public:
    /**
     * @brief Длина статус-бара.
     */
    static const int b = 1600;     

    /**
     * @brief Длина блока.
     */
    static const int r = 1088;     

    /**
     * @brief Длина добавочной части.
     */
    static const int c = 512;      

    /**
     * @brief Длина "слова".
     */
    static const int w = 64;       

    /**
     * @brief Количество итераций.
     */
    static const int nr = 24;      

    /**
     * @brief Хэш-значение.
     */
    QString value;

    /**
     * @brief Конструктор класса Hash.
     * 
     * @param pass Пароль, для которого вычисляется хэш-значение.
     */
    Hash(std::string pass);

    /**
     * @brief Функция преобразования символа в бинарное представление.
     * 
     * @param c Символ для преобразования.
     * @return Бинарное представление символа.
     */
    std::string bin(char c);

    /**
     * @brief Функция вычисления первичного хэша.
     * 
     * @param pass Пароль для вычисления хэша.
     * @return Первичное хэш-значение пароля.
     */
    std::string prime_hash(std::string pass);

    /**
     * @brief Функция добавления нулей в конец строки.
     * 
     * @param line Строка, к которой добавляются нули.
     * @return Строка с добавленными нулями.
     */
    std::string pad(std::string line);

    /**
     * @brief Функция дополнения строки нулями.
     * 
     * @param line Строка, которую нужно дополнить нулями.
     * @return Дополненная строка.
     */
    std::string complete_zero(std::string line);

    /**
     * @brief Функция применения операции XOR к последовательностям битов.
     * 
     * @param a Первая последовательность битов.
     * @param b Вторая последовательность битов.
     * @return Результат применения операции XOR.
     */
    std::string xor_bit(std::string a, std::string b);

    /**
     * @brief Функция применения операции XOR к отдельным битам.
     * 
     * @param a Первый бит.
     * @param b Второй бит.
     * @return Результат применения операции XOR к отдельным битам.
     */
    char xor_bit(char a, char b);

    /**
     * @brief Функция вращения элемента.
     * 
     * @param s 3D массив символов.
     * @param x Координата x.
     * @param y Координата y.
     * @param z Координата z.
     * @param d Расстояние вращения.
     * @return Вращенный элемент.
     */
    char rot(char ***s, int x, int y, int z, int d);

    /**
     * @brief Функция инверсии бита.
     * 
     * @param c Бит для инверсии.
     * @return Инвертированный бит.
     */
    char opposite(char c);

    /**
     * @brief Функция выполнения операции AND над битами.
     * 
     * @param a Первый бит.
     * @param b Второй бит.
     * @return Результат операции AND.
     */
    char char_and(char a, char b);

    /**
     * @brief Функция перестановки.
     * 
     * @param S Строка для перестановки.
     * @return Результат перестановки.
     */
    std::string permutation(std::string S);

    /**
     * @brief Получение хэш-значения в виде QString.
     * 
     * @return Хэш-значение в виде QString.
     */
    QString get_hash();

    /**
     * @brief Получение хэш-значения в виде стандартной строки.
     * 
     * @return Хэш-значение в виде стандартной строки.
     */
    std::string getStdHash();
};

#endif // HASH_H

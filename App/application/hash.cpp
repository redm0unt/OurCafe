/**
 * @file hash.h
 * @brief Заголовочный файл с описанием класса Hash для вычисления хэш-значения пароля.
 */

#include "hash.h"

using namespace std;

/**
 * @brief Конструктор класса Hash.
 * 
 * @param pass Пароль, для которого вычисляется хэш-значение.
 */
Hash::Hash(string pass) {
    // Генерация первичного хэша
    std::string b = permutation(complete_zero(pad(prime_hash(pass))));
    std::string res;
    // Произведение перестановок
    for (int i = 0; i < 10; i++) {b = permutation(b);}
    // Сборка окончательного хэша
    for (int i = 0; i < 256; i++) {res += b[i];}
    value = QString::fromStdString(res);
}

/**
 * @brief Функция преобразования символа в бинарное представление.
 * 
 * @param c Символ для преобразования.
 * @return Бинарное представление символа.
 */
string Hash::bin(char c) {
    int num = c;
    string out;
    while (num > 0) {
        out = to_string(num%2) + out;
        num /= 2;
    }
    return out;
}

/**
 * @brief Функция вычисления первичного хэша.
 * 
 * @param pass Пароль для вычисления хэша.
 * @return Первичное хэш-значение пароля.
 */
string Hash::prime_hash(string pass) {
    string hash;     // Актуальное хэш-значение
    for (unsigned long i = 0; i < pass.size(); i++) hash = bin(pass[i]) + hash;
    return hash;
}

/**
 * @brief Функция добавления нулей в конец строки.
 * 
 * @param line Строка, к которой добавляются нули.
 * @return Строка с добавленными нулями.
 */
string Hash::pad(string line) {
    string part;
    if (r - line.size() == 1) {part = "1";}
    if (r - line.size() >= 2) {
        part += '1';
        for (unsigned long i = 0; i < r - 2 - line.size(); i++) part += '0';
        part += '1';
    }
    return line + part;
}

/**
 * @brief Функция дополнения строки нулями.
 * 
 * @param line Строка, которую нужно дополнить нулями.
 * @return Дополненная строка.
 */
string Hash::complete_zero(string line) {
    string part;
    for (int i = 0; i < c; i++) {part += '0';}
    return line + part;
}

/**
 * @brief Функция применения операции XOR к последовательностям битов.
 * 
 * @param a Первая последовательность битов.
 * @param b Вторая последовательность битов.
 * @return Результат применения операции XOR.
 */
string Hash::xor_bit(string a, string b) {
    string res;
    for (unsigned long i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i]) {res += '0';}
        else {res += '1';}
    }
    return res;
}

/**
 * @brief Функция применения операции XOR к отдельным битам.
 * 
 * @param a Первый бит.
 * @param b Второй бит.
 * @return Результат применения операции XOR к отдельным битам.
 */
char Hash::xor_bit(char a, char b) {
    if (a == b) { return '0'; }
    else { return '1'; }
}

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
char Hash::rot(char ***s, int x, int y, int z, int d) {
    int new_z = z + d;
    if (new_z >= 0) { return s[x][y][new_z % w]; }
    return s[x][y][((w - (-new_z)%w) % w)];
}

/**
 * @brief Функция инверсии бита.
 * 
 * @param c Бит для инверсии.
 * @return Инвертированный бит.
 */
char Hash::opposite(char c) {
    if (c == '0') { return '1'; }
    return '0';
}

/**
 * @brief Функция выполнения операции AND над битами.
 * 
 * @param a Первый бит.
 * @param b Второй бит.
 * @return Результат операции AND.
 */
char Hash::char_and(char a, char b){
    if (a == '1' && b == '1') {return '1';}
    else {return '0';}
}

/**
 * @brief Функция перестановки.
 * 
 * @param S Строка для перестановки.
 * @return Результат перестановки.
 */
string Hash::permutation(string S) {
    if (S.size() == 1600) {
        int move = 0;
        // Инициализация временного 3D массива нулями
        char ***S2 = new char ** [5];
        for (int i = 0; i < 5; i++) {
            S2[i] = new char * [5];
            for (int j = 0; j < 5; j++) {
                S2[i][j] = new char [64];
                for (int k = 0; k < 64; k++) {S2[i][j][k] = '0';}
            }
        }
        // Переписывание строки в 3D массив для упрощения работы
        char ***S1 = new char ** [5];
        for (int i = 0; i < 5; i++) {
            S1[i] = new char * [5];
            for (int j = 0; j < 5; j++) {
                S1[i][j] = new
char [64];
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S[k + move];}
                move += w;
            }
        }

        // Шаг theta
        char bit_sum;
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 64; k++) {
                bit_sum = xor_bit(S1[i][0][k], rot(S1, i, 0, k, -1));
                for (int j = 1; j < 5; j++) {
                    bit_sum = xor_bit(bit_sum, xor_bit(S1[i][j][k], rot(S1, i, j, k, -1)));
                }
                for (int j = 0; j < 5; j++) {
                    S2[i][j][k] = xor_bit(S1[i][j][k], bit_sum);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S2[i][j][k];}
            }
        }

        // Шаг ro
        int x = 1;
        int y = 0;
        int tmp;
        for (int z = 0; z < 64; z++) {
            for (int t = 0; t < 23; t++) {
                S2[x][y][z] = rot(S1, x, y, z, (t+1)*(t+2)/2);
                tmp = x;
                x = y%5;
                y = (2*tmp + 3*y)%5;
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S2[i][j][k];}
            }
        }

        // Шаг pi
        for (int k = 0; k < 64; k++){
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    S2[j][(2*i+4)%5][k] = S1[i][j][k];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S2[i][j][k];}
            }
        }

        // Шаг hi
        for (int k = 0; k < 64; k++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    S2[i][j][k] = xor_bit(S1[i][j][k], char_and(opposite(S1[(i+1)%5][j][k]), S1[(i+2)%5][j][k]));
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S2[i][j][k];}
            }
        }

        // Шаг yota

        // Подготовка результата
        string res;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {res += S1[i][j][k];}
            }
        }
        // Освобождение памяти
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                delete [] S1[i][j];
                delete [] S2[i][j];
            }
            delete [] S1[i];
            delete [] S2[i];
        }
        delete [] S1;
        delete [] S2;

        return res;
    }
}

/**
 * @brief Получение хэш-значения в виде QString.
 * 
 * @return Хэш-значение в виде QString.
 */
QString Hash::get_hash() {
    return value;
}

/**
 * @brief Получение хэш-значения в виде стандартной строки.
 * 
 * @return Хэш-значение в виде стандартной строки.
 */
string Hash::getStdHash() {
    return value.toStdString();
}

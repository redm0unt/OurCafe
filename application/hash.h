#ifndef HASH_H
#define HASH_H

#include <QString>

class Hash {
public:
    static const int b = 1600;     // length of status bar
    static const int r = 1088;     // length of piece
    static const int c = 512;      // length of the adding part
    static const int w = 64;       // length of the "word"
    static const int nr = 24;      // number of iterations

    QString value;

    Hash(std::string pass);

    std::string bin(char c);
    std::string prime_hash(std::string pass);
    std::string pad(std::string line);
    std::string complete_zero(std::string line);
    std::string xor_bit(std::string a, std::string b);
    char xor_bit(char a, char b);
    char rot(char ***s, int x, int y, int z, int d);
    char opposite(char c);
    char char_and(char a, char b);
    std::string permutation(std::string S);
    QString get_hash();
    std::string getStdHash();
};

#endif // HASH_H

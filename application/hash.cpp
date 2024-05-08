#include "hash.h"

using namespace std;


Hash::Hash(string pass) {
    std::string b = permutation(complete_zero(pad(prime_hash(pass))));
    std::string res;
    for (int i = 0; i < 10; i++) {b = permutation(b);}
    for (int i = 0; i < 256; i++) {res += b[i];}
    value = QString::fromStdString(res);
}

string Hash::bin(char c) {
    int num = c;
    string out;
    while (num > 0) {
        out = to_string(num%2) + out;
        num /= 2;
    }
    return out;
}

// creating primary hash
// string will represent binary version of password
string Hash::prime_hash(string pass) {
    string hash;     // actual hash
    for (unsigned long i = 0; i < pass.size(); i++) hash = bin(pass[i]) + hash;
    return hash;
}


// padding function
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

// completing function
string Hash::complete_zero(string line) {
    string part;
    for (int i = 0; i < c; i++) {part += '0';}
    return line + part;
}

// xor for sequences of bits
string Hash::xor_bit(string a, string b) {
    string res;
    for (unsigned long i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i]) {res += '0';}
        else {res += '1';}
    }
    return res;
}

// xor for single bits
char Hash::xor_bit(char a, char b) {
    if (a == b) { return '0'; }
    else { return '1'; }
}

// getting an element that is located at fixed distance from
char Hash::rot(char ***s, int x, int y, int z, int d) {
    int new_z = z + d;
    if (new_z >= 0) { return s[x][y][new_z % w]; }
    return s[x][y][((w - (-new_z)%w) % w)];
}

char Hash::opposite(char c) {
    if (c == '0') { return '1'; }
    return '0';
}

char Hash::char_and(char a, char b){
    if (a == '1' && b == '1') {return '1';}
    else {return '0';}
}

// function to do permutations in status bar
string Hash::permutation(string S) {
    if (S.size() == 1600) {
        int move = 0;
        // initializing temporary 3 dimentional array with zeros
        char ***S2 = new char ** [5];
        for (int i = 0; i < 5; i++) {
            S2[i] = new char * [5];
            for (int j = 0; j < 5; j++) {
                S2[i][j] = new char [64];
                for (int k = 0; k < 64; k++) {S2[i][j][k] = '0';}
            }
        }
        // rewriting status bar into a 3-dimentional array for easier work
        char ***S1 = new char ** [5];
        for (int i = 0; i < 5; i++) {
            S1[i] = new char * [5];
            for (int j = 0; j < 5; j++) {
                S1[i][j] = new char [64];
                for (int k = 0; k < 64; k++) {S1[i][j][k] = S[k + move];}
                move += w;
            }
        }

        // theta step
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

        // ro step
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

        // pi step
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

        // hi step
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

        // yota step

        // preparing the result
        string res;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 64; k++) {res += S1[i][j][k];}
            }
        }
        // clearing the memory
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

QString Hash::get_hash() {
    return value;
}
string Hash::getStdHash() {
    return value.toStdString();
}

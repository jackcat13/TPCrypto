#include <iostream>
#include "Contexte.h"
#include <openssl/md5.h>

using namespace std;

int main() {

    Contexte* contexte = new Contexte((uint64_t) 11881376, 5, 5, (uint64_t[1]) {11881376}, 26,
                            (char[26]) {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
    uint64_t idx = 11844934;
    string *toCrypt = new string[5];
    contexte->i2c(idx, toCrypt);
    cout << toCrypt[0] << toCrypt[1] << toCrypt[2] << toCrypt[3] << toCrypt[4] << endl;

    string toCryptString = "kcyxz";
    unsigned char *crypted = new unsigned char[MD5_DIGEST_LENGTH];
    //Hashage
    contexte->h(toCryptString, crypted);

    //Affichage en entier du hash MD5
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x",crypted[i]);
    } printf("\n");

    cout << contexte->h2i(1, crypted) << endl;

    cout << contexte->i2i(1, idx);
    return 0;
}
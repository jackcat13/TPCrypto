#include <iostream>
using namespace std;
#include <openssl/md5.h>
#include <string.h>
#include "md5.h"

//Fonction de hashage MD5
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    MD5(pPlain, nPlainLen, pHash);
}

/*int main(){

    //Initialisation des variables
    string toCryptString;
    cin >> toCryptString; //Input user
    unsigned char *toCrypt = (unsigned char *) toCryptString.c_str();
    unsigned char *crypted = new unsigned char[MD5_DIGEST_LENGTH];

    //Hashage de l'input utilisateur
    HashMD5(toCrypt, (int) toCryptString.length(), crypted);

    //Affichage en entier du hash MD5
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x",crypted[i]);
    } printf("\n");
    return 0;
}*/

#include <cmath>
#include <iostream>
#include <openssl/md5.h>
#include "Contexte.h"
#include "md5.h"

// fonction de hachage
// In: Clair c ----> Out: Empreinte
void Contexte::h(string c, unsigned char *d) {
    unsigned char *toCrypt = (unsigned char *) c.c_str();
    HashMD5(toCrypt, c.length(), d);
}

// In: position t, empreinte d ---> Retourne index
uint64_t Contexte::h2i(uint64_t t, unsigned char *d) {
    uint64_t *indexOut = (uint64_t*) d;
    return ((uint64_t) indexOut + t) % _N;
}

// In: index idx ----> Out: Clair c
void Contexte::i2c(uint64_t idx, string *c) {

    //Boucle pour calculer le nombre de lettres du mot clair
    int tailleMot = _mot_taille_min;
    for (int i = _mot_taille_min; i < _mot_taille_max; i++){
        if (idx <= std::pow(_nb_lettres, i)){
            tailleMot = i;
        }
    }

    //Boucle pour construire le mot clair
    for (int j = 0; j < tailleMot; j++){
        c[j] = fmod( idx, std::pow(_nb_lettres, (tailleMot-j)) );
    }
}

uint64_t Contexte::i2i(uint64_t t, uint64_t idx) {
    string *s = new string[5];
    this->i2c(idx, s);
    unsigned char *crypted = new unsigned char[MD5_DIGEST_LENGTH];
    this->h(*s, crypted);
    return this->h2i(t, crypted);
}

uint64_t Contexte::randIndex() {
    return 0;
}

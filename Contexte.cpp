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
    int nbOctets = 8;
    uint64_t indexOut = 0;
    for (int i=0; i<nbOctets; i++){
        indexOut += d[i];
    }
    return indexOut + t;
}

// In: index idx ----> Out: Clair c
void Contexte::i2c(uint64_t idx, unsigned char *c) {

}

uint64_t Contexte::i2i(uint64_t idx) {
    return 0;
}

uint64_t Contexte::randIndex() {
    return 0;
}

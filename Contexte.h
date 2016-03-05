#ifndef TP2CRYPTO_CONTEXTE_H
#define TP2CRYPTO_CONTEXTE_H

#include <cstdint>
#include <string>
using namespace std;

class Contexte {

public:
    Contexte(uint64_t _N, int _mot_taille_min, int _mot_taille_max, uint64_t *_N_taille, int _nb_lettres, char *_lettres)
            : _N(_N), _mot_taille_min(_mot_taille_min), _mot_taille_max(_mot_taille_max), _N_taille(_N_taille),
              _nb_lettres(_nb_lettres), _lettres(_lettres) { }

    // fonction de hachage
    // In: Clair c ----> Out: Empreinte
    void h( string c, unsigned char* d );
    // In: position t, empreinte d ---> Retourne index
    uint64_t h2i( uint64_t t, unsigned char* d );
    // In: index idx ----> Out: Clair c
    void i2c( uint64_t idx, unsigned char* c );
    // In: index idx ----> retourne index (la composée des précédentes)
    uint64_t i2i( uint64_t idx );
    // Retourne un indice aléatoire valide.
    uint64_t randIndex();

private:
    uint64_t _N;            // nombre de mots
    int _mot_taille_min;  // nombre de lettres min d'un mot
    int _mot_taille_max;  // nombre de lettres max d'un mot
    uint64_t *_N_taille;   // tableau, nombre de mots d'une taille donnée
    int _nb_lettres;      // nombre de lettres possibles pour un caractère
    char *_lettres;      // tableau des lettres de taille _nb_lettres
};


#endif //TP2CRYPTO_CONTEXTE_H

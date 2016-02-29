#ifndef TP2CRYPTO_ARCENCIEL_H
#define TP2CRYPTO_ARCENCIEL_H

#include <sys/types.h>
#include "Contexte.h"

struct Chaine {
    uint64_t idx1;    // premier indice de la chaine
    uint64_t idxT;    // dernier indice de la chaine
};

class ArcEnCiel {
public:
    ArcEnCiel(uint _numero, uint _M, uint _T, Chaine *_X) : _numero(_numero), _M(_M), _T(_T), _X(_X) { }

private:
    uint _numero;   // numero de la table (ici 0, mais voir "Moult tables")
    uint _M;        // nombre de chaines dans la table
    uint _T;        // taille de chaque chaine
    Chaine* _X;     // la table elle-meme

    // Creer les M chaînes de taille T, dans le contexte ctxt
    void creer( Contexte ctxt, int num, int M, int T );
    // Tri _X suivant idxT.
    void trier();
    // Sauvegarde la table sur disque.
    void save( string name );
    // Charge en mémoire la table à partir du disque.
    void load( string name );
    // Recherche dichotomique dans la table
    // ( p et q sont le premier/dernier trouvé )
    bool recherche( uint64_t idx, uint & p, uint & q );
};

#endif //TP2CRYPTO_ARCENCIEL_H

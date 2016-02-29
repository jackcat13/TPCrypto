#include <openssl/sha.h>

void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
    SHA1(pPlain, nPlainLen, pHash);
}
#ifndef HASH_H
#define HASH_H
#include <stdbool.h>
typedef struct Entree{char *cle;int compteur;struct Entree *suivant;}Entree;
typedef struct{Entree **buckets;int taille;}Hash;
void hash_init(Hash *h,int taille);void hash_incrementer(Hash *h,const char *cle);int hash_rechercher(const Hash *h,const char *cle);void hash_afficher(const Hash *h);void hash_detruire(Hash *h);
#endif

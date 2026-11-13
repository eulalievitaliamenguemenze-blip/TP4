#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
void hash_init(Hash *h,int taille){h->taille=taille;h->buckets=calloc(taille,sizeof(Entree*));}
static unsigned long hf(const char *c,int t){unsigned long h=5381;int ch;while((ch=*c++))h=((h<<5)+h)+ch;return h%t;}
void hash_incrementer(Hash *h,const char *cle){unsigned long idx=hf(cle,h->taille);Entree *e=h->buckets[idx];while(e){if(strcmp(e->cle,cle)==0){e->compteur++;return;}e=e->suivant;}Entree *n=malloc(sizeof(Entree));n->cle=strdup(cle);n->compteur=1;n->suivant=h->buckets[idx];h->buckets[idx]=n;}
int hash_rechercher(const Hash *h,const char *cle){unsigned long idx=hf(cle,h->taille);Entree *e=h->buckets[idx];while(e){if(strcmp(e->cle,cle)==0)return e->compteur;e=e->suivant;}return 0;}
void hash_afficher(const Hash *h){for(int i=0;i<h->taille;i++){Entree *e=h->buckets[i];while(e){printf("%s : %d\n",e->cle,e->compteur);e=e->suivant;}}}
void hash_detruire(Hash *h){for(int i=0;i<h->taille;i++){Entree *e=h->buckets[i];while(e){Entree *t=e;e=e->suivant;free(t->cle);free(t);}}free(h->buckets);h->buckets=NULL;}

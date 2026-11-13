#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
void abr_init(ABR *a){a->racine=NULL;a->taille=0;}
static NoeudABR* creer_noeud(int cle){NoeudABR *n=malloc(sizeof(NoeudABR));n->cle=cle;n->gauche=NULL;n->droite=NULL;return n;}
static NoeudABR* inserer_rec(NoeudABR *r,int cle,bool *aj){if(!r){*aj=true;return creer_noeud(cle);}if(cle<r->cle)r->gauche=inserer_rec(r->gauche,cle,aj);else if(cle>r->cle)r->droite=inserer_rec(r->droite,cle,aj);return r;}
void abr_inserer(ABR *a,int cle){bool aj=false;a->racine=inserer_rec(a->racine,cle,&aj);if(aj)a->taille++;}
bool abr_rechercher(const ABR *a,int cle){NoeudABR *c=a->racine;while(c){if(cle==c->cle)return true;else if(cle<c->cle)c=c->gauche;else c=c->droite;}return false;}
static void infixe_rec(NoeudABR *r){if(!r)return;infixe_rec(r->gauche);printf("%d ",r->cle);infixe_rec(r->droite);}
void abr_infixe(const ABR *a){infixe_rec(a->racine);printf("\n");}
static int hauteur_rec(NoeudABR *r){if(!r)return -1;int hg=hauteur_rec(r->gauche);int hd=hauteur_rec(r->droite);return 1+(hg>hd?hg:hd);}
int abr_hauteur(const ABR *a){return hauteur_rec(a->racine);}
static void detruire_rec(NoeudABR *r){if(!r)return;detruire_rec(r->gauche);detruire_rec(r->droite);free(r);}
void abr_detruire(ABR *a){detruire_rec(a->racine);a->racine=NULL;a->taille=0;}

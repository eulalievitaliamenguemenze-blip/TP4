#ifndef ABR_H
#define ABR_H
#include <stdbool.h>
typedef struct NoeudABR{int cle;struct NoeudABR *gauche,*droite;}NoeudABR;
typedef struct{NoeudABR *racine;int taille;}ABR;
void abr_init(ABR *a);void abr_inserer(ABR *a,int cle);bool abr_rechercher(const ABR *a,int cle);
void abr_infixe(const ABR *a);int abr_hauteur(const ABR *a);void abr_detruire(ABR *a);
#endif

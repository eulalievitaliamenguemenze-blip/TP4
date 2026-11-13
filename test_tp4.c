#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"
#include "hash.h"
int main(){
 ABR a;abr_init(&a);int vals[]={50,30,70,20,40,60,80};for(int i=0;i<7;i++)abr_inserer(&a,vals[i]);
 printf("Infixe : ");abr_infixe(&a);printf("Hauteur %d\n",abr_hauteur(&a));abr_detruire(&a);
 Hash h;hash_init(&h,101);hash_incrementer(&h,"bonjour");hash_incrementer(&h,"bonjour");printf("bonjour=%d\n",hash_rechercher(&h,"bonjour"));hash_detruire(&h);
 ABR a2;abr_init(&a2);Hash h2;hash_init(&h2,10007);srand(42);for(int i=0;i<10000;i++){int v=rand()%100000;abr_inserer(&a2,v);char b[32];snprintf(b,32,"mot%d",v);hash_incrementer(&h2,b);}
 clock_t d=clock();for(int i=0;i<10000;i++)abr_rechercher(&a2,rand()%100000);clock_t f=clock();double ta=(double)(f-d)/CLOCKS_PER_SEC;
 d=clock();for(int i=0;i<10000;i++){char b[32];snprintf(b,32,"mot%d",rand()%100000);hash_rechercher(&h2,b);}f=clock();double th=(double)(f-d)/CLOCKS_PER_SEC;
 printf("ABR 10000: %f s\nHASH 10000: %f s\n",ta,th);
 FILE *csv=fopen("mesures.csv","w");fprintf(csv,"structure,temps\nABR,%f\nHASH,%f\n",ta,th);fclose(csv);
 abr_detruire(&a2);hash_detruire(&h2);printf("TP4 OK\n");return 0;
}

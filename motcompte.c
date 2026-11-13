#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
int main(int argc,char *argv[]){
 const char *fichier=(argc>1)?argv[1]:"texte.txt";
 FILE *f=fopen(fichier,"r");if(!f){perror("fopen");return 1;}
 Hash h;hash_init(&h,101);char mot[256];int total=0;
 while(fscanf(f,"%255s",mot)==1){char propre[256];int j=0;for(int i=0;mot[i];i++)if(isalnum((unsigned char)mot[i]))propre[j++]=tolower((unsigned char)mot[i]);propre[j]='\0';if(j>0){hash_incrementer(&h,propre);total++;}}
 fclose(f);printf("Motcompte %s (%d mots)\n",fichier,total);hash_afficher(&h);hash_detruire(&h);return 0;
}

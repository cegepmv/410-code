#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* p;
    int moitie;
    int taille;
    char* mot1;
    char* mot2;
    char* pm1;
    char* pm2;

    if (argc == 2) {
        p = argv[1];    // Pointeur sur le premier caractère de argv[1]
        taille = strlen(argv[1]);
        moitie = taille / 2;
        mot1 = (char *)malloc(moitie + moitie % 2);
        mot2 = (char *)malloc(moitie);
        pm1 = mot1; // Garder un pointeur au début du mot
        pm2 = mot2; // Garder un pointeur au début du mot

        for (int i=0;i<moitie+1;i++) {
            *mot1 = *p;
            mot1++;
            p++;
        }
        for (int i=0;i<moitie;i++) {
            *mot2 = *p;
            mot2++;
            p++;
        }
    }
    printf("mot 1: %s\nmot 2: %s\n",pm1,pm2);

}

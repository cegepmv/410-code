#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* final;
    char* p;
    int tailleChaine = 0;   // Taille de la chaîne finale
    int tailleMot;

    // Taille de la chaîne finale
    for (int i=1;i<argc;i++) { // Init à 1 car arg[0] est le nom de l'exec
        tailleChaine += strlen(argv[i]);
    }
    final = (char*)malloc(tailleChaine);

    for (int i=1;i<argc;i++) {  // Pour chaque mot
        tailleMot = strlen(argv[i]);
        p = argv[i];
        for (int j=0;j<tailleMot;j++) {  // Pour chaque lettre on la copie dans 'final'
            *final = *p;
            final++;
            p++;
        }

    }
    final = final-tailleChaine;

    printf("Final: %s\n",final);
}
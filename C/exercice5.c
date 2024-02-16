#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_BUF 200

int main() {
    FILE *f;
    char buffer[TAILLE_BUF]; // Taille arbitraire pour stocker chaque ligne
    int compte = 0;

    f = fopen("monFichier.txt", "r"); 
    if (f == NULL) {
        printf("Erreur !!\n");
        fclose(f);
        return 1;
    }

    while (fgets(buffer,TAILLE_BUF,f)) {
        if (strcmp(buffer,"\n") == 0) {
            compte++;
        }
    }
    printf("%i\n",compte);
    fclose(f);

}
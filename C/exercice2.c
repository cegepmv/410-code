#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char* p;
    int compte = 0;
    char c;
    int taille;

    if (argc == 3) {
        c = *argv[2];   // Le premier caractère de argv[2]
        p = argv[1];    // Pointeur sur le premier caractère de argv[1]
        taille = strlen(argv[1]);
        for (int i=0;i<taille;i++) {
            if (*p == c) {
                compte++;
            }
            p++;
        }
    }
    printf("Le caractère apparaît %i fois\n",compte);
}

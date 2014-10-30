#include <stdlib.h>
#include <stdio.h>

// Definition de la taille de la matrice
#define lin 20
#define col 40
// Definition du type matrice de caractere
typedef char matrice[lin][col];

void initMatrice(matrice m) {
    // Creation du tableau des lettres
    char letters[4] = {'S', 'F', 'P', 'O'};
    // On assigne une lettre au hasard pour chaque case de la matrice
    for (int i = 0; i < lin; ++i)
        for (int j = 0; j < col; ++j)
            // On ajoute des lettres aleatoire a la matrice
            m[i][j] = letters[rand() % 4];
}

void showMatrice(matrice m) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j)
            printf("%c ", m[i][j]);
        printf("\n");
    }
}

void applyRules(matrice m) {
    // On parcours la matrice pour y appliquer les regles
}

int main() {
    // Creation de la matrice
    char matrice[lin][col];
    initMatrice(matrice);
    showMatrice(matrice);
    return 0;
}
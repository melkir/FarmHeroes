#include <stdlib.h>
#include <stdio.h>

// Definition de la taille de la matrice
#define lin 20
#define col 40
// Definition du type matrice de caractere
typedef char matrice[lin][col];
// Initialisation des points du joueur
int nbPts = 0;
// Initialisation des vie du joueur
int nbVie = 5;

/** Initialisation de la matrice */
void initMatrice(matrice m) {
    // Creation du tableau des lettres
    char letters[4] = {'S', 'F', 'P', 'O'};
    // On assigne une lettre au hasard pour chaque case de la matrice
    int i, j;
    for (i = 0; i < lin; ++i)
        for (j = 0; j < col; ++j)
            // On ajoute des lettres aleatoire a la matrice
            m[i][j] = letters[rand() % 4];
}

/** Affichage de la matrice */
void showMatrice(matrice m) {
    int i, j;
    for (i = 0; i < lin; ++i) {
        for (j = 0; j < col; ++j)
            printf("%c ", m[i][j]);
        printf("\n");
    }
}

void rules(matrice m, int ligne, int colonne) {
    // Groupe de 3 lettres consecutive sur ligne
    if (*m[ligne] == *m[ligne + 1] == *m[ligne + 2]) {
        // Groupe de 4 lettres consecutive sur ligne
        if (*m[ligne + 2] == *m[ligne + 3]) {
            nbPts += 8;
        } else nbPts += 3;
    }
    // Groupe de 3 lettres consecutive en colonne
    if (*m[colonne] == *m[colonne + 1] == *m[colonne + 2]) {
        // Groupe de 4 lettres consecutive sur colonne
        if (*m[colonne + 2] == *m[ligne + 3]) {
            nbPts += 8;
        } else nbPts += 3;
    }
    //TODO Definir les autres regles
}

// Permutte deux elements de la matrice
void permutte(matrice m, int i1, int j1, int i2, int j2) {
    char temp = m[i1][j1];
    m[i1][j1] = m[i2][j2];
    m[i2][j2] = temp;
    showMatrice(m);
}

void applyRules(matrice m) {
    // On parcours la matrice pour y appliquer les regles
    int i, j;
    for (i = 0; i < lin; ++i) {
        for (j = 0; j < col; ++j) {
            rules(m, i, j);
        }
    }
}

int main() {
    // Creation de la matrice
    char m[lin][col];
    initMatrice(m);
    showMatrice(m);
    printf("Affichage de la nouvelle matrice \n");
    // Permutte l'element {0,0} avec {0,1} de la matrice
    permutte(m, 0, 0, 0, 1);
    return 0;
}
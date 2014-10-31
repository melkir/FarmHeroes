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
// Creation de la matrice
char m[lin][col];

/** Initialisation de la matrice */
void initMatrice() {
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
void showMatrice() {
    int i, j;
    for (i = 0; i < lin; ++i) {
        for (j = 0; j < col; ++j)
            printf("%c ", m[i][j]);
        printf("\n");
    }
}

void rules(int ligne, int colonne) {
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
void permutte(int i1, int j1, int i2, int j2) {
    char temp = m[i1][j1];
    m[i1][j1] = m[i2][j2];
    m[i2][j2] = temp;
    showMatrice();
}

void applyRules() {
    // On parcours la matrice pour y appliquer les regles
    int i, j;
    for (i = 0; i < lin; ++i) {
        for (j = 0; j < col; ++j) {
            rules(i, j);
        }
    }
}

void save() {
    FILE *file;
    file = fopen("/home/melkir/save.txt", "w+"); /* apend file (add text to a file or create a file if it does not exist.*/
    fprintf(file, "%u %u", nbPts, nbVie); /*writes*/
    int i, j = 0;
    for (j = 0; j < col; ++j) {
        for (i = 0; i < lin; ++i) {
            fputc(m[i][j], file);
        }
        fputc('\n', file);
    }
    fclose(file); /*done!*/
}

void load() {
    FILE *file;
    file = fopen("/home/melkir/save.txt", "r");
    /* fopen returns 0, the NULL pointer, on failure */
    if (file == 0) {
        printf("Could not open file\n");
    }
    else {
        int x;
        /* read one character at a time from file, stopping at EOF, which
           indicates the end of the file.  Note that the idiom of "assign
           to a variable, check the value" used below works because
           the assignment statement evaluates to the value assigned. */
        while ((x = fgetc(file)) != EOF) {
            printf("%c", x);
        }
        fclose(file);
    }
}

int main() {
    initMatrice();
    showMatrice();
//    printf("Affichage de la nouvelle matrice \n");
    // Permutte l'element {0,0} avec {0,1} de la matrice
//    permutte(m, 0, 0, 0, 1);
    save();
    load();
    return 0;
}

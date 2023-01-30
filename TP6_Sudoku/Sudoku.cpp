#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

class Sudoku {
    
    vector<vector<int>> board; // tableau bidimensionnel représentant la grille de Sudoku
    int complexity; // 1-5
    int size; // taille des lignes et colonnes

    public:
    // Constructors
    Sudoku();                           // default : size = 9*9, complexity = 1 ; 
    Sudoku(int complexity);             // size = 9*9, complexity = complexity ;
    Sudoku(int size, int complexity);   // size = size X size, complexity = complexity ;

    // Getters
    vector<vector<int>> getBoard();
    int getComplexity();
    int getSize();

    // Setters
    void setBoard(vector<vector<int>> board);
    void setComplexity(int complexity);
    void setSize(int size);

    // Display
    void displayBoard();
    friend ostream& operator<<(ostream& os, Sudoku& sudoku);

    // Methods
    int getCase(int l, int c);              // obtenir la valeur d'une case selon la ligne et la colonne
    void clearBoard();                      // Toutes les cases sont remplies/réinitialisées à 0
    void randomFilling(int complexity);     // pré-remplissage aléatoire de la grille avec des nombres aléatoires
    
    bool isPlayableColumn(int c, int n);    // vérifie si le nombre n peut être placé dans la colonne c
    bool isPlayableLine(int l, int n);      // vérifie si le nombre n peut être placé dans la ligne l
    bool isPlayableSquare(int l, int c, int n); // vérifie si le nombre n peut être placé dans le carré de la case (l,c)
    bool isPlayable(int l, int c, int n); // vérifie si le nombre n peut être placé dans la case (l,c)

    void setCase(int l, int c, int n);      // place le nombre n dans la case (l,c), utiliser pour tester le placement d'un nombre

    bool solveSudoku(Sudoku& sudoku, int c, int l);     // résoud la grille par backtracking
};

// Constructors
Sudoku::Sudoku() {
    this->board = vector<vector<int>>(9, vector<int>(9, 0));
    this->complexity = 1;
    this->size = 9;
    // on ne pré-remplit pas la grille par défaut
};
Sudoku::Sudoku(int complexity) {
    this->board = vector<vector<int>>(9, vector<int>(9, 0));
    this->complexity = complexity;
    this->size = 9;
    this->randomFilling(this->complexity);
    // on pré-remplit la grille selon la difficulté
};
Sudoku::Sudoku(int size, int complexity) {
    this->board = vector<vector<int>>(size, vector<int>(size, 0));
    this->complexity = complexity;
    this->size = size;
    this->randomFilling(this->complexity);
    // on pré-remplit la grille selon la difficulté
};

// Getters
vector<vector<int>> Sudoku::getBoard() {
    return this->board;
};
int Sudoku::getComplexity() {
    return this->complexity;
};
int Sudoku::getSize() {
    return this->size;
};

// Setters
void Sudoku::setBoard(vector<vector<int>> board) {
    this->board = board;
};
void Sudoku::setComplexity(int complexity) {
    this->complexity = complexity;
};
void Sudoku::setSize(int size) {
    this->size = size;
};

// Display
void Sudoku::displayBoard() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << this->board[i][j] << " ";
        };
        cout << endl;
    };
};

ostream& operator<<(ostream& os, Sudoku& sudoku) {
    int nbTrait = sudoku.getSize()+4 + ( (sqrt(sudoku.getSize())-1)*(sqrt(sudoku.getSize())) );

    // Pour chaque ligne
    for (int i = 0; i < sudoku.getSize(); i++) {
        if(i % (int)sqrt(sudoku.getSize()) == 0) {
            for(int i = 0; i < nbTrait ; i++) {
                os << "-" ;
            };
            os << endl;
        };

        // Carré et trait de séparation de la colonne
        for (int j = 0; j < sudoku.getSize(); j++) {
            if( !(j % (int)sqrt(sudoku.getSize()) == 0) ){
                os << " " ;
            };

            if(j % (int)sqrt(sudoku.getSize()) == 0) {
                os << "|" ;
            };
            if(sudoku.getCase(i,j) == 0)
                os << "*";
            else
                os << sudoku.getCase(i,j);
        };
        os << "|" << endl;
    };

    // ligne de séparation du bas
    for(int i = 0; i < nbTrait ; i++) {
        os << "-" ;
    };
    os << endl;

    return os;
};

// Methods
int Sudoku::getCase(int l, int c) {
    return this->board[l][c];
};

void Sudoku::clearBoard() {
    // Toutes les cases sont remplies/réinitialisées à 0
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->board[i][j] = 0;
        };
    };
};

void Sudoku::randomFilling(int complexity){
    int nbToFill;
    int nbOfCells = this->size * this->size;

    // on réinitialise la grille avant de la remplir alétoirement (pour éviter de remplir une grille déjà remplie)
    this->clearBoard();

    // on détermine le nombre de cases à remplir selon la difficulté
    switch (complexity) {
        case 1:
                do{
                    nbToFill = rand() % nbOfCells;
                }while(nbToFill < 40 || nbToFill > nbOfCells);
            break;
        case 2:
                do{
                    nbToFill = rand() % nbOfCells;
                }while((nbToFill < 35) || (nbToFill > 40));
            break;
        case 3:
                do{
                    nbToFill = rand() % nbOfCells;
                }while((nbToFill < 30) || (nbToFill > 35));
            break;
        case 4:
            do{
                    nbToFill = rand() % nbOfCells;
                }while((nbToFill < 25) || (nbToFill > 30));
            break;
        case 5:
            do{
                    nbToFill = rand() % nbOfCells;
                }while((nbToFill < 20) || (nbToFill > 25));
            break;
        default:
            // par défaut : diffculté maximale
            nbToFill = 20;
            break;
    };

    // on remplit aléatoirement la grille en vérifiant que la colonne, la ligne et le carré de la case sont jouables
    // Pour chaque nombre de case à remplir
    int l, c, n;
    for (int i = 0; i < nbToFill; i++) {
        // on  choisit une case aléatoire
        l = rand() % this->size;
        c = rand() % this->size;
        // on choisit un nombre aléatoire
        n = rand() % this->size + 1;
        while (!this->isPlayable(l, c, n)) {
            // tant que le nombre n'est pas jouable, on en choisit un autre
            // on choisit aussi une autre case aléatoire pour éviter de bloquer la grille (boucle infinie)
            // (-> cela a été source de bus jusqu'à ce que je trouve cette solution)
            l = rand() % this->size;
            c = rand() % this->size;
            n = rand() % this->size + 1;
        };
        // Une fois la vérification faite, on place le nombre dans la case
        this->setCase(l, c, n);
    };
};
bool Sudoku::isPlayableColumn(int c, int n) {
    // vérifie si le nombre n peut être placé dans la colonne c
    for (int i = 0; i < this->size; i++) {
        if (this->board[i][c] == n) {
            return false;
        };
    };
    return true;
};
bool Sudoku::isPlayableLine(int l, int n) {
    // vérifie si le nombre n peut être placé dans la ligne l
    for (int i = 0; i < this->size; i++) {
        if (this->board[l][i] == n) {
            return false;
        };
    };
    return true;
};
bool Sudoku::isPlayableSquare(int l, int c, int n) {
    // vérifie si le nombre n peut être placé dans le carré de la case (l,c)
    int squareSize = sqrt(this->size);
    int squareLine = l / squareSize;
    int squareColumn = c / squareSize;

    // Pour chaque case du carré
    for (int i = squareLine * squareSize; i < (squareLine + 1) * squareSize; i++) {
        // Pour chaque case de la ligne
        for (int j = squareColumn * squareSize; j < (squareColumn + 1) * squareSize; j++) {
            if (this->board[i][j] == n) {
                return false;
            };
        };
    };
    return true;
};
bool Sudoku::isPlayable(int l, int c, int n) {
    // vérifie :
    // - si le nombre n peut être placé dans la colonne c avec la méthode isPlayableColumn
    // - si le nombre n peut être placé dans la ligne l avec la méthode isPlayableLine
    // - si le nombre n peut être placé dans le carré de la case (l,c) avec la méthode isPlayableSquare
    return (this->isPlayableColumn(c, n) && this->isPlayableLine(l, n) && this->isPlayableSquare(l, c, n));
};

void Sudoku::setCase(int l, int c, int n) {
    this->board[l][c] = n;
};

bool Sudoku::solveSudoku(Sudoku& sudoku, int c, int l){
    // on commence la récursivité à partir de la case (0,0)
    // et on la poursuit avec la case suivante (c+1, l) ou (0, l+1) si on est arrivé à la fin de la ligne
    // et on continue jusqu'à la dernière case (size-1, size-1)
    // on fait l'équivalent d'une lecture de gauche à droite puis de haut en bas
    // La résolution se termine quand on arrive à la dernière case de la grille

    // si on est arrivé à la fin de la grille, on a résolu le sudoku
    if (l == sudoku.size) {
        return true;
    };

    // si la case est déjà remplie, on passe à la case suivante
    if (sudoku.getCase(l, c) != 0) {
        if (c == sudoku.size - 1) {
            return solveSudoku(sudoku, 0, l + 1);
        } else {
            return solveSudoku(sudoku, c + 1, l);
        };
    };

    // sinon, on essaie de placer un nombre dans la case
    for (int i = 1; i <= sudoku.size; i++) {
        if (sudoku.isPlayable(l, c, i)) {
            sudoku.setCase(l, c, i);
            if (c == sudoku.size - 1) {
                // on recommence pour la ligne suivante (et en repartant à la colonne 0)
                if (solveSudoku(sudoku, 0, l + 1)) {
                    return true;
                };
            } else {
                // on continue de résoudre la ligne jusqu'à la fin (colonne par colonne)
                if (solveSudoku(sudoku, c + 1, l)) {
                    return true;
                };
            };
        };
    };

    // si aucun nombre n'est jouable, on remet la case à 0 et on retourne false
    sudoku.setCase(l, c, 0);
    return false;
}

// La classe sudoku et ses méthodes sont tout de suite créées dans le but de l'adapter à un sudoku de n'importe quelle taille


#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>

// pour la seed du random = srand(...);
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>

#include "Sudoku.cpp"

using namespace std;

void test1(){
    cout << "Test 1 : " << endl;
    Sudoku sudoku1 = Sudoku();
    cout << sudoku1 << endl;
    // surcharge de l'opérateur << pour afficher la grille : OK
    cout << "Test 1.2 " << endl;
    sudoku1.displayBoard();
    // méthode displayBoard() : OK
};

void test2(){
    cout << "Test 2 : " << endl;
    Sudoku sudoku2 = Sudoku();
    cout << "-----------------" << endl;
    cout << sudoku2 << endl;
    cout << "-----------------" << endl;

    bool playable = sudoku2.isPlayable(0,0,1);
    cout << "placer la valeur 1 dans la case (0,0) est possible : " << playable << endl;

    sudoku2.setCase(0,0,1);
    cout << "-----------------" << endl;
    cout << sudoku2 << endl;
    cout << "-----------------" << endl;

    playable = sudoku2.isPlayable(0,0,1);
    cout << "placer la valeur 1 dans la case (0,0) est possible : " << playable << endl;
    
    playable = sudoku2.isPlayable(0,1,1);
    cout << "placer la valeur 1 dans la case (0,1) est possible : " << playable << endl;

    playable = sudoku2.isPlayable(1,0,1);
    cout << "placer la valeur 1 dans la case (1,0) est possible : " << playable << endl;

    playable = sudoku2.isPlayable(1,1,1);
    cout << "placer la valeur 1 dans la case (1,1) est possible : " << playable << endl;

    // La vérification Colonne/Ligne/Carré : OK
};

void test3(){
    // on fera le test sur des sudokus classique de taille 9x9
    // une difficulté 5+ correspond à la difficulté maximale (20 cases pré-remplies)
    Sudoku sudoku3_1 = Sudoku(1);
    Sudoku sudoku3_2 = Sudoku(2);
    Sudoku sudoku3_3 = Sudoku(3);
    Sudoku sudoku3_4 = Sudoku(4);
    Sudoku sudoku3_5 = Sudoku(5);

    cout << "Sudoku complexity : 1 " << endl;
    cout << sudoku3_1 << endl;

    cout << "Sudoku complexity : 2 " << endl;
    cout << sudoku3_2 << endl;

    cout << "Sudoku complexity : 3 " << endl;
    cout << sudoku3_3 << endl;

    cout << "Sudoku complexity : 4 " << endl;
    cout << sudoku3_4 << endl;

    cout << "Sudoku complexity : 5 " << endl;
    cout << sudoku3_5 << endl;

    // La génération de sudoku : OK
}

// tests de la question 4
void test4_1(){
    Sudoku sudoku4_1 = Sudoku(1);
    bool isSolved = false;

    cout << "Sudoku complexity : 1 " << endl;
    cout << sudoku4_1 << endl;

    cout << "resolution du sudoku 1" << endl;
    // on lance la méthode de résolution par la case (0,0)
    isSolved = sudoku4_1.solveSudoku(sudoku4_1, 0, 0);
    cout << sudoku4_1;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };
    cout << endl;
};

void test4_2(){
    Sudoku sudoku4_2 = Sudoku(2);
    bool isSolved = false;

    cout << "Sudoku complexity : 2 " << endl;
    cout << sudoku4_2 << endl;

    cout << "resolution du sudoku 2" << endl;
    isSolved = sudoku4_2.solveSudoku(sudoku4_2, 0, 0);
    cout << sudoku4_2;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };
    cout << endl;
};

void test4_3(){
    Sudoku sudoku4_3 = Sudoku(3);
    bool isSolved = false;

    cout << "Sudoku complexity : 3 " << endl;
    cout << sudoku4_3 << endl;

    cout << "resolution du sudoku 3" << endl;
    isSolved = sudoku4_3.solveSudoku(sudoku4_3, 0, 0);
    cout << sudoku4_3;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };
    cout << endl;
};

void test4_4(){
    Sudoku sudoku4_4 = Sudoku(4);
    bool isSolved = false;

    cout << "Sudoku complexity : 4 " << endl;
    cout << sudoku4_4 << endl;

    cout << "resolution du sudoku 4" << endl;
    isSolved = sudoku4_4.solveSudoku(sudoku4_4, 0, 0);
    cout << sudoku4_4;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };
    cout << endl;
};

void test4_5(){
    Sudoku sudoku4_5 = Sudoku(5);
    bool isSolved = false;

    cout << "Sudoku complexity : 5 " << endl;
    cout << sudoku4_5 << endl;

    cout << "resolution du sudoku 5" << endl;
    isSolved = sudoku4_5.solveSudoku(sudoku4_5, 0, 0);
    cout << sudoku4_5;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };
    cout << endl;
};

void test4(){
    // regroupement en sous-fonctions pour faciliter le travail de correction
    // tester chaque sudoku de difficulté 1 à 5 afin d'éviter les bugs de lancement
    // tests avec des sudokus 9x9
    
    // Avec beaucoup de nombres aléatoires, il est courant que le sudoku ne soit pas résolvable
    test4_1();

    // Un peu plus de chance de résolution
    test4_2();

    // Encore plus de chance de résolution
    test4_3();

    // Encore plus de chance de résolution
    test4_4();

    // Encore plus de chance de résolution
    test4_5();

    // La résolution de sudoku : OK
};

void test5(){
    // tests avec des sudokus de taille size et de difficulté complexity
    int N, size, complexity;
    bool isSolved = false;

    cout << "Entrer la taille N d'un carre du Sudoku (NxN) :" << endl;
    cin >> N;
    size = N*N;
    cout << "Entrer la difficulte du Sudoku : " << endl;
    cin >> complexity;

    // Vaidation de la génération du Sudoku de taille size et de difficulté complexity
    cout << "Sudoku de taille " << size << "x" << size << " et de difficulte " << complexity << endl;
    Sudoku sudoku = Sudoku(size, complexity);
    cout << sudoku << endl;

    // Vaidation de la résolution du Sudoku de taille size et de difficulté complexity
    cout << "resolution du Sudoku de taille " << size << "x" << size << " et de difficulte " << complexity << endl;
    isSolved = sudoku.solveSudoku(sudoku, 0, 0);
    cout << sudoku;

    if(isSolved == true){
        cout << "Le sudoku est resolu : Oui" << endl;
    }else{
        cout << "Le sudoku est resolu : Non" << endl;
    };

    // La génration et la résolution de sudoku avec des tailles et des difficultés variables : OK
};

int main() {

    srand((unsigned)time(NULL));
    
    // test1();

    // test2();

    // test3();

    // test4();

    test5();
    // l'affichage ne fonctionne que pour des sudokus 9x9
    // Pour size > 9, il y a un décalage à cause des dizaines.
    // Cela ne change en rien à la fonctionnalité du programme.

    return 0;
}

// --------------- Remarques ---------------- // :

// Utilisation de programmes test pour tester la classe Sudoku à chaque étape de son développement.
// Il est évident que le temps de résolution pour les grilles très grandes est très long (10-15 secondes pour du 16x16, bien plus pour du 25x25 et +).
// Il est possible de réduire le temps de résolution en utilisant des techniques de programmation avancées (par exemple, en utilisant des threads).
// On utilise directement la méthode de résolution comme méthode de vérification de la validité d'une grille.

// --------------- A améliorer/ A ajouter ---------------- //

// On ne fait pas de simples vérifications si la taille du sudoku est suffisante par rapport aux nombres de pré-remplissage générés aléatoirement
// (on suppose qu'on travaille avec des sudokus de taille 9x9, 16x16, 25x25, etc.).


// --------------- Pistes de continuation --------------- //

// En plaçant un compteur dans la méthode de résolution, on peut "quantifier" l'avancée de la résolution en pourcentage.
// et afficher ce pourcentage durant la résolution afin de suivre son avancement.

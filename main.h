#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void presentation();
int traduction_tableau(int nombre, char tableau[3][3]);
void show_tab(char tableau[3][3]);
void adversaire_joue(char tableau[3][3]);
int check_win(char tableau[3][3]);
int check_draw(char tableau[3][3]);
void lancer_jeu();

#endif // MAIN_H
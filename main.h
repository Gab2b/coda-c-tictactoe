#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void lancer_jeu();           
void show_tab(char tableau[3][3]);
int traduction_tableau(int nombre, char tableau[3][3]);
int check_win(char tableau[3][3]);

#endif // MAIN_H

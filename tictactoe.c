#include "main.h"

int traduction_tableau(int nombre, char tableau[3][3])
{
    if (nombre < 0 || nombre > 8)
    {
        printf("Votre nombre est incorrect. Entrez un chiffre entre 1 et 9.\n");
        return 0;
    }
    else
    {
        if (tableau[nombre / 3][nombre % 3] != ' ')
        {
            printf("Cette case est déjà occupée. Choisissez une autre case.\n");
            return 0;
        }

        else
        {
            tableau[nombre/3][nombre%3] = 'X';
            return 1;
        }
    }   

}

void show_tab(char tableau[3][3])
{
    char *transition = "---|---|---";

    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", tableau[i][0], tableau[i][1], tableau[i][2]);
        if (i!=2)
        {
            printf("\n%s", transition);
        }
        printf("\n");
        
    }

}

void adversaire_joue(char tableau[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (tableau[i][j] == ' ')
            {
                tableau[i][j] = 'O';
                return;
            }
        }
        
    }
    
}

int check_win(char tableau[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (tableau[i][0] == tableau[i][1] && tableau[i][0] == tableau[i][2] && tableau[i][0] != ' ')
        {
            printf("Le joueur %c a gagné sur la ligne %d !\n", tableau[i][0], i + 1);
            return 1;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (tableau[0][j] == tableau[1][j] && tableau[0][j] == tableau[2][j] && tableau[0][j] != ' ')
        {
            printf("Le joueur %c a gagné sur la colonne %d !\n", tableau[0][j], j + 1);
            return 1;
        }
    }

    if (tableau[0][0] == tableau[1][1] && tableau[0][0] == tableau[2][2] && tableau[0][0] != ' ')
    {
        printf("Le joueur %c a gagné sur la première diagonale !\n", tableau[0][0]);
        return 1;
    }

    if (tableau[0][2] == tableau[1][1] && tableau[0][2] == tableau[2][0] && tableau[0][2] != ' ')
    {
        printf("Le joueur %c a gagné sur la seconde diagonale !\n", tableau[0][2]);
        return 1;
    }

    return 0;
}


void lancer_jeu()
{
    char plateau[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int game = 1;
    int choix;

    while (game)
    {
        show_tab(plateau);
        printf("\nVotre choix :\n- ");
        scanf(" %d", &choix);

        if (traduction_tableau(choix, plateau))
        {
            if (check_win(plateau))
            {
                game = 0;
                break;
            }

            adversaire_joue(plateau);

            if (check_win(plateau))
            {
                game = 0;
                break;
            }
        }
        printf("\n\n");
    }
    printf("Vous avez gagné !");
    
}
#include "tic-tac-toe.h"

void presentation()
{
    printf("\n\033[0;33mBienvenue au jeu du TicTacToe\033[0m\n");
    printf("\033[0;33mVous incarnez les Croix, vous pouvez choisir une case à jouer avec leur indice\033[0m \n\n");
    printf(" 0 | 1 | 2 \n---|---|---\n 3 | 4 | 5 \n---|---|---\n 6 | 7 | 8 \n\n");
    printf("\033[0;36mBon jeu !\n\n\033[0m");
    printf("   |   |   \n---|---|---\n   |   |   \n---|---|---\n   |   |   \n\n");
}

int traduction_tableau(int nombre, char tableau[3][3])
{
    if (nombre < 0 || nombre > 8)
    {
        printf("Votre nombre est incorrect. Entrez un chiffre entre 0 et 8.\n");
        return 0;
    }
    else
    {
        if (tableau[nombre / 3][nombre % 3] != ' ')
        {
            printf("\n\033[1;31mCette case est déjà occupée. Choisissez une autre case.\033[0m");
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
    printf("\n\033[0;35mTour de l'adversaire :\n\n\033[0m");
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
            return 1;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (tableau[0][j] == tableau[1][j] && tableau[0][j] == tableau[2][j] && tableau[0][j] != ' ')
        {
            return 1;
        }
    }

    if (tableau[0][0] == tableau[1][1] && tableau[0][0] == tableau[2][2] && tableau[0][0] != ' ')
    {
        return 1;
    }

    if (tableau[0][2] == tableau[1][1] && tableau[0][2] == tableau[2][0] && tableau[0][2] != ' ')
    {
        return 1;
    }

    return 0;
}

int check_draw(char tableau[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tableau[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
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

    presentation();

    while (game)
    {
        printf("Votre choix :\n- ");
        scanf(" %d", &choix);

        if (traduction_tableau(choix, plateau))
        {
            printf("\n");
            show_tab(plateau);

            if (check_win(plateau))
            {
                game=0;
                printf("\n\033[0;32m★★ - Bien joué vous avez gagné !- ★★\033[0m\n\n");
                break;
            }

            adversaire_joue(plateau);

            show_tab(plateau);

            if (check_win(plateau))
            {
                game=0;
                printf("\n\033[0;31mL'adversaire a gagné !\033[0m\n\n");
                break;
            }
            
            else if (check_draw(plateau))
            {
                game=0;
                printf("\n- Malheureusement c'est une égalité ! -\n\n");
                break;
            }
            
        }
        printf("\n\n");
    }

}
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void plateaux(char tableau[largeur][longueur]) {
    for (int i = 0; i < largeur + 2; i++) {
        for (int j = 0; j < longueur + 2; j++) {
            if (i == 0 || i == largeur + 1 || j == 0 || j == longueur + 1) {
                printf("#");
            } else {
                printf("%c", tableau[i - 1][j - 1] ? tableau[i - 1][j - 1] : ' ');
            }
        }
        printf("\n");
    }
}

void mouvement(char tableau[largeur][longueur]) {
    srand(time(NULL));

    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < longueur; j++) {
            tableau[i][j] = ' ';
        }
    }


    char joueur = 'X';
    char boite = 'O';
    char fin = '.';
    int joueur_a = (rand() % largeur);
    int joueur_b = (rand() % longueur);
    
    printf("Coordonnées générées pour le joueur : %d et %d\n", joueur_a, joueur_b);
    tableau[joueur_a][joueur_b] = joueur;

    int boite_c, boite_d;
    do {
        boite_c = (rand() % (largeur - 2)) + 1;
        boite_d = (rand() % (longueur - 2)) + 1;
    } while ((boite_c == joueur_a && boite_d == joueur_b));
    
    printf("Coordonnées générées pour la boîte : %d et %d\n", boite_c, boite_d);
    tableau[boite_c][boite_d] = boite;

    int fin_e, fin_f;
    do {
        fin_e = (rand() % (largeur - 2)) + 1;
        fin_f = (rand() % (longueur - 2)) + 1;
    } while ((fin_e == joueur_a && fin_f == joueur_b) || (fin_e == boite_c && fin_f == boite_d));
    
    tableau[fin_e][fin_f] = fin;
    plateaux(tableau);
    printf("Les déplacements se font avec les touches z (haut), q (gauche), s (bas), d (droite) .\n");

    while (true) {
        char touches;
        scanf(" %c", &touches);

        if ((touches == 'z' || touches == 'Z') && joueur_a > 0) {
            tableau[joueur_a][joueur_b] = ' ';
            joueur_a--;
            if (joueur_a == boite_c && joueur_b == boite_d) {
                tableau[boite_c][boite_d] = ' ';
                boite_c--;
                
                if (boite_c == 0) {
                    printf("vous avez perdus\n");
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    break;
                } else if (boite_c == fin_e && boite_d == fin_f) {
                    tableau[fin_e][fin_f] = ' ';
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    printf("vous avez gagner\n");
                    break;   
                }
            }
            tableau[joueur_a][joueur_b] = joueur;
            tableau[boite_c][boite_d] = boite;
            plateaux(tableau);
            printf("Coordonnées joueur : %d et %d\n", joueur_a, joueur_b);
        } else if ((touches == 's' || touches == 'S') && joueur_a < largeur - 1) {
            tableau[joueur_a][joueur_b] = ' ';
            joueur_a++;
            if (joueur_a == boite_c && joueur_b == boite_d) {
                tableau[boite_c][boite_d] = ' ';
                boite_c++;
                
                if (boite_c == largeur - 1) {
                    printf("vous avez perdus\n");
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    break;
                } else if (boite_c == fin_e && boite_d == fin_f) {
                    tableau[fin_e][fin_f] = ' ';
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    printf("vous avez gagner\n");
                    break;   
                }
            }
            tableau[joueur_a][joueur_b] = joueur;
            tableau[boite_c][boite_d] = boite;
            plateaux(tableau);
            printf("Coordonnées joueur : %d et %d\n", joueur_a, joueur_b);  
            printf("Coordonnées de la boite : %d et %d\n", boite_c, boite_d);
        } else if ((touches == 'q' || touches == 'Q') && joueur_b > 0) {
            tableau[joueur_a][joueur_b] = ' ';
            joueur_b--;
            if (joueur_a == boite_c && joueur_b == boite_d) {
                tableau[boite_c][boite_d] = ' ';
                boite_d--;
                
                if (boite_d == 0) {
                    printf("vous avez perdus\n");
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    break;
                } else if (boite_c == fin_e && boite_d == fin_f) {
                    tableau[fin_e][fin_f] = ' ';
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    printf("vous avez gagner\n");
                    break;   
                }
            }
            tableau[joueur_a][joueur_b] = joueur;
            tableau[boite_c][boite_d] = boite;
            plateaux(tableau);
            printf("Coordonnées joueur : %d et %d\n", joueur_a, joueur_b); 
            printf("Coordonnées de la boite : %d et %d\n", boite_c, boite_d);
        } else if ((touches == 'd' || touches == 'D') && joueur_b < longueur - 1) {
            tableau[joueur_a][joueur_b] = ' ';
            joueur_b++;
            if (joueur_a == boite_c && joueur_b == boite_d) {
                tableau[boite_c][boite_d] = ' ';
                boite_d++;
                
                if (boite_d == longueur - 1) {
                    printf("vous avez perdus\n");
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    break;
                } else if (boite_c == fin_e && boite_d == fin_f) {
                    tableau[fin_e][fin_f] = ' ';
                    tableau[joueur_a][joueur_b] = joueur;
                    tableau[boite_c][boite_d] = boite;
                    plateaux(tableau);
                    printf("vous avez gagner\n");
                    break;   
                }
            }
            tableau[joueur_a][joueur_b] = joueur;
            tableau[boite_c][boite_d] = boite;
            plateaux(tableau);
            printf("Coordonnées joueur : %d et %d\n", joueur_a, joueur_b);
            printf("Coordonnées de la boite : %d et %d\n", boite_c, boite_d);
        } else {
            printf("Vous ne pouvez pas dépasser les limites.\n");
            printf("Choisissez un autre mouvement entre z,q,s,d.\n");
            continue;
        }
    }
}
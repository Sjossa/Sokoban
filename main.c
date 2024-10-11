#include "header.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int largeur;
int longueur;

int main() {
    printf("Bienvenue dans ma version du Sokoban\n");

    
    while (true) {
        printf("Veuillez choisir la largeur du plateau entre 5 et 20 :\n");
        scanf("%d", &largeur);
        if (largeur >= 5 && largeur <= 20) {
            break;
        } else {
            printf("Erreur : la largeur doit être entre 5 et 20.\n");
        }
    }

    
    while (true) {
        printf("Maintenant, entrez la longueur :\n");
        scanf("%d", &longueur);
        if (longueur >= 5 && longueur <= 20) {
            break;
        } else {
            printf("Erreur : la longueur doit être entre 5 et 20.\n");
        }}
    
    plateaux();
    mouvement();
    return 0;
}
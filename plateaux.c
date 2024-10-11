#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void plateaux() {
    char tableau[largeur][longueur];
    int espace = longueur; 

    
    for (int i = 0; i < largeur; i++) {
        printf("#"); 

        
        if (i == 0 || i == largeur - 1) {
            for (int j = 0; j < espace; j++) {
                printf("#");
            }
        } else {
            for (int j = 0; j < espace; j++) {
                printf(" ");
            }
        }
        
        printf("#\n");
    }
}


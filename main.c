#include <stdio.h>
#include "methodes_puissances.h"


int main()
{
	/*
    MATRICE_CARREE mat = NULL;

    printf("Veuillez entrer la taille de la matrice: ");
    scanf("%d",mat.taille);

    mat = allouer_matrice_carree(taille);
    remplir_matrice(mat);
    afficher_matrice(mat);
    desallouer_matrice_carree(mat);*/

	printf("Résultat du test de la fonction multiplier matxvect = %d", tester_fct_multiplier_mat_vect());

	return 0;
}

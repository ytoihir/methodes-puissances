#ifndef METHODES_PUISSANCES_PARALLELE_H
#define METHODES_PUISSANCES_PARALLELE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

typedef struct MATRICE_CARREE
{
	int taille;
	float** tab_mat;
}MATRICE_CARREE;

typedef struct VECTEUR
{
	int taille;
	float* tab_vect;
}VECTEUR;

typedef struct COUPLE_VECT_VAL
{
	VECTEUR vect;
	float val_propre;
}COUPLE_VECT_VAL;


MATRICE_CARREE allouer_matrice_carree_parallele(int taille);
MATRICE_CARREE remplir_matrice_parallele(MATRICE_CARREE mat);
VECTEUR remplir_vecteur_parallele(VECTEUR vect);
void afficher_matrice_parallele(MATRICE_CARREE mat);
void afficher_vecteur_parallele(VECTEUR vect);
void desallouer_matrice_carree_parallele(MATRICE_CARREE mat);
VECTEUR multiplier_mat_vect_parallele(MATRICE_CARREE mat, VECTEUR vect);
float calculer_val_max_composante_parallele(VECTEUR vect);
VECTEUR multiplier_vect_scal_parallele(VECTEUR vect, float scalaire);
float methodes_puissances_parallele(MATRICE_CARREE mat, VECTEUR vect, int n);
bool verif_convergence_parallele();
bool tester_fct_verif_convergence_parallele();
bool tester_fct_calculer_val_max_parallele();
bool tester_fct_multiplier_mat_vect_parallele();
bool tester_fct_multiplier_vect_scal_parallele();
bool tester_fct_methodes_puissances_parallele();

#endif

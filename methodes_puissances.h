#ifndef METHODES_PUISSANCES_H
#define METHODES_PUISSANCES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int NB_THREADS;

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


MATRICE_CARREE allouer_matrice_carree(int taille);
MATRICE_CARREE remplir_matrice(MATRICE_CARREE mat);
VECTEUR remplir_vecteur(VECTEUR vect);
void afficher_matrice(MATRICE_CARREE mat);
void afficher_vecteur(VECTEUR vect);
void desallouer_matrice_carree(MATRICE_CARREE mat);
VECTEUR multiplier_mat_vect(MATRICE_CARREE mat, VECTEUR vect);
float calculer_val_max_composante(VECTEUR vect);
VECTEUR multiplier_vect_scal(VECTEUR vect, float scalaire);
float methodes_puissances(MATRICE_CARREE mat, VECTEUR vect, int n);
bool verif_convergence();
bool tester_fct_verif_convergence();
bool tester_fct_calculer_val_max();
bool tester_fct_multiplier_mat_vect();
bool tester_fct_multiplier_vect_scal();
bool tester_fct_methodes_puissances();

#endif

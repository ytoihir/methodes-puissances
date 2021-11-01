#ifndef METHODES_PUISSANCES_H
#define METHODES_PUISSANCES_H

typedef struct MATRICE_CARREE
{
	int taille;
	float** tab_mat;
}MATRICE_CARREE;


typedef struct VECTEUR 
{
	int taille;
	float* vect;
}VECTEUR;

typedef struct COUPLE_VECT_VAL
{
	VECTEUR vect;
	float val_propre;
}COUPLE_VECT_VAL;

MATRICE_CARREE allouer_matrice_carree(int taille);
void remplir_matrice(MATRICE_CARREE mat);
void afficher_matrice(MATRICE_CARREE mat);
void desallouer_matrice_carree(MATRICE_CARREE mat);
VECTEUR multiplier_mat_vect(MATRICE_CARREE mat);

#endif
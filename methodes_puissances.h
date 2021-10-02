#ifndef METHODES_PUISSANCES_H
#define METHODES_PUISSANCES_H



typedef struct MATRICE_CARREE
{
	int taille;
	int** mat[taille][taille];
}MATRICE_CARREE;


typedef struct VECTEUR 
{
	MATRICE_CARREE* mat;
	int* vect[mat.taille];
	
}

MATRICE_CARREE** allouer_matrice_carree(int taille);
void remplir_matrice(MATRICE_CARREE** mat);
void afficher_matrice(MATRICE_CARREE** mat);
void desallouer_matrice_carree(MATRICE_CARREE** * mat);

#endif

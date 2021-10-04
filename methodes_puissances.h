#ifndef METHODES_PUISSANCES_H
#define METHODES_PUISSANCES_H

typedef struct MATRICE_CARREE
{
	int taille;
	float** mat;
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

typedef struct thread_info
{
	VECTEUR vect;
	MATRICE_CARREE matrice;
}thread_info;

MATRICE_CARREE** allouer_matrice_carree(int taille);
void remplir_matrice(MATRICE_CARREE** mat);
void afficher_matrice(MATRICE_CARREE** mat);
void desallouer_matrice_carree(MATRICE_CARREE** * mat);
void createThreads(MATRICE_CARREE* matrice, VECTEUR* v);
void* thread_start(void *args);
void calculMax(thread_info* thread_info_args);

#endif

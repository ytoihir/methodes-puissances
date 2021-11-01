#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>		
#include <time.h>	
#include <string.h>		
#include <unistd.h>		
#include <semaphore.h>
#include "stat.h"
#include "methodes_puissances.h"

#define NB_THREADS 0

/******************************************
 *  VARIABLES PARTAGEES ENTRE LES THREADS
 * ****************************************/

COUPLE_VECT_VAL* donneesVectVal; //Données contenant le couple valeur propre vecteur

/************************
 *  FONCTION PRINCIPALE
 * **********************/

MATRICE_CARREE** allouer_matrice_carree(int taille) 
{
	MATRICE_CARREE** mat = NULL;
	int i=0;
	
	mat =(MATRICE_CARREE**)malloc(taille*sizeof(int));
    for(i=0; i<taille; i++) 
    {
        mat[i] = (MATRICE_CARREE*)malloc(taille*sizeof(int));
    }

    return mat;
}

void remplir_matrice(MATRICE_CARREE** mat)
{
    int i=0, j=0;
    
    for(i=0; i<mat.taille; i++) 
    {
        for(j=0; j<mat.taille; j++) 
        {
            mat[i][j] = i+j;
        }
    }
    return;
}

void afficher_matrice(MATRICE_CARREE** mat) 
{
	int i=0, j=0;
    for(i=0; i<mat.taille; i++) 
    {
        for(j=0; j<mat.taille; j++) 
        {
            printf("mat[%d][%d] = %d\n",i,j, mat[i][j]);
        }
    }
    return;
}

void desallouer_matrice_carree(MATRICE_CARREE** * mat)
{
	for(int i=0; i<mat.taille; i++) {
        free((*mat)[i]);
    }
    free(*mat);
	*mat = NULL;
	return;
}
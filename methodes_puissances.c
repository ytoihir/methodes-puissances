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
 *  Fonction permettant de calculer la plus grande composante 
 * **********************/

float calculer_val_max_composante(VECTEUR vect) 
{
    int i;
    float valMax=NULL;
    if (vect.taille>0) valMax=vect.tab_vect[0];

    for (i=1; i<vect.taille; i++) 
    {
        if (vect.tab_vect[i]>valMax)
            valMax = vect.tab_vect[i]
    }

    return valMax;
}

/************************
 *  Fonction permettant de calculer le produit entre une matrice et un vecteur
 * **********************/

VECTEUR multiplier_mat_vect(MATRICE_CARREE mat, VECTEUR vect) 
{
    VECTEUR vectRes;
    vectRes = (float*)malloc(taille*sizeof(float));
    int i, j, resColonne;

    for (i=0; i<mat.taille; i++) 
    {
        resColonne = 0;
        for (j=0; j<mat.taille; j++) 
        {
            resColonne += mat.tab_mat[i][j]*vect.tab_vect[j];
        }
        vectRes[i]=resColonne;
    }

    return vectRes;
}

/************************
 *  Fonction permettant d'allouer l'espace mémoire d'une matrice carrée
 * **********************/

MATRICE_CARREE allouer_matrice_carree(int taille) 
{
	MATRICE_CARREE mat = NULL;
	int i;
	
	mat.taille = taille;
	mat.tab_mat =(float**)malloc(taille*sizeof(float));
    for(i=0; i<taille; i++) 
    {
        mat.tab_mat[i] = (float*)malloc(taille*sizeof(float));
    }

    return mat;
}

/************************
 *  Fonction permettant de remplir une matrice
 * **********************/

void remplir_matrice(MATRICE_CARREE mat)
{
    int i, j;
    
    for(i=0; i<mat.taille; i++) 
    {
        for(j=0; j<mat.taille; j++) 
        {
            mat.tab_mat[i][j] = i+j;
        }
    }
    return;
}

/************************
 *  Fonction permettant d'afficher une matrice
 * **********************/

void afficher_matrice(MATRICE_CARREE mat) 
{
	int i=0, j=0;
    for(i=0; i<mat.taille; i++) 
    {
        for(j=0; j<mat.taille; j++) 
        {
            printf("mat.tab_mat[%d][%d] = %d\n",i,j, mat.tab_mat[i][j]);
        }
    }
    return;
}

/************************
 *  Fonction permettant de désaouller l'espace mémoire d'une matrice carrée
 * **********************/

void desallouer_matrice_carree(MATRICE_CARREE mat)
{
	for(int i=0; i<mat.taille; i++) {
        free(mat.tab_mat[i]);
    }
    free(mat);
	return;
}

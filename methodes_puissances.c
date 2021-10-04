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

COUPLE_VECT_VAL* donneesVectVal; // Données contenant le couple valeur propre vecteur
int T_donneesVectVal=0; // Taille du pointeur donneesVectVal

int tete_ecriture=0; 
sem_t cases_occ, cases_lib; //nombre de cases occupées et nbr de cases libres

/************************
 *  FONCTION PRINCIPALE
 * **********************/

void createThreads(MATRICE_CARREE* matrice, VECTEUR* v) {
	NB_THREADS = matrice->taille;
	pthread_t thread[NB_THREADS];
	
	sem_init(&cases_occ,0,0);
	sem_init(&cases_lib,0,T_donneesVectVal);

	int i;
	
	thread_info* args = (thread_info *) malloc (sizeof(thread_info));
	args->vect = v;
	args->matrice = matrice;

	// On crée les threads
	for(i=0;i<NB_THREADS;i++)
		pthread_create(&thread[i],NULL,thread_start,args);
	
	// On attend que les threads se finissent
	for(i=0;i<NB_THREADS;i++)
		pthread_join(thread[i],NULL);
				
	free(args);
		
	printf("\n");
}

void* thread_start(void *args)
{
	thread_info *thread_info_args = args;
	
	sem_wait(&cases_lib);

	calculMax(thread_info_args);

	sem_post(&cases_occ);

	printf("**Thread n%d a fini de calculer...**\n", info_args->numModule);
	
	return NULL;
}

void calculMax(thread_info* thread_info_args) 
{
	
}

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

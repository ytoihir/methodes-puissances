#include "methodes_puissances.h"

int NB_THREADS = 1;

void menu()
{
    MATRICE_CARREE mat;
	VECTEUR vect;
	int option, option2;
	do
	{
		printf("MENU :\n");
		printf("1) Affecter une taille à une matrice\n");
		printf("2) Affecter une taille à un vecteur\n");
		printf("3) Sortir\n");

		printf("Choissisez une option : ");
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				printf("Donnez une taille à la matrice : ");
				scanf("%d", &mat.taille);
				printf("1) Remplir la matrice manuellement\n");
				printf("2) Remplir la matrice aléatoirement\n");
				printf("Appuyez sur n'importe quelle touche pour retourner à l'étape précédente\n");
				printf("Choissisez une option : ");
				scanf("%d", &option2);
				switch(option2)
				{
					case 1:
    					mat = allouer_matrice_carree(mat.taille);
    					remplir_matrice(mat);
    					afficher_matrice(mat);
    					break;

					case 2:
						printf("MatrixMarket\n");
						break;

					default:
						printf("Retour au menu\n");
						break;
				}
				break;

			case 2:
				do
				{
					printf("Donnez une taille au vecteur (TAPEZ -1 POUR RETOURNER AU MENU) : ");
					scanf("%d", &vect.taille);
				} while (vect.taille != mat.taille && vect.taille != -1);

				if (vect.taille != -1)
				{
					printf("1) Remplir le vecteur manuellement\n");
					printf("2) Remplir le vecteur à l'aide de MatrixMarket\n");
					printf("Appuyez sur n'importe quelle touche pour retourner à l'étape précédente\n");
					printf("Choissisez une option : ");
					scanf("%d", &option2);
					switch(option2)
					{
						case 1:
							vect.tab_vect = (float*)malloc(vect.taille*sizeof(float));
    						remplir_vecteur(vect);
    						afficher_vecteur(vect);
    						break;

    					case 2:
    						printf("MatrixMarket\n");
    						break;

    					default:
							printf("Retour au menu\n");
							break;
					}
				}
				break;
		}

	} while(option!=3);

}

/********************************************************
 *  Fonction permettant de mesurer la performance
 * @param res : le resultat de la fct methodes_puissances
 * *****************************************************/

void plot_graphe(float res)
{
	int i = 0;
	double tim[40];
	clock_t start, end;
	
	while (i < 40)
	{
		start = clock();
		end = clock();
			
		tim[i] = ((double)(end-start));
		printf("%li, %li, %lf\n", (long int)NB_THREADS, (long int)tim, (float)res);
		
		NB_THREADS += 100;
		i++;
	}	
}

int main()
{
	
	MATRICE_CARREE mat;
    VECTEUR vect;
    float res;


    mat = allouer_matrice_carree(3);
    mat.tab_mat[0][0]=10;
    mat.tab_mat[0][1]=0;
    mat.tab_mat[0][2]=0;

    mat.tab_mat[1][0]=1;
    mat.tab_mat[1][1]=-3;
    mat.tab_mat[1][2]=-7;

    mat.tab_mat[2][0]=0;
    mat.tab_mat[2][1]=2;
    mat.tab_mat[2][2]=6;

    vect.taille = 3;
    vect.tab_vect = (float*)malloc(vect.taille*sizeof(float));
    vect.tab_vect[0]=1;
    vect.tab_vect[1]=0;
    vect.tab_vect[2]=0;
    
    res = methodes_puissances(mat, vect, 3);
    
    plot_graphe(res);

	
	/*
	printf("Test de la fonction multiplier matxvect = %d\n", tester_fct_multiplier_mat_vect());
    printf("Test de la fonction composante max = %d\n", tester_fct_calculer_val_max());
    printf("Test de la fonction multipler vectxscalaire = %d\n", tester_fct_multiplier_vect_scal());
    printf("Test de la fonction méthodes des puissances = %d\n", tester_fct_methodes_puissances());
	*/
	return 0;

}

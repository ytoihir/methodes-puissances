#include "methodes_puissances.h"

long int NB_THREADS = 2;

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

/*******************************************************
 *  Fonction permettant de mesurer la performance
 * @param es : le resultat de la fct methodes_puissances
 * ****************************************************/

void plot_graphe(float res)
{
	int i = 0;
	double tim[40];
	clock_t start, end;
	
	while (i < 40)
	{
		start = clock();
		float res = res
		end = clock();
			
		tim[i] = ((double)(end-start));
		printf("%li, %li, %li", (long int)NB_THREADS, (long int)tim, (long int)res);
		
		NB_THREADS += 100;
	}	
}

int main()
{

	printf("Test de la fonction multiplier matxvect = %d\n", tester_fct_multiplier_mat_vect());
    printf("Test de la fonction composante max = %d\n", tester_fct_calculer_val_max());
    printf("Test de la fonction multipler vectxscalaire = %d\n", tester_fct_multiplier_vect_scal());
    printf("Test de la fonction méthodes des puissances = %d\n", tester_fct_methodes_puissances());

	return 0;

}

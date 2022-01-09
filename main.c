#include "GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.h"


/*********************************************************
 *  Fonction permettant d'afficher un menu dans la console
 * ******************************************************/
void menu(MATRICE_CARREE mat, VECTEUR vect)
{

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
						mat = allouer_matrice_carree(mat.taille);
						generer_matrice_aleatoire(mat);
						afficher_matrice(mat);
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
					printf("2) Remplir le vecteur aléatoirement\n");
					printf("Appuyez sur n'importe quelle touche pour retourner à l'étape précédente\n");
					printf("Choissisez une option : ");
					scanf("%d", &option2);
					switch(option2)
					{
						case 1:
							vect = allouer_vecteur(vect.taille);
    						remplir_vecteur(vect);
    						afficher_vecteur(vect);
    						break;

    					case 2:
							vect = allouer_vecteur(vect.taille);
    						generer_vecteur_aleatoire(vect);
    						afficher_vecteur(vect);
    						break;

    					default:
							printf("Retour au menu\n");
							break;
					}
				}
				break;
				
				
			case 3:
				break;
		}

	} while(option!=3);

}

/********************************************************
 *  Fonction permettant de mesurer la performance
 * @param res : le resultat de la fct methodes_puissances
 * *****************************************************/
void plot_graphe(MATRICE_CARREE mat, VECTEUR vect)
{
	NB_THREADS = 1;
	float res;
	int i;
	double tim, start, end;
	
	i = 0;
	while (i < 50)
	{
		start = omp_get_wtime();	
		res = methodes_puissances(mat, vect, mat.taille);
    	end = omp_get_wtime();
		
		tim = (end-start);
		printf("%li, %f, %lf\n", (long int)NB_THREADS, tim, res);
		
		NB_THREADS += 1;
		i++;
	}	
}

int main()
{

	MATRICE_CARREE mat;
    VECTEUR vect;
    float valeur_propre = 0;
	

	NB_THREADS = 1;
	
	/*afficher le menu*/
	menu(mat, vect);
	
	valeur_propre = methodes_puissances(mat, vect, mat.taille);
	printf("La valeur propre est: %f\n", valeur_propre);

	//plot_graphe(mat, vect);
	
	//Tests
	/*
	printf("Test de la fonction multiplier matxvect = %d\n", tester_fct_multiplier_mat_vect());
    printf("Test de la fonction composante max = %d\n", tester_fct_calculer_val_max());
    printf("Test de la fonction multipler vectxscalaire = %d\n", tester_fct_multiplier_vect_scal());
    printf("Test de la fonction méthodes des puissances = %d\n", tester_fct_methodes_puissances());
	*/
	
	desallouer_matrice_carree(mat);
	desallouer_vecteur(vect);

	return 0;

}

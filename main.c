#include <stdio.h>
#include "methodes_puissances_parallele.h"

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
				printf("2) Remplir la matrice à l'aide de MatrixMarket\n");
				printf("Appuyez sur n'importe quelle touche pour retourner à l'étape précédente\n");
				printf("Choissisez une option : ");
				scanf("%d", &option2);
				switch(option2)
				{
					case 1:
    					mat = allouer_matrice_carree_parallele(mat.taille);
    					remplir_matrice_parallele(mat);
    					afficher_matrice_parallele(mat);
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
    						remplir_vecteur_parallele(vect);
    						afficher_vecteur_parallele(vect);
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

int main()
{
    /*FILE *f;
	int M, N, nz;
	MM_typecode matcode;
	int ret_code;
	int i, *I, *J;
    double *val;
    FILE * fp;

    menu();

	fp = fopen ("file.txt", "w+");
	
    MATRICE_CARREE mat = NULL;

    printf("Veuillez entrer la taille de la matrice: ");
    scanf("%d",mat.taille);

    mat = allouer_matrice_carree(taille);
    remplir_matrice(mat);
    afficher_matrice(mat);
    desallouer_matrice_carree(mat);
   if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [martix-market-filename]\n", argv[0]);
		exit(1);
	}
    else
    {
        if ((f = fopen(argv[1], "r")) == NULL)
            exit(1);
    }

    if (mm_read_banner(f, &matcode) != 0)
    {
        printf("Could not process Matrix Market banner.\n");
        exit(1);
    }


    // This is how one can screen matrix types if their application 
    //  only supports a subset of the Matrix Market data types.      

    if (mm_is_complex(matcode) && mm_is_matrix(matcode) &&
            mm_is_sparse(matcode) )
    {
        printf("Sorry, this application does not support ");
        printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
        exit(1);
    }

    // find out size of sparse matrix ....

    if ((ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz)) !=0)
        exit(1);


    // reserve memory for matrices

    I = (int *) malloc(nz * sizeof(int));
    J = (int *) malloc(nz * sizeof(int));
    val = (double *) malloc(nz * sizeof(double));


    // NOTE: when reading in doubles, ANSI C requires the use of the "l"  
    //   specifier as in "%lg", "%lf", "%le", otherwise errors will occur 
    //  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            

    for (i=0; i<nz; i++)
    {
        fscanf(f, "%d %d %lg\n", &I[i], &J[i], &val[i]);
        fprintf(fp, "%d %d %lg\n", I[i], J[i], val[i]);
        //fprintf(f, "%d %d %lg\n", &I[i], &J[i], &val[i]);
        I[i]--;  // adjust from 1-based to 0-based
        J[i]--;
    }


    for (i=0; i<nz; i++)
    {
        printf("mat[%d][%d]: %lg\n", I[i], J[i], val[i]);
    }



    if (f !=stdin) fclose(f);
    fclose(fp);*/
 

	printf("Test de la fonction multiplier matxvect = %d\n", tester_fct_multiplier_mat_vect_parallele());
    printf("Test de la fonction composante max = %d\n", tester_fct_calculer_val_max_parallele());
    printf("Test de la fonction multipler vectxscalaire = %d\n", tester_fct_multiplier_vect_scal_parallele());
    printf("Test de la fonction méthodes des puissances = %d\n", tester_fct_methodes_puissances_parallele());

	return 0;




}

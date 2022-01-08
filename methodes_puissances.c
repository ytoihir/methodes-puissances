#include "methodes_puissances.h"

/***********************************************************************
 *
 *                          LA PARTIE UTILITAIRE
 *
 * ********************************************************************/

/*****************************************************
 *  Fonction permettant de générer un nombre aléatoire
 * **************************************************/
 
float generer_nombre_aleatoire()
{
	// nombre aléatoire généré
	float nbr;
	
	srand(time(NULL));
	nbr = rand() % 400 + 1;
	
	return nbr;
	 
}

/***********************************************
 *  Fonction permettant de normaliser un vecteur
 * @param vecteur: vecteur à normaliser
 * *********************************************/

 float normaliser_vecteur(VECTEUR vect)
 {
	float somme;
    somme = 0;
	int i;
	 
    if (vect.tab_vect == NULL)
	{
	    exit(EXIT_FAILURE);
	}	

	#pragma omp shared(somme) for reduction(+: somme)
	for(i = 0; i < vect.taille; i++)
	{
		somme = somme + (vect.tab_vect[i] * vect.tab_vect[i]);
	}
	 
	return sqrt(somme);
 }
 
/**********************************************************************
 *  Fonction permettant d'allouer l'espace mémoire d'une matrice carrée
 * @param taille : la taille de la matrice à allouer
 * *******************************************************************/

MATRICE_CARREE allouer_matrice_carree(int taille)
{
	MATRICE_CARREE mat;
	int i;

	mat.taille = taille;
	mat.tab_mat =(float**)malloc(taille*sizeof(float));
	
	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	#pragma omp parallel for
    for(i=0; i<taille; i++)
    {
        mat.tab_mat[i] = (float*)malloc(taille*sizeof(float));
    }

    return mat;
}

/*********************************************
 *  Fonction permettant de remplir une matrice 
 * ******************************************/

MATRICE_CARREE remplir_matrice(MATRICE_CARREE mat)
{
    int i, j;
    float nbr;
    
    if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
        for(j=0; j<mat.taille; j++)
        {
			printf("Indice %d = ", i);
			scanf("%f", &nbr);
            mat.tab_mat[i][j] = nbr;
        }
    }
    return mat;
}

/***********************************************************
 *  Fonction permettant de remplir une matrice aléatoirement
 * ********************************************************/

MATRICE_CARREE generer_matrice_aleatoire(MATRICE_CARREE mat)
{
    int i, j;
    
    if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
        for(j=0; j<mat.taille; j++)
        {
            mat.tab_mat[i][j] = generer_nombre_aleatoire();
        }
    }
    
    return mat;
}

/*********************************************
 *  Fonction permettant d'afficher une matrice
 * @param mat: la matrice à afficher
 * ******************************************/

void afficher_matrice(MATRICE_CARREE mat)
{
	int i,j;
	
	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
        for(j=0; j<mat.taille; j++)
        {
            printf("mat.tab_mat[%d][%d] = %lf\n",i,j, mat.tab_mat[i][j]);
        }
    }
}

/**************************************************************************
 *  Fonction permettant de désaouller l'espace mémoire d'une matrice carrée
 * ***********************************************************************/

void desallouer_matrice_carree(MATRICE_CARREE mat)
{
	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	#pragma omp parallel for
	for(int i=0; i<mat.taille; i++) {
        free(mat.tab_mat[i]);
    }
    free(mat.tab_mat);
	return;
}

/***********************************************
 *  Fonction permettant d'allouer un vecteur
 * @param taille: la taille du vecteur à allouer
 * ********************************************/

VECTEUR allouer_vecteur(int taille)
{
	VECTEUR vect;
	
	vect.taille = taille;
	
	vect.tab_vect = (float*) malloc(sizeof(float) * vect.taille);
	
	if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	return vect;
}

/*********************************************************
 *  Fonction permettant de remplir un vecteur manuellement
 * @param vect: vecteur à remplir
 * ******************************************************/

VECTEUR remplir_vecteur(VECTEUR vect)
{
    int i;
    float nbr;
    
    if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<vect.taille; i++)
    {
    	printf("Indice %d = ", i);
       	scanf("%f", &nbr);
       	vect.tab_vect[i] = nbr;
    }
    return vect;
}

/**********************************************************
 *  Fonction permettant de remplir un vecteur aléatoirement
 * *******************************************************/

VECTEUR generer_vecteur_aleatoire(VECTEUR vect)
{
    int i;
    
    if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<vect.taille; i++)
    {
       	vect.tab_vect[i] = generer_nombre_aleatoire();
    }
    
    return vect;
}

/*********************************************
 *  Fonction permettant d'afficher un vecteur
 * ******************************************/

void afficher_vecteur(VECTEUR vect)
{
	int i;
	
	if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<vect.taille; i++)
    {
    	printf("vect.tab_vect[%d] = %lf\n",i, vect.tab_vect[i]);
    }
}

/*********************************************
 *  Fonction permettant de libérer un vecteur
 * ******************************************/
 
 void desallouer_vecteur(VECTEUR vect)
 {
	 if (vect.tab_vect == NULL)
	 {
		exit(EXIT_FAILURE);
	 }	
	 
	 free(vect.tab_vect);
	 
 }

/***********************************************************************
 *
 *                          LA PARTIE PARALLELE
 *
 * ********************************************************************/


/************************************************************
 *  Fonction de la méthode des puissances
 * *********************************************************/
 
float methodes_puissances(MATRICE_CARREE mat, VECTEUR vect, int n)
{
	int k, convergence;
    VECTEUR vectRes, vectRetour;
    float m;
    
    #pragma omp parallel num_threads(NB_THREADS)
    {    
        // m : la composante de v de module maximum
        m = 1;
    
        // vectRes : vecteur resultant de la multiplication d'une matrice par un vecteur
        vectRes.taille = mat.taille;
        vectRes = allouer_vecteur(vectRes.taille);
        
        // vectRetour
        vectRetour.taille = mat.taille;
        vectRetour = allouer_vecteur(vectRetour.taille);
    
        // initialisation
        vect = initialiser_vecteur(vect);
	
		// problème de convergence
		convergence = 5;

        //#pragma omp for schedule(static, ((convergence-1)/NB_THREADS)) ordered
		//for (k=1; k<convergence; k++)
    	//{
            vectRes = multiplier_mat_vect(mat, vect, vectRetour);
            vectRes = multiplier_vect_scal(vectRes, 1/m, vectRetour);
            
            vect = vectRes;

            m = calculer_val_max_composante(vect);
    	//}
    }    

    return m;
}


/************************************************************
 *  Fonction permettant de calculer la plus grande composante
 * *********************************************************/
   
float calculer_val_max_composante(VECTEUR vect)
{
    int i;
    float valMax=-1;
    
    if (vect.taille>0) valMax=vect.tab_vect[0];

	#pragma omp shared(valMax) for schedule(static, ((vect.taille-1)/NB_THREADS)) reduction(max: valMax)
    for (i=1; i<vect.taille; i++)
    {
        if (vect.tab_vect[i]>valMax)
            valMax = vect.tab_vect[i];
    }

    return valMax;
}

/*****************************************************************************
 *  Fonction permettant de calculer le produit entre une matrice et un vecteur
 * **************************************************************************/

VECTEUR multiplier_mat_vect(MATRICE_CARREE mat, VECTEUR vect, VECTEUR vectRes)
{
	int i, j, resColonne;
    
    #pragma omp for schedule(static, 1)
    for (i=0; i<mat.taille; i++)
    {
        resColonne = 0;
        for (j=0; j<mat.taille; j++)
        {
            resColonne += mat.tab_mat[i][j]*vect.tab_vect[j];
        }
        vectRes.tab_vect[i] = resColonne;
    }

    return vectRes;
}

/*********************************************************************************
 *  Fonction permettant d'effectuer la multiplication d'un vecteur par un scalaire
 * ******************************************************************************/

VECTEUR multiplier_vect_scal(VECTEUR vect, float scalaire, VECTEUR vectRes)
{
    int i;
    float resColonne = 0;
    
	#pragma omp for schedule(static, 1) 
    for (i=0; i<vect.taille; i++)
    {
        resColonne = vect.tab_vect[i] * scalaire;
        vectRes.tab_vect[i] = resColonne;
    }

    return vectRes;
}

/**********************************************
 *  Fonction permettant d'initialiser un vecteur
 * @param vecteur: vecteur initial
 * ********************************************/
 
VECTEUR initialiser_vecteur(VECTEUR vect)
{
	int i;
	// vectRes : vecteur resultant de l'initialisation du vecteur initial vect
	VECTEUR vectRes;
	
	// normaliser le vecteur initial vect
	float vectNormalise = normaliser_vecteur(vect);
    
    vectRes.taille = vect.taille;
    vectRes = allouer_vecteur(vectRes.taille);
	 
	#pragma omp for schedule(static, 1) 
    for(i = 0; i < vect.taille; i++)
	{
        vectRes.tab_vect[i] = vect.tab_vect[i] / vectNormalise;
    }
	 
	return vect; 
}

/*************************************************
 *  Fonction permettant de vérifier la convergence
 * **********************************************/
/*
 bool verif_convergence()
 {

 }
 */


/***********************************************************************
 *
 *            FONCTIONS DE TESTS POUR LA PARTIE PARALLELE
 *
 * ********************************************************************/


/*************************************************************************
 *  Fonction permettant de tester la fonction calculer composante maximale
 * **********************************************************************/

bool tester_fct_calculer_val_max()
{
    VECTEUR vect;
    float resAttendu, resObtenu;

    vect.taille = 4;
    vect = allouer_vecteur(vect.taille);
    vect.tab_vect[0]=7;
    vect.tab_vect[1]=8;
    vect.tab_vect[2]=4;
    vect.tab_vect[3]=7;

    resAttendu = 8;

	resObtenu = calculer_val_max_composante(vect);

    if (resAttendu!=resObtenu) return false;
    return true;
}

/***********************************************************************
 *  Fonction permettant de tester la fonction multiplier matrice vecteur
 * ********************************************************************/

bool tester_fct_multiplier_mat_vect()
{
    int i;
    MATRICE_CARREE mat;
    VECTEUR vect;
    VECTEUR vectResAttendu;
    VECTEUR vectResObtenu;
    bool memesVecteurs = true;

    mat = allouer_matrice_carree(4);
    mat.tab_mat[0][0]=3;
    mat.tab_mat[0][1]=0;
    mat.tab_mat[0][2]=8;
    mat.tab_mat[0][3]=8;

    mat.tab_mat[1][0]=2;
    mat.tab_mat[1][1]=9;
    mat.tab_mat[1][2]=1;
    mat.tab_mat[1][3]=7;

    mat.tab_mat[2][0]=1;
    mat.tab_mat[2][1]=3;
    mat.tab_mat[2][2]=3;
    mat.tab_mat[2][3]=3;

    mat.tab_mat[3][0]=1;
    mat.tab_mat[3][1]=5;
    mat.tab_mat[3][2]=0;
    mat.tab_mat[3][3]=6;

    vect.taille = 4;
    vect = allouer_vecteur(vect.taille);
    vect.tab_vect[0]=7;
    vect.tab_vect[1]=8;
    vect.tab_vect[2]=4;
    vect.tab_vect[3]=7;

    vectResAttendu.taille = 4;
    vectResAttendu = allouer_vecteur(vectResAttendu.taille);
    vectResAttendu.tab_vect[0]=109;
    vectResAttendu.tab_vect[1]=139;
    vectResAttendu.tab_vect[2]=64;
    vectResAttendu.tab_vect[3]=89;

    vectResObtenu.taille = vect.taille;
    vectResObtenu = allouer_vecteur(vectResObtenu.taille);

	vectResObtenu = multiplier_mat_vect(mat, vect, vectResObtenu);

    if (vectResAttendu.taille == vectResObtenu.taille)
    {
        for(i=0; i<vectResAttendu.taille; i++)
        {
            if (vectResObtenu.tab_vect[i]!=vectResAttendu.tab_vect[i])
            {
                memesVecteurs = false;
                break;
            }
        }
    }

    else memesVecteurs = false;
    return memesVecteurs;
}

/**********************************************************************************
 *  Fonction permettant de tester la fonction multiplier un vecteur par un scalaire
 * *******************************************************************************/

bool tester_fct_multiplier_vect_scal()
{
    int i;
    VECTEUR vect;
    VECTEUR vectResAttendu;
    VECTEUR vectResObtenu;
    float scal = 3;
    bool memesVecteurs = true;

    vect.taille = 4;
    vect = allouer_vecteur(vectResObtenu.taille);
    vect.tab_vect[0]=7;
    vect.tab_vect[1]=8;
    vect.tab_vect[2]=4;
    vect.tab_vect[3]=7;

    vectResAttendu.taille = 4;
    vectResAttendu = allouer_vecteur(vectResAttendu.taille);
    vectResAttendu.tab_vect[0]=21;
    vectResAttendu.tab_vect[1]=24;
    vectResAttendu.tab_vect[2]=12;
    vectResAttendu.tab_vect[3]=21;
    
    vectResObtenu.taille = vect.taille;
    vectResObtenu = allouer_vecteur(vectResObtenu.taille);

	vectResObtenu = multiplier_vect_scal(vect, scal, vectResObtenu);

    if (vectResAttendu.taille == vectResObtenu.taille)
    {
        for(i=0; i<vectResAttendu.taille; i++)
        {
            if (vectResObtenu.tab_vect[i]!=vectResAttendu.tab_vect[i])
            {
                memesVecteurs = false;
                break;
            }
        }
    }

    else memesVecteurs = false;

    return memesVecteurs;
}

/****************************************************************
 *  Fonction permettant de tester la fonction methodes puissances
 * *************************************************************/

bool tester_fct_methodes_puissances()
{
    MATRICE_CARREE mat;
    VECTEUR vect;
    float valeur_propre_attendue = 10;
    float valeur_propre_obtenue;

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
    vect = allouer_vecteur(vect.taille);
    vect.tab_vect[0]=1;
    vect.tab_vect[1]=0;
    vect.tab_vect[2]=0;

	valeur_propre_obtenue = methodes_puissances(mat, vect, mat.taille);
    
    if (valeur_propre_attendue!=valeur_propre_obtenue) return false;
    return true;
}

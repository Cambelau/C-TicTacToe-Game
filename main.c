#include <stdio.h>

// Signes pour les deux joueurs
const char signe1='*';
const char signe2='o';

void initialisationgrille(char grille[3][3])
{
	int i; // Ligne
	int j; // Colonne
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			grille[i][j]=' ';
		}
	}
}

void affichergrille(char grille[3][3])
{
	int i; // Ligne
	int j; // Colonne
	printf("-------------\n");
	for(i=0;i<3;i++)
	{
	    printf("|");
	    for(j=0;j<3;j++)
	    {
		printf(" %c |",grille[i][j]);
	    }
	    printf("\n");
	}
	printf("-------------\n");
 }

int remplirgrille(char grille[3][3],char signe)
// Renvoie 0 si la grille n a pas ete remplie
// Renvoie 1 si la grille a ete correctement remplie
{
    int ligne;
    int colonne;
    int reponse=0;
    printf("veuillez entrer la ligne: \n");
    scanf("%d",&ligne);
    printf("veuillez entrer la colonne: \n");
    scanf("%d",&colonne);
    do
    {

    if((ligne>0 && ligne<=3)&&(colonne>0 && colonne<=3))
    {
        if(grille[ligne-1][colonne-1]!=' ')
        {
            printf("déjà rempli \n");
        }
        else
       {
            grille[ligne-1][colonne-1]=signe;
            reponse=1;
       }
    }
    else
    {
        printf("coordonnées pas correct \n");
    }
    }while(reponse!=0);
    return(reponse);
}

char testgagnant(char grille[3][3])
//Renvoie ' ' si pas de gagnant
//Renvoie le signe du gagnant sinon
{
    char reponse=' ';
    if((grille[0][0]==grille[1][1])&&(grille[1][1]==grille[2][2]))
    {
        reponse=grille[0][0];
    }
    else
    {
        if((grille[0][0]==grille[0][1])&&(grille[0][1]==grille[0][2]))
        {
            reponse=grille[0][0];
        }
        else
        {
            if((grille[1][0]==grille[1][1])&&(grille[1][1]==grille[1][2]))
            {
                reponse=grille[1][0];
            }
            else
            {
                if((grille[2][0]==grille[2][1])&&(grille[2][1]==grille[2][2]))
                {
                    reponse=grille[2][0];
                }
                else
                {
                    if((grille[0][0]==grille[1][0])&&(grille[1][0]==grille[2][0]))
                    {
                        reponse=grille[0][0];
                    }
                    else
                    {
                        if((grille[0][1]==grille[1][1])&&(grille[1][1]==grille[2][1]))
                        {
                            reponse=grille[0][1];
                        }
                        else
                        {
                            if((grille[0][2]==grille[1][2])&&(grille[1][2]==grille[2][2]))
                            {
                                reponse=grille[0][0];
                            }
                            else
                            {
                                if((grille[0][2]==grille[1][1])&&(grille[1][1]==grille[2][0]))
                                {
                                    reponse=grille[0][2];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return(reponse);
}






int main()
{
	char grille1[3][3];
    char signe[2];
    char joueur1[20] ;
    char joueur2[20] ;
    int reponse1 ;
	initialisationgrille(grille1);
	affichergrille(grille1);
	printf("Joueur 1 : Entrez votre prenom \n");
	scanf("%s",&joueur1);
	while(getchar()!='\n') ;
	printf("Joueur 2 : Entrez votre prenom \n");
	scanf("%s",&joueur2);
	while(getchar()!='\n') ;
	// On recupere les signes de deux joueurs
	do
	{
		printf("vous avez le choix entre 2 signes: \n");
		printf("signe1='*' et signe2='o'\n");
		printf("entrez votre choix Joueur 1 \n");
		scanf("%c",&signe[0]);
		while(getchar()!='\n') ;
		if( signe[0] == signe2 )
		{
			signe[1]=signe1;
		}
		else
		{
			signe[1]=signe2;
		}
	}
	while ( (signe[0]!='*') && (signe[0]!='o') );
	printf("Nom Joueur 1 : %s et Signe : %c \n ", joueur1, signe[0] ) ;
	printf("Nom Joueur 2 : %s et Signe : %c \n ", joueur2, signe[1] ) ;

    affichergrille(grille1);
    reponse1 = remplirgrille(grille1,signe[0]);
    testgagnant(grille1);
    Fin_partie(grille1);

	return 0 ;
}

int Fin_partie(char grille[3][3])
// Renvoie 1 si la grille est completement remplie
// Renvoie 0 sinon
{
    int i;
    int j ;
    int reponse = 0 ;
    do
    {
        for (i=0;i<3;i++)
        {
           for(j=0;j<3;j++)
          {
            if(grille[i][j]==' ')
            {
                return(reponse) ;
            }
          }
        }
    reponse = 1 ;
    }while(reponse==0 && reponse==1);
    return reponse ;
}

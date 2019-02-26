#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define colone 7
#define ligne 6
/*Initialisation  des variables */
char X='X';
char O='O';
char* J1;
char* J2;

int gagner = 0;
int attaquer = 1;

void presentation(char* J1,char* J2){
    
    printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(" ++++++++                                    ++++++++\n");
    printf(" ++++++                                        ++++++\n");
    printf(" +++             Jeux PUISSANCE 4                 +++\n");
    printf(" +++                                              +++\n");
    printf(" ++++++                                        ++++++\n");
    printf(" ++++++++                                    ++++++++\n");
    printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
    printf("\n");
    printf("\n");


/*Les joueurs saissie leur noms*/
    printf("****************************************************\n");
    printf("Joueur 1 choisi ton noms \n");
    scanf("%s",J1);
    fflush(stdin); // vider e tampon de sorti 
    printf("\n");
    printf("Joueur 2 choisi ton noms \n");
    scanf("%s",J2); 
    fflush(stdin);
    printf("\n");
    printf("****************************************************\n");


// couleur des joueur 


    printf("%s, vous jouez les pions Rouge(X)\n",J1);
    printf("%s, vous jouez les pions Bleu(O)\n",J2 );
    printf("****************************************************\n");
    printf("\n");
    printf("\n");


}



// Initialiser le tableau 
void init(char grille[ligne][colone]){ 
    int i,j;
	for(i = 0 ; i < colone; i++){
		for(j = 0 ; j<=ligne; j++){
			grille[i][j]='.'; /
		}					 
	}						  
} 

// affichage de la grille 
void afficheGrille(char grille[ligne][colone]){
	int i,j;                           
	for(i = 0; i < colone; i++){ 
		printf("  %d  ", i + 1); 
	}
        printf("\n|");
    
	for(i = 0; i<colone; i++){   $
		printf("%s","-----" ); 
	}
	printf("|"); 
	printf("\n");

for(i = ligne ; i > 0; i--){ 
        printf("|");
        for(j = 0; j < colone; j++){
            printf("  %c  ", grille[j][i]);
        }
        printf("|\n");
    }
    printf("|");
    for(j = 0; j < colone; j++)
        printf("_____");
    printf("|\n");	
    printf(" ");
	for(i = 0; i < colone; i++){
		printf("  %d  ",i+1);
	}
	printf("\n");
}

void choix (char grille[ligne][colone], char* Joueur){
    int choix, i ;

//Le joueur choisi la colonne
printf("%s ! Entrez les coordonnees: \n", Joueur); 
scanf("%d", &choix); 

//Tant que colonne choisie  pleine 
while((grille[choix][0] == X) || (grille[choix][0] == O)){ 

    printf("La colonne est pleine!\n\n"); 
    printf("%s ! Entrez les coordonnees: \n", Joueur); 
    scanf("%d", &choix); 
} 
// tant que le joueur entre pas une colonne valide
    while((choix > colone) || (choix < 1)){ 

        printf("Entrez une colonne correct!\n\n"); 
        printf("%s ! Entrez les coordonnees: \n", Joueur); 
        scanf("%d", &choix); 
}   
/*Verifie si la premiere case ( derniere ligne grille) vide sinon place le placement du  pion  au dessus */
    for(i = ligne; i >= 0; i--){ 
        if(grille[choix][i]=='.'){ 
            if(Joueur == J1){ 
                grille[choix][i] = X; 
            }else{ 
                grille[choix][i] = O; 
            }
        }
    }
}
    

    




int main(int argc , char **argv){
    char* Joueur = malloc(20*sizeof(char));
    char* J1 = malloc(20*sizeof(char));
    char* J2 = malloc(20*sizeof(char));
	presentation(J1,J2);

	char grille [ligne][colone];
	init(grille);
	afficheGrille(grille);
    choix(grille,J1);
    choix(grille,J2);
    return 0;
}
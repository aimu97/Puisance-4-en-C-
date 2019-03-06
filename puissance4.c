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

		for(j = 0 ; j <= ligne; j++){

			grille[i][j] = '.';
		}					 
	}						  
} 

// affichage de la grille 

void aff(char grille[ligne][colone]) {
    for(int i = 0; i < colone; i++){
        printf(" %d ", i + 1);
    }
    printf("\n");


    for(int i = (ligne - 1); i >= 0; i--){
        for (int y = 0; y < colone ; y++)
            printf(" %c ", grille[i][y]);
        printf("\n");
    }
    printf("\n");
    printf("\n");
}
    


int choix (char grille[ligne][colone], int Joueur, int choix_j){
    int i = 0;
while(i < 6){
    if(grille[i][choix_j] == '.' && Joueur == 0){
            grille[i][choix_j] = 'X'; 
            return 0;
        }
     if (grille[i][choix_j] =='.' && Joueur == 1){
            grille[i][choix_j] = 'O';
            return 0;
        }
    i++;
}
return 1;
}
    
int  verification(char grille[ligne][colone], int Joueur){

    int i;
    int j;
// Horizontale 

    for(i = 0; i < ligne; i++){
        for(j = 0; j < 4; j++){ // 4 car pions aligner = gagner 

            if(Joueur == 0){

               
                if(grille[i][j] == 'X' && grille[i][j+ 1] == 'X' && grille[i][j + 2] == 'X' && grille[i][j + 3] == 'X' ){
                    return 0;

                }
            }
            else{

                if(grille[i][j] == 'O' && grille[i][j + 1] == 'O' && grille[i][j + 2] =='O' && grille[i][j + 3] == 'O'){
                    return 0;

                }  
            }
        }
      

    }



//Vertical


for(j = 0; j < colone; j++){
        for(i = 0; i < 4; i++){ // 4 car pions aligner = gagner 

            if(Joueur == 0){

               
                if(grille[i][j] == 'X' && grille[i + 1][j] == 'X' && grille[i + 2][j] == 'X' && grille[i + 3][j] == 'X' ){
                    return 0;

                }
            }
            else{

                if(grille[i][j] == 'O' && grille[i + 1][j] == 'O' && grille[i + 2][j] =='O' && grille[i + 3][j] == 'O'){
                    return 0;

                }  
            }
        }
      

    }

// diagonal gauche vers droite 

    for( i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            if( i + 3 < ligne && j + 3 < colone){ // condition pour ne pas avoir de débordement 
                if(Joueur == 0){
                    if(grille[i][j] == 'X' && grille[i + 1][j + 1] =='X' && grille[i + 2][j + 2] && grille[i + 3][j + 3] == 'X'){
                        return 0;
                    }
                    else{
                       if(grille[i][j] == 'O' && grille[i + 1][j + 1] =='O' && grille[i + 2][j + 2] && grille[i + 3][j + 3] == 'X'){
                            return 0;

                       }

                    }
                }

            }
        }
    }

//diagonal droite gauche
    for( i = ligne; i >= 3; i--){
        for(j = 0; j < 4; j++){
            if(i - 3 >= 0 && j + 3 <= colone){
                if(Joueur == 0){
                    if(grille[i][j] =='X' && grille[i - 1][j + 1] == 'X' && grille[i - 2][j +2] == 'X' && grille[i - 3][j + 3] == 'X'){
                        return 0;
                    }

                    else{

                        if(grille[i][j] =='O' && grille[i - 1][j + 1] == 'O' && grille[i - 2][j +2] == 'O' && grille[i - 3][j + 3] == 'O'){
                            return 0;
                        }

                    }
                }
            }
        }
    }

    return 1;
   
  }
    




int main(int argc , char **argv){

    int Joueur = 0;
    char* J1 = malloc(20*sizeof(char));
    char* J2 = malloc(20*sizeof(char));
    char grille [ligne][colone];
    int condition_victoire = 1;
    int choix_j;
    int round = 1;

    presentation(J1,J2);
    init(grille);

    while(condition_victoire == 1){

        //afficheGrille(grille);
        aff(grille);
        if(Joueur == 0){
            printf("%s ! Entrez les coordonnees: \n", J1); 
            scanf("%d", &choix_j);
            choix_j = choix_j - 1;

            printf("\n");
             }
        else{
            printf("%s ! Entrez les coordonnees: \n", J2); 
            scanf("%d", &choix_j); 
            choix_j = choix_j - 1;
            printf("\n");
        }

        if(choix(grille,Joueur,choix_j) == 0 && round <= 42){
            //test_victoire();
           condition_victoire = verification(grille,Joueur);

           if(condition_victoire == 1){
            if(Joueur == 1)
                Joueur = 0;
            else
                Joueur = 1;
        }
            round ++;
        }
        else{
            printf("Saissez une autre colone \n");

        }
    }
    

    if(round <= 42){
        if(Joueur == 0){
             aff(grille);

            printf("%s a gagner! Bravo\n",J1);
        }
        else if(Joueur == 1){
             aff(grille);
            printf("%s a gagner! Bravo\n",J2);
        }
        
        else{
            printf("Match nul !\n");
        }


        

    
    return 0;
}
}

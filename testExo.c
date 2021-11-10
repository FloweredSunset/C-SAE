#include<stdio.h>
#include<stdlib.h>
#include"exo.h"

int main(void) {

   /* ------------------------------- */

	int taille=40,tabNum[taille], tabStock[taille], tabInfo[4], fin, choix, comptageH=0;
	float tabPrix[taille];
	char tabNom[taille],*clear="clear";

   /* ------------------------------- */
   system(clear);

   printf("\n              .--.                   .---.\n");
   printf("          .---|__|           .-.     |~~~|\n");
   printf("       .--|===|--|_          |_|     |~~~|--.\n");
   printf("       |  |===|  |'\\     .---!~|  .--|   |--|\n");
   printf("       |==|   |  |.'\\    |===| |--|++|   |  \n");
   printf("       |  |   |  |\\.'\\   |   | |__|  |   |  |\n");
   printf("       |==|   |  | \\  \\  |===| |==|  |   |  |\n");
   printf("       |  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n");
   printf("       |  |===|--|   \\.'\\|===|~|--|++|~~~|--|\n");
   printf("       ^--^---'--^    `-'`---^-^--^--^---'--'\n\n");

   /* Boucle pour le menu */
   fin = 0;
  
   while(!fin) {
      char *clear="clear";
      
      printf("Menu:\n"
               "1.Passer un devis\n"
               "2.Passer une commande\n" /* affichage menu */
               "3.Accéder à l'historique des commandes\n"
               "4.Accéder à la gestion des stocks\n"
               "5.Quitter\n");

      printf("\n--> ");
      scanf("%d",&choix);

      switch(choix)
      {
         case 1:
            system(clear);
            printf("\nSTATUS: Exécution de la fonction de devis.\n");
            devis(tabNum, tabNom, tabStock, tabPrix, taille, tabInfo);
            printf("STATUS: Devis terminé.\n\n");
            continue;

         case 2:
            system(clear);
            printf("\nSTATUS: Exécution de la fonction passage de commande.\n");
            commande(tabNum, tabNom, tabStock, tabPrix, taille, tabInfo);
            printf("STATUS: Commande passée.\n\n");
            printf("RESULT:\n\tAjout de la commande passée à l'historique\n\tn°client: %d\n\tn°livre : %d\n\tnb livre: %d\n\n",tabInfo[0],tabInfo[1],tabInfo[2]);
            continue;

         case 3:
            system(clear);
            printf("STATUS: Exécution de la fonction d'affichage d'historique.\n");
            
            FILE *historique;
            historique=fopen("historique","r");

            while(feof(historique)==0) {
               comptageH++;
               fscanf(historique,"%*d %*c %*d %*f ");
            }
            comptageH++;

            historiqueCommande(comptageH);
            printf("\nSTATUS: Fonction d'affichage de l'historique terminée.\n\n");
            comptageH=0;
            continue;
 
         case 4:
            system(clear);
            printf("STATUS: Exécution de la fonction de gestion des stocks.\n");
            gstock(tabNum, tabStock, taille);
            printf("STATUS: Fonction de gestion des stocks terminée.\n\n");
            continue;
         
         case 5:
            system(clear);
            fin = 1;
            continue;
         default:
            system(clear);
            printf("Choix errone\n");
      }
   }

   /* fin */

   /* ------------------------------- */
 
   return 0;
}

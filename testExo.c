#include<stdio.h>
#include<stdlib.h>
#include"exo.h"

int main(void) {
   /* ------------------------------- */

	int tabNum[40], tabStock[40], tabInfo[4], fin, choix;
	float tabPrix[40];
	char tabNom[40],*clear="clear";

   /* ------------------------------- */
   system(clear);
   /* Boucle pour le menu */
   fin = 0;
  
   while(!fin) {
      char *clear="clear";
      
      printf("1.Passer une commande\n" /* affichage menu */
               "2.Accéder à l'historique des commandes\n"
               "3.Choix 3\n"
               "4.Quitter\n");

      printf("\n--> ");
      scanf("%d",&choix);

      switch(choix)
      {
         case 1:
            system(clear);
            printf("\nSTATUS: Exécution de la fonction passage de commande.\n");
            commande(tabNum, tabNom, tabStock, tabPrix, 40, tabInfo);
            printf("STATUS: Commande passée.\n\n");
            printf("RESULT:\n\tAjout de la commande passée à l'historique\n\tn°client: %d\n\tn°livre : %d\n\tnb livre: %d\n\n",tabInfo[0],tabInfo[1],tabInfo[2]);
            continue;

         case 2:
            system(clear);
            printf("STATUS: Exécution de la fonction d'affichage d'historique.\n");
            historiqueCommande(tabInfo, 3);
            printf("\nSTATUS: Fonction d'affichage de l'historique terminée.\n\n");
            continue;

         case 3:
            system(clear);
            printf("Choix 3\n");
            continue;
 
         case 4:
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

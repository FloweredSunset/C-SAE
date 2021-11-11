#include<stdio.h>
#include<stdlib.h>
#include"exo.h"

int main(void) {

   //taille -> Taille des tableaux. fin -> menu. choix -> menu. comptageH -> taille du tableau pour historique
   int taille=40, fin=0, choix, comptageH=0;
   
   //-> Utile pour clear le terminal à chaque changement d'état du programme
   char *clear="clear";

   /* Initialisation des tableaux (tableau qui renvoie les informations, noms, prix, stock et numéro du produit) */
   int tabNum[taille], tabStock[taille], tabInfo[4];
   char tabNom[taille];
   float tabPrix[taille];

   //clear le terminal (côtés esthétique).
   system(clear);

   // Affichage d'un livre (côtés esthétique).
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
   while(!fin) {
      char *clear="clear";
   // Affichage des différentes fonctionnalitées    
      printf("Menu:\n"
               "1. Passer un devis\n"
               "2. Passer une commande\n" /* affichage menu */
               "3. Accéder à l'historique des commandes\n"
               "4. Accéder à la gestion des stocks\n"
               "9. Exit\n");

      printf("\n--> "); 
      // Stockage dans la variable choix  
      scanf("%d",&choix);
      // Menu switch
      switch(choix)
      {
          // Si l'utilisateur met 1 lancer la commande devis
         case 1:
            system(clear);
            printf("\nSTATUS: Exécution de la fonction de devis.\n");
            devis(tabNum, tabNom, tabStock, tabPrix, taille, tabInfo);
            printf("STATUS: Devis terminé.\n\n");
            continue;
          // Si l'utilisateur met 2 lancer la fonction commande
         case 2:
            system(clear);
            printf("\nSTATUS: Exécution de la fonction passage de commande.\n");
            commande(tabNum, tabNom, tabStock, tabPrix, taille, tabInfo);
            printf("\nSTATUS: Fin de la fonction commande.\n\n");
            printf("-----| Si 0 n'a pas été sélectionné |-----\n");
            printf("RESULT:\n\n\tAjout de la commande passée à l'historique\n\tn°client: %d\n\tn°livre : %d\n\tnb livre: %d\n\n",tabInfo[0],tabInfo[1],tabInfo[2]);
            continue;
          // Si l'utilisateur met 3 lancer la fonction d'affichage d'historique
         case 3:
            system(clear);
            printf("STATUS: Exécution de la fonction d'affichage d'historique.\n");
            
            FILE *historique;
            historique=fopen("historique","r");

            while(feof(historique)==0) {
               comptageH++;
               fscanf(historique,"%*d %*c %*d %*f ");
            }
            comptageH+=2;

            historiqueCommande(comptageH);
            printf("\nSTATUS: Fonction d'affichage de l'historique terminée.\n\n");
            comptageH=0;
            continue;
          // Si l'utilisateur met 4 lancer la foction de gestion des stocks
         case 4:
            system(clear);
            printf("STATUS: Exécution de la fonction de gestion des stocks.\n");
            gstock(tabNum, tabStock, taille);
            printf("STATUS: Fonction de gestion des stocks terminée.\n\n");
            continue;
          // Si l'utilisateur met 9 mettre fin aux switch
         case 9:
            system(clear);
            fin = 1;
            continue;
          // Si l'utilisateur met un choix qui ne figure pas sur le menu, mettre une erreur et relancer la boucle
         default:
            system(clear);
            printf("\nERROR: case sélectionnée inexistante.\n\n");
      }
   }

   /* fin */

   /* ------------------------------- */
 
   return 0;
}

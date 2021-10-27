#include<stdio.h>
#include<stdlib.h>
#include"exo.h"

int commande(int tabNum[], char tabNom[], int tabStock[], float tabPrix[], int taille, int tabInfo[]) {

	/* Inititalisation des différentes variables:*/
	char nameL,*clear="clear";;
	int nb, numL, nInStockL, lSelect, nbL, numClient, fin=0, reponse;
	float priceL, PrixCommande=0;

	FILE *fs, *fichier;

	fs=fopen("livres","r");
	fichier=fopen("historique","a");

	perror("\nLancement de la commande");
	printf("\n");
	if (fs == NULL) {
		printf("Error: Erreur lors de l'ouverture du fichier.\n");
		return -1;
	}

	while(fin==0) {
		printf("Quel est votre numéro de client ?\n");
		printf("-> ");
		scanf("%d",&numClient);

		fscanf(fs,"%d %c %d %f",&numL, &nameL, &nInStockL, &priceL);

		nb=1;

		tabNum[nb]=numL;
		tabNom[nb]=nameL;
		tabStock[nb]=nInStockL;
		tabPrix[nb]=priceL;

		if(tabPrix[nb]<10) {
			printf("n°livre\t nom\t stock\t prix\n");
			printf(" %d\t",tabNum[nb]);
			printf("  %c\t",tabNom[nb]);
			printf("  %d\t",tabStock[nb]);
			printf("  0%2.2f\n",tabPrix[nb]); }

		printf("n°livre\t nom\t stock\t prix\n");
		printf(" %d\t",tabNum[nb]);
		printf("  %c\t",tabNom[nb]);
		printf("  %d\t",tabStock[nb]);
		printf("  %2.2f\n",tabPrix[nb]);

		while (nb<taille) {
			nb+=1;

			fscanf(fs,"%d %c %d %f",&numL, &nameL, &nInStockL, &priceL);

			tabNum[nb]=numL;
			tabNom[nb]=nameL;
			tabStock[nb]=nInStockL;
			tabPrix[nb]=priceL;

			if(tabPrix[nb]<10) {
				printf(" %d\t",tabNum[nb]);
				printf("  %c\t",tabNom[nb]);
				printf("  %d\t",tabStock[nb]);
				printf("  0%2.2f\n",tabPrix[nb]); }	
			else {
				printf(" %d\t",tabNum[nb]);
				printf("  %c\t",tabNom[nb]);
				printf("  %d\t",tabStock[nb]);
				printf("  %2.2f\n",tabPrix[nb]); }
		}

		printf("\n-> %d livres ont étés trouvés.\n\n",nb);

		printf("Quel livre voulez-vous acheter ?\n");
		printf("-> ");
		scanf("%d",&lSelect);

		while(lSelect>taille) {
			printf("\nError: Veuillez choisir un livre présent dans la liste énoncée plus haut.\n\n");
			printf("Quel livre voulez-vous acheter ?\n");
			printf("-> ");
			scanf("%d",&lSelect);
		}

		printf("\n-------:livre sélectionné:-------\n\n"); //transition

		printf("n°livre\t nom\t stock\t prix\n");
		printf(" %d\t",tabNum[lSelect]);
		printf("  %c\t",tabNom[lSelect]);
		printf("  %d\t",tabStock[lSelect]);
		printf("  %2.2f\n",tabPrix[lSelect]);

		printf("\nCombien voulez-vous acheter d'exemplaires ?\n");
		printf("->");
		scanf("%d",&nbL);

		PrixCommande=(nbL*tabPrix[lSelect]);

		printf("\nPrix total de votre commande: %2.2f €\n\n",PrixCommande);

		printf("Êtes-vous sûr de vouloir passer cette commande ? (0 to abort, anything else to confirm)\n");
		printf("->");
		scanf("%d",&reponse);
		
		if(reponse!=0) fin=1;
		else {
			system(clear);
			printf("STATUS: ARRÊT DE LA FONCTION ('0' sélectionné)\n");
			printf("STATUS: RESTART de la fonction\n\n");
			fin=0;
		}
	}

	printf("\nRécapitulatif de la commande:\n");
	printf("-> n° de client: %d\n-> livre sélectionné: %d\n-> nb d'exemplaires achetés: %d\n-> prix total: %2.2f\n",numClient,lSelect,nbL,PrixCommande);
	fclose(fs);
	printf("\n---------------------------------\n\n");

	printf("aaaaaaaaaaaaaaaaa\n");
	printf("%d %d %d\n",numClient, lSelect, nbL );
	fprintf(fichier,"%d\t%d\t%d\n",numClient, lSelect, nbL);
	printf("aaaaaaaaaaaaaaaaa\n");

	tabInfo[0]=numClient;
	tabInfo[1]=lSelect;
	tabInfo[2]=nbL;

	return *tabInfo;
}

void historiqueCommande(int tabInfo[], int taille) {
	FILE *fichier;
	int nb=0, numC, numL, nbL, tabNum[40], tabL[40], tabNbL[40];

	fichier=fopen("historique","r");

	printf("\nNum-Commande:\tNum-Client:\tNum-Livre:\tNb-Exemplaires:\n");
	while (nb<taille) {
		nb+=1;

		fscanf(fichier,"%d %d %d",&numC, &numL, &nbL);

		tabNum[nb]=numC;
		tabL[nb]=numL;
		tabNbL[nb]=nbL;

		printf("     %d\t\t",nb);
		printf("     %d\t\t",tabNum[nb]);
		printf("     %d\t\t",tabL[nb]);
		printf("     %d\n",tabNbL[nb]);
	
	}
}

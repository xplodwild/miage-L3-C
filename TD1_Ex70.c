/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	// On valide le nombre d'arguments
	if (argc != 2)
	{
		printf("Usage: %s fichier_annuaire\n", argv[0]);
		exit(-1);
	}

	// On essaye d'ouvrir le fichier annuaire en lecture
	FILE* fp_src = fopen(argv[1], "r");
	
	if (!fp_src)
	{
		printf("Impossible d'ouvrir %s!\n", argv[1]);
		exit(-1);
	}
	
	
	// On le lis
	char* ligne = NULL;
	char* nom = NULL;
	char* prenom = NULL;
	char* adresse = NULL;
	char* telephone = NULL;	
	
	while (!feof(fp_src)){
		printf("Lecture..\n");
		
		ligne = (char*)malloc(sizeof(char) * 255);
		nom = (char*)malloc(sizeof(char) * 255);
		prenom = (char*)malloc(sizeof(char) * 255);
		adresse = (char*)malloc(sizeof(char) * 255);
		telephone = (char*)malloc(sizeof(char) * 255);
		
		fscanf(fp_src, "%s", ligne);
		
		char *ptrtocomma;
		if(ptrtocomma=strchr(ligne, ';')!=NULL)
		{
			printf("Trouve nom %p\n", ptrtocomma);
			while (nom != ptrtocomma)
			{
				printf("Copie %c\n", ptrtocomma[0]);
				(*nom++) = (*ptrtocomma++);
			}
		}
		
		if(ptrtocomma=strchr(ptrtocomma, ';')!=NULL)
		{
			printf("Trouve prenom\n");
			while (ligne != ptrtocomma)
			{
				(*prenom++) = (* ptrtocomma ++);
			}
		}
		
		if(ptrtocomma=strchr(ptrtocomma, ';')!=NULL)
		{
			while (ligne != ptrtocomma)
			{
				(*adresse++) = (* ptrtocomma ++);
			}
		}
		
		if(ptrtocomma=strchr(ptrtocomma, ';')!=NULL)
		{
			while (ligne != ptrtocomma)
			{
				(*telephone++) = (* ptrtocomma ++);
			}
		}
		
		printf("Va afficher..\n");
		printf("Nom: %s\n", nom);
		
	}
	
		
	// On affiche le résultat
	printf("Termine.\n");
	
	return 0;
}

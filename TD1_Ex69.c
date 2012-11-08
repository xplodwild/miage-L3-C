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
	if (argc != 5)
	{
		printf("Usage: %s source destination recherche remplacement\n", argv[0]);
		exit(-1);
	}

	// On essaye d'ouvrir le fichier source en lecture
	FILE* fp_src = fopen(argv[1], "r");
	
	if (!fp_src)
	{
		printf("Impossible d'ouvrir %s!\n", argv[1]);
		exit(-1);
	}
	
	// On essaye d'ouvrir le fichier desination en écriture
	FILE* fp_dest = fopen(argv[2], "w+");
	
	if (!fp_dest)
	{
		printf("Impossible d'ouvrir %s!\n", argv[2]);
		exit(-1);
	}

	
	// On recopie caractère par caractère
	while (!feof(fp_src))
	{
		char* src = (char*)malloc(sizeof(char) * (strlen(argv[3]) + 1));
		fgets(src, strlen(argv[3])+1, fp_src);
		
		printf("'%s' == '%s'\n", src, argv[3]);
		
		// Si la chaine est celle qu'on cherche
		if (strcmp(src, argv[3]) == 0)
		{
			fputs(argv[4], fp_dest);
		}
		else
		{
			fputs(src, fp_dest);
		}
	}
	
	// On affiche le résultat
	printf("Termine.\n");
	
	
	return 0;
}

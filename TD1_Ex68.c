/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>


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
		char c = fgetc(fp_src);
		
		// Si le caractère est celui qu'on cherche
		if (c == argv[3][0])
		{
			fputc(argv[4][0], fp_dest);
		}
		else
		{
			fputc(c, fp_dest);
		}
	}
	
	// On affiche le résultat
	printf("Termine.\n");
	
	
	return 0;
}

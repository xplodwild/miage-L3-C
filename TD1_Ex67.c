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
	if (argc != 3)
	{
		printf("Usage: %s filename character\n", argv[0]);
		exit(-1);
	}

	// On essaye d'ouvrir le fichier en lecture
	FILE* fp = fopen(argv[1], "r");
	
	if (!fp)
	{
		printf("Impossible d'ouvrir %s!\n", argv[1]);
		exit(-1);
	}
	
	
	int count = 0;
	
	// On lit caractère par caractère
	while (!feof(fp))
	{
		char c = fgetc(fp);
		
		// Si le caractère est celui qu'on cherche
		if (c == argv[2][0])
		{
			count++;
		}
	}
	
	// On affiche le résultat
	printf("Il y a %d fois %c\n", count, argv[2][0]);
	
	
	return 0;
}

/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		printf("Usage: %s valeur1 valeur2 valeur3 ..\n", argv[0]);
		exit(-1);
	}
	
	int i = 1;
	int somme = 0;
	for (; i < argc; i++)
	{
		somme += atoi(argv[i]);
	}	
	
	printf("Somme: %d\n", somme);
	
	return EXIT_SUCCESS;
}
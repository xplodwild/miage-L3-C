/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - r�utilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

int main(int argc, char* argv[])
{
	int n, ret = 0;
	
	// Lis un nombre d�cimal
	while (ret != 1)
	{
		printf("Entrez un nombre d�cimal: ");
		ret = scanf("%d", &n);
		CLRBUF;
	}
	
	// Affiche sa valeur hexad�cimale
	printf("En hexa: %x\n", n);
	
	// Lis un nombre hexa
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez un nombre hexa: ");
		ret = scanf("%x", &n);
		CLRBUF;
	}
	
	// Affiche sa valeur d�cimale
	printf("En base 10: %d\n", n);
	
	return 0;
}

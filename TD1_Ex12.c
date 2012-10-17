/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

int main(int argc, char* argv[])
{
	int n, ret = 0;
	
	// Lis un nombre décimal
	while (ret != 1)
	{
		printf("Entrez un nombre décimal: ");
		ret = scanf("%d", &n);
		CLRBUF;
	}
	
	// Affiche sa valeur hexadécimale
	printf("En hexa: %x\n", n);
	
	// Lis un nombre hexa
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez un nombre hexa: ");
		ret = scanf("%x", &n);
		CLRBUF;
	}
	
	// Affiche sa valeur décimale
	printf("En base 10: %d\n", n);
	
	return 0;
}

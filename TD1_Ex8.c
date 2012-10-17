/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule a^b
int power(int a, int b);

int main(int argc, char* argv[])
{
	int a, b, ret = 0;

	// Lis le nombre 1
	while (ret != 1) {
		printf("Nombre 1: ");
		ret = scanf("%d", &a);
		CLRBUF;
	}
	
	// Lis le nombre 2
	ret = 0;
	while (ret != 1) {
		printf("Nombre 2: ");
		ret = scanf("%d", &b);
		CLRBUF;
	}
	
	// Affiche la puissance
	printf("%d\n", power(a,b));
	
	return 0;
}

int power(int a, int b)
{
	int result = 1;
	int i = 0;
	
	// Si b vaut zéro, x^0 vaut toujours 1
	if (b == 0) {
		return 1;
	}
	
	for (; i < b; i++) {
		result *= a;
	}

	return result;
}
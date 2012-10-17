/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule la suite de fibonnaci à la raison n
int fibonacci(int n);

int main(int argc, char* argv[])
{
	int x, ret = 0;
	
	// Lis la raison
	while (ret != 1)
	{
		printf("Raison: ");
		ret = scanf("%d", &x);
		CLRBUF;
	}
	
	// Calcule et affiche 
	printf("Résultat: %d\n", fibonacci(x));
			
	return 0;
}

int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int sum;
	int i;

	for (i=0; i<n; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}

	return a;
}
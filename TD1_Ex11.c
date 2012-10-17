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
	int n, somme = 0, ret = 0;
	
	// Lis le nombre
	while (ret != 1)
	{
		printf("Nombre: ");
		ret = scanf("%d", &n);
		CLRBUF;
	}
	
	// Calcule la somme en divisant le nombre par 10 et en utilisant le reste de la 
	// division à chaque fois
	while (n != 0)
	{
		int c = n%10;
		somme += c;
		n /= 10;
	}
	
	printf("Somme: %d\n", somme);
		
	return 0;
}

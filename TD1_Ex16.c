/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Retourne si oui ou non un nombre est premier
int prime(int x);

int main(int argc, char* argv[])
{
	int x, ret = 0;
	
	// Lis le nombre
	while (ret != 1)
	{
		printf("Nombre: ");
		ret = scanf("%d", &x);
		CLRBUF;
	}
	
	// Calcule si le nombre est premier ou non, et affiche une chaine en conséquence
	printf("%s\n", prime(x) ? "Premier" : "Pas Premier");
			
	return 0;
}

int prime(int x)
{	
	int i = 2;
	for (; i <= x-1; i++)
	{ 
		if (x%i == 0)
		{
			// On trouve un diviseur pour le nombre x (autre que 1 et lui-même), donc il n'est pas premier.
			return 0;
		}
   }
   
   return 1;
}
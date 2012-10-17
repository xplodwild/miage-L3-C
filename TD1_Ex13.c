/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule le PGCD entre x et y
int pgcd(int x, int y);

int main(int argc, char* argv[])
{
	int x, y, ret = 0;
	
	// Lis les deux nombres
	while (ret != 1)
	{
		printf("Nombre 1: ");
		ret = scanf("%d", &x);
		CLRBUF;
	}
	
	ret = 0;
	while (ret != 1)
	{
		printf("divisé par: ");
		ret = scanf("%d", &y);
		CLRBUF;
	}
	
	// Affiche le PGCD calculé
	printf("PGCD %d\n", pgcd(x,y));
			
	return 0;
}

int pgcd(int x, int y)
{
	if(y == 0)
	{
		// On arrive avec un reste nul, on a donc notre plus grand dénominateur commun
		return x;
	}
	else 
	{
		return pgcd(y, x%y);
	}
}
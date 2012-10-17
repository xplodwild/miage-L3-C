/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - r�utilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Dessine un triangle rempli d'x �toiles au maximum
void triangle(int x);

int main(int argc, char* argv[])
{
	int x, ret = 0;
	
	// On lit le nombre max d'�toiles
	while (ret != 1)
	{
		printf("Nombre d'�toiles: ");
		ret = scanf("%d", &x);
		CLRBUF;
	}
	
	// Dessine le triangle
	triangle(x);
			
	return 0;
}

void triangle(int x)
{
	int i = 0;
	
	// Pour chaque ligne demand�e
	for (; i < x; i++)
	{
		int j = 0;
		
		// On dessine le nombre d'�toiles correspondant � la ligne en cours
		for (; j < i+1; j++)
		{
			printf("*");
		}
		
		printf("\n");
	}
}
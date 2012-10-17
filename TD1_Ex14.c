/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Dessine un triangle rempli d'x étoiles au maximum
void triangle(int x);

int main(int argc, char* argv[])
{
	int x, ret = 0;
	
	// On lit le nombre max d'étoiles
	while (ret != 1)
	{
		printf("Nombre d'étoiles: ");
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
	
	// Pour chaque ligne demandée
	for (; i < x; i++)
	{
		int j = 0;
		
		// On dessine le nombre d'étoiles correspondant à la ligne en cours
		for (; j < i+1; j++)
		{
			printf("*");
		}
		
		printf("\n");
	}
}
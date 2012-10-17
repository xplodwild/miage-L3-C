/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule le nombre de résultats pour un polynome de 2ème degré (ax2+bx+c)
int resultats(int a, int b, int c);

int main(int argc, char* argv[])
{
	int a, b, c, ret = 0;
	
	// On lis les 3 valeurs
	while (ret != 1)
	{
		printf("a: ");
		ret = scanf("%d", &a);
		CLRBUF;
	}
	
	ret = 0;
	while (ret != 1)
	{
		printf("b: ");
		ret = scanf("%d", &b);
		CLRBUF;
	}
	
	ret = 0;
	while (ret != 1)
	{
		printf("c: ");
		ret = scanf("%d", &c);
		CLRBUF;
	}
	
	// On calcule et affiche le résultat
	printf("Il y a %d résultats possibles\n", resultats(a,b,c));
	
	return 0;
}

int resultats(int a, int b, int c)
{
	int delta;
	
	// delta = b2-4ac
	delta = b*b - 4*a*c;
	
	// Si le delta est négatif, il n'y a aucun résultat.
	// Si le delta est nul, il y a un résultat
	// Si le delta est positif, il y a 2 résultats
	if (delta < 0)
		return 0;
	else if (delta == 0)
		return 1;
	else
		return 2;
}
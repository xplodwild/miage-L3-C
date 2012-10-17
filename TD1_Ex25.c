/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Affiche un tableau d'entiers
void afficheTabEntiers(int* p, int len);

int main(int argc, char* argv[])
{
	int ret = 0, i = 0;
	int nbVal,curVal = 0;
	int* tab = 0;
	
	// On lit le nombre de valeurs que l'utilisateur souhaite rentrer
	// Note: On pourrait aussi ne pas le lire et réserver une valeur (0 par exemple) en tant que fin,
	// ou bien spécifier qu'une valeur erronée indique la fin de la suite. Le tableau serait réalloué par realloc.
	while (ret != 1)
	{
		printf("Entrez le nombre de valeurs: ");
		ret = scanf("%d", &nbVal);
		CLRBUF;
	}
	
	// On alloue le tableau
	tab = (int*)malloc(sizeof(int) * nbVal);
	
	// On lis les valeurs
	for (i = 0; i < nbVal; i++)
	{
		ret = 0;
		while (ret != 1)
		{
			printf("Valeur #%d: ", (i+1));
			ret = scanf("%d", &tab[i]);
			CLRBUF;
		}
	}
	
	// On calcule et affiche le résultat
	printf("Valeur entrées:\n");
	afficheTabEntiers(tab, nbVal);
	
	free(tab);
	
	return 0;
}

void afficheTabEntiers(int* p, int len)
{
	int i = 0;
	
	for (; i < len; i++)
	{
		printf("Case %d: %d\n", i, p[i]);
	}
}
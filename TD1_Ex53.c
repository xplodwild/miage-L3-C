/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

int* faisTableau(int n, ...);

int main(int argc, char* argv[])
{
	int i = 0;
	
	// On créée le tableau à partir des arguments
	int* tableau = faisTableau(5, 1, 2, 3, 4, 5);
	
	// On affiche le tableau créé
	for (i = 0; i < 5; i++) {
		printf("%d\n", *tableau++);
	}

	return 0;
}

int* faisTableau(int n, ...)
{
	int i=0,j=n,c=0;
	
	// On alloue le tableau
	int* tabFinal = (int*)malloc(sizeof(int) * n);
	
	// On garde un pointeur vers la première valeur
	int* tabPremier = tabFinal;
	
	// On démarre le parcours
	va_list ap;
	va_start(ap,n);
	
	while (i < j)
	{
		// On lis l'argument
		c=va_arg(ap,int);
		
		// On le met dans le tableau
		(*tabFinal++) = c;
		
		i++;
	}
	
	// On efface la liste
	va_end(ap);
	
	return tabPremier;
}

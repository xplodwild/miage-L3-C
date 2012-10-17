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

// Structure de liste
struct Tlist
{
	int nb;
	struct Tlist* next;
};

struct Tlist* faisListe(int n, ...);

void afficheListe(struct Tlist* liste)
{
	while (liste)
	{
		printf("%d ", liste->nb);
		liste = liste->next;
	}
}

int main(int argc, char* argv[])
{
	int i = 0;
	
	// On créée la liste à partir des arguments
	struct Tlist* liste = faisListe(5, 1, 2, 3, 4, 5);
	
	// On affiche la liste
	afficheListe(liste);
	
	return 0;
}

struct Tlist* faisListe(int n, ...)
{
	int i=0,j=n,c=0;
	
	// On alloue la liste
	struct Tlist* last = NULL;
	
	// On garde un pointeur vers la première valeur
	struct Tlist* first = last;
	
	// On démarre le parcours
	va_list ap;
	va_start(ap,n);
	
	while (i < j)
	{
		// On lis l'argument
		c=va_arg(ap,int);
		
		// On ajoute la valeur à la liste
		if (last == NULL)
		{
			last = (struct Tlist*)malloc(sizeof(struct Tlist));
			first = last;
		} 
		else
		{
			last = last->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		}
		
		last->nb = c;
		last->next = 0;
		
				
		i++;
	}
	
	// On efface la liste
	va_end(ap);
	
	return first;
}

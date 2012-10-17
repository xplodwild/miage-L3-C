/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - r�utilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Structure de liste
struct Tlist
{
	int nb;
	struct Tlist* next;
};

// Lib�re la m�moire occup�e par la liste
void free_list(struct Tlist* liste);

int main(int argc, char* argv[])
{
	int ret = 0, val = -1;
	
	// On d�clare la t�te de liste
	struct Tlist* head = (struct Tlist*)malloc(sizeof(struct Tlist));
	
	// Le dernier element en traitement
	struct Tlist* last = head;
	head->nb = 0;
	head->next = 0;
	
	// Tant qu'on entre pas 0
	while (val != 0)
	{
		// On lit une valeur
		ret = 0;
		while (ret != 1)
		{
			printf("Entrez des nombres (0 = stop): ");
			ret = scanf("%d", &val);
			CLRBUF;
		}
		
		// On ajoute la valeur � la liste
		last = last->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		last->nb = val;
		last->next = 0;
	}
	
	// On lib�re la m�moire
	free_list(head);
	printf("\n");
	
	return 0;
}


void free_list(struct Tlist* liste)
{
	struct Tlist* elem = 0;
	
	while (liste)
	{
		elem = liste;
		liste = liste->next;
		free(elem);
	}
}
/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
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

// Supprime le dernier élément de la liste
struct Tlist* list_remove_last(struct Tlist* liste);

int main(int argc, char* argv[])
{
	int ret = 0, val = -1;
	
	// On déclare la tête de liste
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
		
		// On ajoute la valeur à la liste
		last = last->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		last->nb = val;
		last->next = 0;
	}
	
	// On supprime le dernier
	list_remove_last(head);
	
	return 0;
}


struct Tlist* list_remove_last(struct Tlist* liste)
{
	struct Tlist* head = liste;
	struct Tlist* prev = head;
	
	while (liste->next)
	{
		// Si on a plus d'élément suivant, on est à la fin.
		if (!liste->next)
			break;
		
		prev = liste;
		liste = liste->next;
	}

	// On supprime le dernier élément et on supprime la référence dans l'élément précédent.
	free(prev->next);
	prev->next = NULL;

	return head;
}
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

// Renvoie une liste qui concatène 
struct Tlist* list_concat(struct Tlist* liste1, struct Tlist* liste2);

// Affiche une liste
void list_print(struct Tlist* liste);

int main(int argc, char* argv[])
{
	int ret = 0, val = -1;
	
	// On déclare la tête de liste
	struct Tlist* head = (struct Tlist*)malloc(sizeof(struct Tlist));
	
		
	return 0;
}

void list_print(struct Tlist* liste)
{
	while (liste)
	{
		printf("%d ", liste->nb);
		liste = liste->next;
	}
}


struct Tlist* list_concat(struct Tlist* liste1, struct Tlist* liste2)
{
	struct Tlist* head = NULL;
	struct Tlist* elem = NULL;
		
	while (liste1->next)
	{
		if (head == NULL)
		{
			head = (struct Tlist*)malloc(sizeof(struct Tlist));
			head->nb = liste1->nb;
			head->next = NULL;
			elem = head;
		}
		else
		{
			elem->next = (struct Tlist*)malloc(sizeof(struct Tlist));
			elem = elem->next;
			elem->nb = liste1->nb;
			elem->next = NULL;
		}

		liste1 = liste1->next;
	}
	
	while (liste2->next)
	{
		if (head == NULL)
		{
			head = (struct Tlist*)malloc(sizeof(struct Tlist));
			head->nb = liste2->nb;
			head->next = NULL;
			elem = head;
		}
		else
		{
			elem->next = (struct Tlist*)malloc(sizeof(struct Tlist));
			elem = elem->next;
			elem->nb = liste2->nb;
			elem->next = NULL;
		}

		liste2 = liste2->next;
	}
		
	return head;
}
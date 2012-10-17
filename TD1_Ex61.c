/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Structure de liste
struct Tlist
{
	int nb;
	struct Tlist* next;
};

// Filtre la liste
struct Tlist* list_filter(struct Tlist* liste, int(*g)(struct Tlist* element))
{
	struct Tlist* new_list = NULL;
	struct Tlist* head_new_list = new_list;
	
	while (liste->next)
	{
		if (((*g)(liste)) > 0)
		{
			if (new_list == NULL)
			{
				new_list = (struct Tlist*)malloc(sizeof(struct Tlist));
				head_new_list = new_list;
			}
			else
			{
				new_list = new_list->next = (struct Tlist*)malloc(sizeof(struct Tlist));
			}
			
			new_list->nb = liste->nb;
			new_list->next = NULL;
			
		}
		
		liste = liste->next;
	}
	
	return head_new_list;
}

// La fonction qui retourne 1 ou 0 si l'élément fait partie de la liste ou pas
int teh_func(struct Tlist* element)
{
	return (element->nb > 20);
}

// Affichage d'une liste
void afficheListe(struct Tlist* liste)
{
	while (liste)
	{
		printf("%d ", liste->nb);
		liste = liste->next;
	}
}

int main(int argc, char** argv)
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

	head = list_filter(head, teh_func);
	
	afficheListe(head);

	return EXIT_SUCCESS;
}

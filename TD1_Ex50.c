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

// Supprime la première occurence de "l" dans la liste
struct Tlist* list_remove_first(int l, struct Tlist* liste);

// Affiche une liste
void list_print(struct Tlist* liste);

int main(int argc, char* argv[])
{
	int ret = 0, val = -1;
	
	struct Tlist* soustraite = NULL;
	
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
			printf("Entrez des nombres TRIES (0 = stop): ");
			ret = scanf("%d", &val);
			CLRBUF;
		}
		
		// On ajoute la valeur à la liste
		last = last->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		last->nb = val;
		last->next = 0;
	}
	
	// On demande la valeur a supprimer
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez la valeur a supprimer: ");
		ret = scanf("%d", &val);
		CLRBUF;
	}
	
	// On filtre la liste
	soustraite = list_remove_first(val, head);
	
	// On l'affiche
	printf("Liste finale: \n");
	list_print(soustraite);
	printf("\n");	
	
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


struct Tlist* list_remove_first(int l, struct Tlist* liste)
{
	struct Tlist* head = liste;
	struct Tlist* prec = NULL;
		
	while (liste->next)
	{
		if (liste->nb == l)
		{
			if (prec == NULL)
			{
				return liste->next;
			}
			else
			{
				prec->next = liste->next;
				free(liste);
			}
		}
				
		prec = liste;
		liste = liste->next;
	}
		
	return head;
}


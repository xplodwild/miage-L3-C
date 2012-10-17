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

// Supprime les occurences de 0 dans la liste
struct Tlist* erase_0(struct Tlist* liste);

// Affiche le contenu d'une liste
void list_print(struct Tlist* liste);

int main(int argc, char* argv[])
{
	int ret = 0, val = -1;

	// On déclare la tête de liste
	struct Tlist* head = (struct Tlist*)malloc(sizeof(struct Tlist));
	
	// Le dernier element en traitement
	struct Tlist* last = head;
	head->nb = 0;
	head->next = 0;
	
	// Tant qu'on entre pas 1
	while (val != 1)
	{
		// On lit une valeur
		ret = 0;
		while (ret != 1)
		{
			printf("Entrez des nombres (1 = stop): ");
			ret = scanf("%d", &val);
			CLRBUF;
		}
		
		// On ajoute la valeur à la liste
		last = last->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		last->nb = val;
		last->next = 0;
	}
	
	
	
	list_print(erase_0(head));
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

struct Tlist* erase_0(struct Tlist* liste)
{
	struct Tlist* head = liste;
	struct Tlist* prec = NULL;
	
	while (liste)
	{
		if (liste->nb == 0)
		{	
			if (!prec)
			{
				prec = liste;
				liste = liste->next;
				head = liste;
				free(prec);
			}
			else
			{
				prec->next = liste->next;	
				free(liste);
				liste = prec;
			}
		}
		
		prec = liste;
		liste = liste->next;
	}	
	
	printf("done erase\n");
	return head;
}
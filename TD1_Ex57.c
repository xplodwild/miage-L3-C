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

// Affichage d'une liste
void afficheListe(struct Tlist* liste)
{
	while (liste)
	{
		printf("%d ", liste->nb);
		liste = liste->next;
	}
}

// Fonction de comparaison
int compare(void const *a, void const *b)
{
	printf("Sorting value…\n");
   // On caste les void* en Tlist*
   struct Tlist** pa = a;
   struct Tlist** pb = b;
   
   printf("Value: pa: %d, pb: %d\n", (*pa)->nb, (*pb)->nb);

   // Et on évalue pour calculer
   return (*pa)->nb - (*pb)->nb;
}

// Tri de la liste
struct Tlist* liste_tri(struct Tlist* liste)
{
	struct Tlist** tabElements = (struct Tlist*)malloc(sizeof(struct Tlist*));
	struct Tlist* elem = liste;
	int count = 0, i =0;
	
	printf("Alloc done\n");
	
	// On passe les éléments de la liste tel un tableau
	while (elem->next)
	{
		tabElements[count] = elem;
		elem = elem->next;
		count++;
		
		printf("Tab idx %d: %d (%p)\n", count, elem->nb, elem);
	}
	
	// On trie la liste
	qsort(tabElements, count, sizeof(struct Tlist**), compare);
	
	printf("Done sorting\n");
	
	// On recréé une liste dans l'ordre
	struct Tlist* finale = NULL;
	struct Tlist* head = finale;
	
	for (; i < count; i++)
	{
		printf("Recreating element %d… Tab pointer: %p\n", i, tabElements[i]);
		
		if (tabElements[i] == NULL)
		{
			continue;
		}
		
		if (finale == NULL)
		{
			finale = (struct Tlist*)malloc(sizeof(struct Tlist));
			head = finale;
		}
		else
		{
			finale = finale->next = (struct Tlist*)malloc(sizeof(struct Tlist));
		}
		
		finale->nb = tabElements[i]->nb;
		finale->next = NULL;
	}
	
	
	return head;
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
	
	// On trie la liste
	head = liste_tri(head);

	// On affiche
	afficheListe(head);
	
   	return 0;
}

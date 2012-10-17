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

// Renvoie la longueur de la liste
int list_count(int nb, struct Tlist* liste);

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
	
	// On recherche une valeur
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez la valeur a chercher: ");
		ret = scanf("%d", &val);
		CLRBUF;
	}
	
	// On calcule et affiche le nombre d'éléments
	printf("La liste contient '%d' %d fois", val, list_count(val, head));
	printf("\n");
	
	return 0;
}


int list_count(int nb, struct Tlist* liste)
{
	int count = 0;
	
	while (liste)
	{
		if (liste->nb == nb)
			count++;
			
		liste = liste->next;
	}
		
	return count;
}
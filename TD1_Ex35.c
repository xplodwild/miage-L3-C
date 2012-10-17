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

// Calcule la valeur max d'un tableau
int* add_tab(int* tab, int size, int elmt);

int afficheTab(int* tab, int size);

int main(int argc, char* argv[])
{
	int ret = 0, val = 0, i = 0;
	int* tab = (int*)malloc(sizeof(int) * 10);
	int* tab_modif = 0;
	
	// On ouvre le fichier
	FILE* file = fopen ("tenvalues.txt", "r");
	
	// Vérifie si il est bien ouvert
	if (!file)
	{
		printf("Impossible d'ouvrir 'tenvalues.txt' !");
		exit(-1);
	}
	
	// On lit chaque ligne
	while (!feof(file))
	{
		ret = fscanf(file, "%d", &val);
		
		// Si fscanf n'est pas valide, ou si on est aux bornes de notre tableau, on s'arrête.
		if (ret != 1 || i == 10)
			break;
		
		// Sinon on assigne la valeur dans notre tableau
		tab[i++] = val;
	}
	
	// On ferme le fichier
	fclose(file);
	
	// On demande la valeur à ajouter
	ret = 0;
	while (ret != 1)
	{
		printf("Valeur a ajouter: ");
		ret = scanf("%d", &val);
		CLRBUF;
	}
	
	// On ajoute la valeur
	tab_modif = add_tab(tab, 10, val);
	
	// On affiche les tableaux
	printf("Original: \n");
	afficheTab(tab, 10);
	
	printf("\nModif: \n");
	afficheTab(tab_modif, 11);
	printf("\n");
	
	// On libère la mémoire
	free(tab);
	free(tab_modif);
	
	return 0;
}

int* add_tab(int* tab, int size, int elmt)
{
	int i = 0, elem_put = 0;
	
	// On alloue un nouveau tableau avec une case en plus
	int* new_tab = malloc(sizeof(int) * (size + 1));
	
	// On récupère un pointeur vers le premier élément
	int* ptr_tab = new_tab;
	
	// On recopie chaque élément, en placant si nécessaire le nouvel élément au bon endroit
	for (; i < size; i++)
	{
		if (!elem_put && elmt < tab[i])
		{
			(*ptr_tab++) = elmt;
			elem_put = 1;
		}
		
		(*ptr_tab++) = tab[i];
	}
	
	// Si l'élement est plus grand que n'importe quel élément du tableau, on le place
	// à la fin.
	if (!elem_put)
		(*ptr_tab++) = elmt;
	
	return new_tab;
}

int afficheTab(int* tab, int size)
{
	int j = 0;
	for (; j < size; j++)
		printf("%d ", tab[j]);
}
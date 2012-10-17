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

// Calcule la valeur max d'un tableau
int max_tab(int* tab, int size);

int main(int argc, char* argv[])
{
	int ret = 0, val = 0, i = 0;
	int tab[10];
	
	// On ouvre le fichier
	FILE* file = fopen ("tenvalues.txt", "r");
	
	// V�rifie si il est bien ouvert
	if (!file)
	{
		printf("Impossible d'ouvrir 'tenvalues.txt' !");
		exit(-1);
	}
	
	// On lit chaque ligne
	while (!feof(file))
	{
		ret = fscanf(file, "%d", &val);
		
		// Si fscanf n'est pas valide, ou si on est aux bornes de notre tableau, on s'arr�te.
		if (ret != 1 || i == 10)
			break;
		
		// Sinon on assigne la valeur dans notre tableau
		tab[i] = val;
	}
	
	// On ferme le fichier
	fclose(file);
	
	// On calcule et affiche la valeur max
	printf("Max: %d\n", max_tab(tab, 10));
	
	return 0;
}

int max_tab(int* tab, int size)
{
	int max = -2147483646, i = 0;
	
	// On parcourt le tableau et on garde uniquement la plus grande valeur
	for (; i < size; i++)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	
	return max;
}

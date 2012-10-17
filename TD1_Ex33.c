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

// Met les valeurs d'une matrice au carré
void carreMatrice(int* tab, int x, int y);

// Affiche une matrice d'entiers
void afficheMatrice(int* tab, int x, int y);

int main(int argc, char* argv[])
{
	int ret = 0, val = 0, i = 0, j = 0;
	int tab[10][10];
	
	// On ouvre le fichier
	FILE* file = fopen ("matrice.txt", "r");
	
	// Vérifie si il est bien ouvert
	if (!file)
	{
		printf("Impossible d'ouvrir 'matrice.txt' !");
		exit(-1);
	}
	
	// On lit chaque valeur
	while (!feof(file))
	{
		ret = fscanf(file, "%d", &val);
		
		// Si fscanf n'est pas valide, ou si on est aux bornes de notre matrice, on s'arrête.
		if (ret != 1)
			continue;
		if (i == 10)
			break;
		
		// Sinon on assigne la valeur dans notre tableau
		tab[i][j++] = val;
		
		if (j == 10)
		{
			j = 0;
			i++;
		}
	}
	
	// On ferme le fichier
	fclose(file);
	
	// On calcule et affiche la matrice
	carreMatrice(&tab[0][0], 10, 10);
	afficheMatrice(&tab[0][0], 10, 10);
	
	return 0;
}

void carreMatrice(int* tab, int x, int y)
{
	int i = 0, j = 0;
	
	// On multiplie par elle-même chaque valeur
	for (; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			(*tab++) *= (*tab);
		}
	}
}

void afficheMatrice(int* tab, int x, int y)
{
	int i = 0, j = 0;
	
	for (; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", (*tab++));
		}
		printf("\n");
	}
}

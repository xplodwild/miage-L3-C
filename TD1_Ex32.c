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

// Calcule la moyenne des valeurs d'un tableau d'entiers
int moyenneTab(int* tab, int len);

int main(int argc, char* argv[])
{
	int ret = 0, val = 0, i = 0;
	int tab[10];
	
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
		tab[i] = val;
	}
	
	// On ferme le fichier
	fclose(file);
	
	// On calcule et affiche la moyenne
	printf("Moyenne: %d\n", moyenneTab(tab, 10));
	
	return 0;
}

int moyenneTab(int* tab, int len)
{
	int somme = 0, i = 0;
	
	// On calcule la somme
	for (; i < len; i++)
		somme += tab[i];
	
	// Puis la moyenne en divisant la somme par le nombre de valeurs
	return somme/len;
}

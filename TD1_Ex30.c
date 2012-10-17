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

// Retourne le nombre de fois o� une occurence apparait dans une chaine
int occurences(char* chaine, char* mot);

int main(int argc, char* argv[])
{
	int ret = 0;
	char chaine[255];
	char mot[255];
	
	// On lis la chaine
	while (ret != 1)
	{
		printf("Entrez une chaine: ");
		ret = scanf("%254s", chaine);
		CLRBUF;
	}
	
	// On lis le mot
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez un mot: ");
		ret = scanf("%254s", mot);
		CLRBUF;
	}
	
	// On calcule et affiche le r�sultat
	printf("Il y a %d fois '%s' dans '%s'.\n", occurences(chaine,mot), mot, chaine);
	
	return 0;
}

int occurences(char* chaine, char* mot)
{
	int count = 0, curr_occ_valid = 0,
		i = 0, j = 0,
		ch_size = strlen(chaine),
		wd_size = strlen(mot);
	
	// Pour chaque caract�re de la chaine compl�te
	for (; i < ch_size; i++)
	{
		// On part du principe que en partant du caract�re en cours, on a une occurence
		curr_occ_valid = 1;
		
		for (j = 0; j < wd_size; j++)
		{
			// On part donc du caract�re en cours, et on le compare au mot.
			if (chaine[i+j] != mot[j])
			{
				// On a une lettre qui diff�re, on n'a donc pas d'occurence � cet index, on passe � la suite
				curr_occ_valid = 0;
				break;
			}
		}
		
		// Les lettres correspondent, on a une occurrence
		if (curr_occ_valid)
			count++;
	}
	
	return count;
}

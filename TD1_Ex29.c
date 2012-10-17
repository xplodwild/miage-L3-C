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

// Retourne si une chaine est un palindrome (oui=1 non=0)
int palindrome(char* chaine);

int main(int argc, char* argv[])
{
	int ret = 0;
	char chaine[255];
	
	// On lis la chaine
	while (ret != 1)
	{
		printf("Entrez un mot: ");
		ret = scanf("%254s", chaine);
		CLRBUF;
	}
	
	// On calcule et affiche le résultat
	printf("%s %s un palindrome.\n", chaine, palindrome(chaine) ? "est" : "n'est pas");
	
	return 0;
}

int palindrome(char* chaine)
{
	int size = strlen(chaine);
	int i = 0;

	// Pour chaque caractère jusqu'au milieu
	for (; i < size/2; ++i)
	{
		// Si le caractère à l'opposé de la chaine est différent, ce n'est pas un palindrome
		if (chaine[i] != chaine[size-i-1])
			return 0; 
	} 
	
	return 1;
}

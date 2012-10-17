/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule la longueur d'une chaine
int my_strlen(char* chaine);

// Copie une chaine
void my_strcpy(char* src, char* dest);

// Compare 2 chaines
int my_strcmp(char* chaine1, char* chaine2);

int main(int argc, char* argv[])
{
	int ret = 0;
	char chaine[255];
	char chaineCopie[255];
	char chaineAutre[255];
	
	// On lis une première chaine, dont on va calculer la longueur puis copier
	while (ret != 1)
	{
		printf("Entrez une chaine: ");
		ret = scanf("%254s", chaine);
		CLRBUF;
	}
	
	// On affiche la longueur avec notre fonction
	printf("Longueur: %d\n", my_strlen(chaine));
	
	// On copie la chaine dans chaineCopie avec notre fonction
	my_strcpy(chaine, chaineCopie);
	
	// On affiche la chaine copiée pour vérification
	printf("Chaine copiee: %s\n", chaineCopie);
	
	// On demande une seconde chaine à l'utilisateur pour tester la comparaison
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez une autre chaine: ");
		ret = scanf("%254s", chaineAutre);
		CLRBUF;
	}
	
	// On affiche le résultat de la comparaison
	printf("Comparaison: %d\n", my_strcmp(chaine, chaineAutre));
	
	return 0;
}

int my_strlen(char* chaine)
{
	int size = 0;
	
	// on parcourt chaque caractère de la chaine jusqu'à trouver le caractère de fin de chaine
	while ((*chaine++) != '\0')
		size++;
		
	return size;
}

void my_strcpy(char* src, char* dest)
{
	// Tant qu'on est pas à la fin de la chaine, on copie le caractère
	while ((*src) != '\0')
		(*dest++) = (*src++);
		
	// Puisqu'on s'arrête sur le caractère de fin de chaine, on le rajoute manuellement à la destination.
	(*dest++) = '\0';
}

int my_strcmp(char* chaine1, char* chaine2)
{
	// On saute les caractères tant qu'ils sont similaires et qu'on n'est pas à la fin
	while ((*chaine1) != '\0' && (*chaine2) != '\0' && (*chaine1++) == (*chaine2++));
	
	// On est arrivé après le premier caractère différent, on revient en arrière pour donner la différence
	chaine1--;
	chaine2--;
	
	return (*chaine1) - (*chaine2);
}
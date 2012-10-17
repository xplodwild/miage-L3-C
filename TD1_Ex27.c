/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - r�utilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Ajoute la chaine "appendix" apr�s les caract�res de la chaine "chaine" (version pointeurs)
void my_strcat_ptr(char* chaine, char* appendix);

// Ajoute la chaine "appendix" apr�s les caract�res de la chaine "chaine" (version tableaux)
void my_strcat_tab(char* chaine, char* appendix);

// Copie une chaine (cf. ex26)
void my_strcpy(char* src, char* dest);

int main(int argc, char* argv[])
{
	int ret = 0;
	char chaine[255];
	char chaineCopie[255];
	char append[255];
	
	// On lis les deux chaines
	while (ret != 1)
	{
		printf("Entrez un mot: ");
		ret = scanf("%254s", chaine);
		CLRBUF;
	}
	
	// On garde une copie de la chaine initiale pour pouvoir utiliser nos deux fonctions avec la m�me chaine
	my_strcpy(chaine, chaineCopie);
	
	ret = 0;
	while (ret != 1)
	{
		printf("Entrez un mot a concatener: ");
		ret = scanf("%254s", append);
		CLRBUF;
	}
	
	// On concat�ne une premi�re fois avec la m�thode aux pointeurs
	my_strcat_ptr(chaine,append);
	printf("Resultat (pointeur): %s\n", chaine);
	
	// Puis avec des tableaux
	my_strcat_tab(chaineCopie,append);
	printf("Resultat (tableau): %s\n", chaineCopie);
	
	return 0;
}

void my_strcat_ptr(char* chaine, char* appendix)
{
	// On va a la fin de la chaine initiale
	while ((*chaine++) != '\0');
	
	// On revient avant le caract�re \0
	chaine--;
	
	// On ajoute les caract�res � ajouter � la chaine
	while (*appendix != '\0')
		(*chaine++) = (*appendix++);
		
	// On termine la cahine
	(*chaine) = '\0';
}

void my_strcat_tab(char* chaine, char* appendix)
{
	int i = 0, j = 0;
	
	// On va a la fin de la chaine initiale
	while (chaine[i] != '\0')
		i++;
	
	// On ajoute les caract�res � ajouter � la chaine
	while (appendix[j] != '\0')
		chaine[i++] = appendix[j++];
		
	// On termine la cahine
	chaine[i] = '\0';
}

void my_strcpy(char* src, char* dest)
{
	// Tant qu'on est pas � la fin de la chaine, on copie le caract�re
	while ((*src) != '\0')
		(*dest++) = (*src++);
		
	// Puisqu'on s'arr�te sur le caract�re de fin de chaine, on le rajoute manuellement � la destination.
	(*dest++) = '\0';
}

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

// Retourne si une chaine est carr�e (ex. bonbon / chercher) ou pas (oui=1 non=0)
int chaineCarree(char* chaine);

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
	
	// On calcule et affiche le r�sultat
	printf("%s %s un carre.\n", chaine, chaineCarree(chaine) ? "est" : "n'est pas");
	
	return 0;
}

int chaineCarree(char* chaine)
{
	int size = strlen(chaine);
	int gauche = 0, droite = 0;
	
	// Une chaine carr�e a forc�ment un nombre pair de caract�res. On s'arr�te tout de suite
	// si ce n'est pas la cas.
	if (size % 2 != 0)
		return 0;
	
	// On place notre deuxi�me curseur � la moiti� de la chaine
	droite = size/2;
	
	// On lit chaque caract�re de la chaine avec nos deux pointeurs tant que les caract�res sont
	// identiques
	while (chaine[gauche++] == chaine[droite++] && chaine[droite] != '\0');
	
	// Si la chaine est carr�e, cela signifie que notre pointeur gauche est arriv� au milieu (point de
	// d�part du pointeur de droite)
	return (gauche == size/2);
}

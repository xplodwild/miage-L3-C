/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Affichage d'un tableau
void affiche_tableau(int *a, size_t n)
{
   size_t i;
   for (i = 0; i < n; i++)
   {
      printf ("%d\n", a[i]);
   }
   printf ("\n");
}

// Fonction de comparaison
int compare(void const *a, void const *b)
{
   // On caste les void* en int*
   int const *pa = a;
   int const *pb = b;

   // Et on évalue pour calculer
   return *pa - *pb;
}

int main(int argc, char** argv)
{
	// Tableau à trier
   	int tab[] = { 4, 6, -3, 4, 7 };

   	// Tri
   	qsort(tab, 5, sizeof(int), compare);

	// On affiche le tableau après le tri
   	affiche_tableau(tab, 5);

   	return 0;
}
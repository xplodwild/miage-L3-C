/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule le nombre de solutions d'un polynome du second degré dans n, et donne les solutions éventuelles dans x1 et x2
void exo24(float a, float b, float c, int* n, float* x1, float* x2);

// Calcule le nombre de résultats pour un polynome de 2ème degré (ax2+bx+c) et renvoie le delta dans delta -- Modifié de l'ex 10
int resultats(float a, float b, float c, float* delta);

int main(int argc, char* argv[])
{
	float a,b,c,x1,x2;
	int n, ret = 0;
	printf("Calcul des solutions d'un polynome du second degré (ax²+bx+c)\n");
	
	// On lit les 3 valeurs
	ret = 0;
	while (ret != 1)
	{
		printf("a=");
		ret = scanf("%f", &a);
		CLRBUF;
	}
	
	ret = 0;
	while (ret != 1)
	{
		printf("b=");
		ret = scanf("%f", &b);
		CLRBUF;
	}
	
	ret = 0;
	while (ret != 1)
	{
		printf("c=");
		ret = scanf("%f", &c);
		CLRBUF;
	}
	
	
	// On effectue le calcul
	exo24(a,b,c,&n,&x1,&x2);
	
	if (n == 0)
	{
		printf("Aucune solution.\n");
	}
	else if (n == 1)
	{
		printf("Une solution: %f\n", x1);
	}
	else
	{
		printf("Deux solutions: %f et %f\n", x1, x2);
	}
	
			
	return 0;
}

void exo24(float a, float b, float c, int* n, float* x1, float* x2)
{
	float delta;

	// On rappelle l'expression
	printf("Expression: %fx² + %fb + %f = 0\n", a, b, c);
	
	// On calcule le nombre de solutions
	*n = resultats(a,b,c,&delta);
	
	if (*n == 1)
	{
		// solution = -b/2a
		*x1 = -(b / 2 * a);
	}
	else if (*n > 1)
	{
		// ( -b +- sqrt(delta) ) / 2a
		*x1 = ( -b + sqrt(delta) ) / (2 * a);
		*x2 = ( -b - sqrt(delta) ) / (2 * a);
	}
}

int resultats(float a, float b, float c, float* delta)
{	
	// delta = b2-4ac
	*delta = b*b - 4*a*c;
	
	// Si le delta est négatif, il n'y a aucun résultat.
	// Si le delta est nul, il y a un résultat
	// Si le delta est positif, il y a 2 résultats
	if (*delta < 0)
		return 0;
	else if (*delta == 0)
		return 1;
	else
		return 2;
}
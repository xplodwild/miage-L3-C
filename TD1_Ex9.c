/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule l'harmonique au degré a
float harmonic(int a);

int main(int argc, char* argv[])
{
	int a, ret = 0;
	
	// Lis le degré
	while (ret != 1) {
		printf("Terme: ");
		ret = scanf("%d", &a);
		CLRBUF;
	}
	
	// Affiche l'harmonique demandée
	printf("%f\n", harmonic(a));
	
	return 0;
}

float harmonic(int a)
{
	float result = 1;
	int i = 0;
	
	// On calcule
	for (; i < a-1; i++) {
		result += 1.0f/(float)a;	
	}
	
	return result;
}
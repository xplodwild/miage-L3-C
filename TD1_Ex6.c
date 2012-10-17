#include <stdio.h>
#include <stdlib.h>

// Macro pour vider le buffer de scanf
#define CLRBUF { scanf("%*[^\n]"); getchar(); }

// Calcule la factorielle de "num"
int factorielle(int num);

int main(int argc, char* argv[])
{
	int factor = 0, ret = 0;
	
	// Lis le nombre � calculer
	while (ret != 1)
	{
		printf("Factorielle de: ");
		ret = scanf("%d", &factor);
		CLRBUF;
	}
	
	// Calcule et affiche le r�sultat
	printf("R�sultat: %d\n", factorielle(factor));
	
	return 0;
}

int factorielle(int num)
{
	int result = num;
	int i = num-1;
	
	// On part de la fin en d�cr�mentant le facteur � chaque fois pour calculer la factorielle
	for (; i > 0; i--)
	{
		result *= i;
	}
	
	return result;
}
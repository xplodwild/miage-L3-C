/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

float f(float(*g)(int), int a, int b)
{
	// somme a<=i<=b g(i)
	int x = a;
	float somme = 0;
	
	for (; x <= b; x++)
	{
		somme += (*g)(x);
	}
	
	return somme;
}


float teh_func(int i)
{
	return (float)i * 1.5f;	
}

int main(int argc, char** argv)
{
	printf("%f\n", f(teh_func, 1, 20));
	return EXIT_SUCCESS;
}
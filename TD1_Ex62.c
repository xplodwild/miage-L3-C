/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int i = 1;
	for (; i < argc; i++)
	{
		printf("%d: %s\n", i, argv[i]);	
	}	
	
	return EXIT_SUCCESS;
}
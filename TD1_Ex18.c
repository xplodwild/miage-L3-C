/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - réutilisation du code interdite
 */
/**
 * A la fin de l'exécution, 
 * a = 6
 * b = 10
 * pa pointera sur b
 * pb pointera sur b
 * pc pointera sur b
 
 */
 
int a=3;
int b=10;
int c, *pa, *pb, *pc;

pa = &a;  // pa vaudra la même valeur que a à tout instant du programme (et vice versa)
*pa = *pa * 2; // pa = a = 6
pb = &b; // pb vaudra la même valeur que b à tout instant du programme (et vice versa)
c = 3 * (*pb - *pa) // c = 3 * (b-a) = 3 * (10 - 6) = 3 * 4 = 12
pc = pb; // pc = pb = b
pa = pb; // pa = pb = pc = b
pb = pc; // pb = pc = b

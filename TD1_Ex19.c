/**
 * @author Guillaume Lesniak
 * https://github.com/xplodwild/miage-L3-C
 * Pour information uniquement - r�utilisation du code interdite
 */
/**
 * Le code est incorrect, car les cases d'un tableau commencent � 0 et non � 1. Du coup, p[10] est la 11�me case, or on n'alloue que 10 cases dans le malloc.
 * De plus, le tableau n'est pas lib�r� (free)
 */
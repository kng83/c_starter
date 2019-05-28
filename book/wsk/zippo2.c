
/* zippo2.c -- informacje o zippo poprzez zmienna wskaznikowa */
#include <stdio.h>
int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int(*pz)[2];
    pz = zippo;
    printf(" pz = %p, pz + 1 = %p\n",
           pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
           pz[0], pz[0] + 1);
    printf(" *pz = %p, *pz + 1 = %p\n",
           *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf(" *pz[0] = %d\n", *pz[0]);
    printf(" **pz = %d\n", **pz);
    printf(" pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
    return 0;
}
/*
 zippo = 0x0064fd38, zippo + 1 = 0x0064fd40
 zippo[0] = 0x0064fd38, zippo[0] + 1 = 0x0064fd3c
 *zippo = 0x0064fd38, *zippo + 1 = 0x0064fd3c
 zippo[0][0] = 2
 *zippo[0] = 2
 **zippo = 2
 zippo[2][1] = 3
*(*(zippo+2) + 1) = 3
*/

//int (* wz)[2]; // wz wskazuje do tablicy dwóch elementów typu int
//int * pax[2]; // pax to tablica dwoch wskaznikow do int
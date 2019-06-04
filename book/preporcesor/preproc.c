/* preproc.c -- proste przyklady uzycia preprocesora */
#include <stdio.h>
#define DWA 2                     /* mozna korzystac z komentarzy */
#define OW "Konsekwencja jest ostatnim schronieniem ludzi pozba\
wionych fantazji.\n- Oscar Wilde" /* lewy ukosnik przenosi definicje */
/* do nastepnego wiersza */
#define CZTERY DWA *DWA
#define PX printf("X wynosi %d.\n", x)
#define FMT "X wynosi %d.\n"
#define KWADR(Y) Y*Y
#define INC(Z)(++(Z))
#define PKW(x) printf("\nKwadratem " #x " jest %d.\n",((x)*(x))) //x w cudzyslowie to ta liczba

int main(void)
{
    int x = DWA,k=3;
    PX;
    x = CZTERY;
    PX;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("DWA: OW\n");
    printf("\nwartosc kwadratu X=%d",KWADR(4));
    printf("\ninkrementacja %d",INC(k));
    PKW(100);
    return 0;
}
#include <stdio.h>

void go_south_east(int *,int*);
int ship_main();

int main()
{
    int x = 4;

    printf("adres zmiennej x to %p", &x);
    ship_main();
}

void go_south_east(int *lat, int *lon)
{
    *lat = *lat - 1;
    *lon = *lon + 1;
    printf("\nto jest %i i %i",*lat,*lon);
}

int ship_main()
{
    int latitude = 32;
    int longitude = -64;

    go_south_east(&latitude,&longitude);
    printf("\nStop aktualne polozenie to: [%i,%i]\n", latitude, longitude);
    
    char info[20] = "lampart";
    int some = sizeof("lampa");
    int * koko;
    printf("Some is %i i %i i typ danych %i i wskaznik do int %i", some,sizeof(info),sizeof(int),sizeof(*koko)); //6 i 20

    //Sprawdzenie jaki system 4bajty to 32 8 to 64

    char s[]= "Jestem dlugim ciagiem znakow";
    char *t =s;


    printf("\nto jest s %i a to t %i", sizeof(s),sizeof(t));

    //Tu jest ciekawy dostep do tablicy
    int doses[] ={1,3,2,1000};
    printf("\nZaplikuj dawke %i and %i and %i",3[doses],doses[3], *(doses+2));

    return 0;
}
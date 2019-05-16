#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const int Ilosc_Liczb =3;
int main(){
    
    int wynik[Ilosc_Liczb];
    int suma =0;
    printf("podaje liczbe numerow do sredniej");
    for(int index=0;index<Ilosc_Liczb;index++){
        scanf("%d",&wynik[index]);
    }

    //srednia
    for(int i=0;i<Ilosc_Liczb;i++){
        suma+=wynik[i];
    }
    printf("Srednia to %f",(float)suma/(float)Ilosc_Liczb);

}
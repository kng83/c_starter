#include<stdio.h>
int main(){
 unsigned short int kon =4;
    printf("\nto jes dlugosc kon %i",sizeof(kon));
    char alpha = 'A';
    printf("\n size of alpha %i",sizeof(alpha));
    float piotrek = 10.0;
    printf("\n typ float wartosc to %d",sizeof(piotrek));
    long long dar = 10.0;
    printf("\n typ long long wartosc to %d",sizeof(dar));
    long  pojlong = 10.0;
    printf("\n typ poj long wartosc to %d",sizeof(pojlong));
    double  doub = 10.0;
    printf("\n typ double wartosc to %d",sizeof(doub));
    printf("\n callin some funciton %c",goSomeWhere());
    printf("\n %d %d %d",4,3);

//tu mamy floata zaokroglonego do 3 miejsc po przecinku;
    float ryba =10.134132;
    printf("\n to jes %.3f",ryba);
}
 
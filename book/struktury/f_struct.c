/* fund2.c -- przekazywanie wskaznika do struktury */
#include <stdio.h>
#define FUNDDL 50
struct fundusze
{
    char bank[FUNDDL];
    double bankfund;
    char oszcz[FUNDDL];
    double oszczfund;
};
double suma(const struct fundusze *); /* argument jest wskaznikiem */
double addMoney(struct fundusze mamona); /*argument jest struktura */
int main(void)
{
    struct fundusze edek = {
        "Bank Czosnkowo-Melonowy",
        2024.72,
        "Kasa Oszczednosciowo-Pozyczkowa \"Debet\"",
        8237.11};
    //zeby dobrac sie do struktury potrzebujemy jej adres
    printf("Edek posiada w sumie %.2f zl.\n", suma(&edek));
    printf("Edek posiada w sumie %.2f zl.\n", addMoney(edek));
    return 0;
}
double suma(const struct fundusze * cash){
    return (cash->bankfund + cash->oszczfund);
}

//tu jest tworzona lokalna struktura
double addMoney(struct fundusze mamona){
 return(mamona.bankfund + mamona.oszczfund);
}
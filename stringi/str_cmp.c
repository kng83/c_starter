#include <stdio.h>
#include <string.h>

#define ans "kot"
void test_strcmp();
void test_strncmp();

int main()
{
    test_strncmp();
    return 0;
}

void test_strcmp(){
    char tab[40];
    puts("co to jest");
    gets(tab);
    while (strcmp(tab,ans)){
        puts("to zla odpowiedz.Jeszcze raz");
        gets(tab);
    }
    puts("OK");
}

//porownuje do ilosc miejsc
//mozna z tego zrobic wyszukiwanie w locie
void test_strncmp(){
    char tab[40];
    puts("co to jest");
    gets(tab);
    while (strncmp(tab,ans,3)){
        puts("to zla odpowiedz.Jeszcze raz");
        gets(tab);
    }
    puts("OK");

}
#include <stdio.h>
#include <string.h>

#define ans "kot"
void test_strcpy();
void test_strncpy();
void test_sprintf();

int main()
{
    test_strcpy();
    puts("\n");
    test_strncpy();
    test_sprintf();
    return 0;
}

void test_strcpy(){
   char  text[100] = "to jest duzy tekst";
   char text2[100];
   char *t2= text2;
   strcpy(t2,text);
   printf("%s\n",t2);
   text[0] ='Z'; //zmieniam original
   printf("%s\n",text);
   printf("%s\n",text2);
   
}

//porownuje do ilosc miejsc
//mozna z tego zrobic wyszukiwanie w locie
void test_strncpy(){
   char  text[100] = "to jest duzy tekst";
   char text2[100];
   char *t2 = text2;
   strncpy(t2,text,20); //jest tu rozmiar
   printf("%s\n",t2);
   text[0] ='d'; //zmieniam original
   printf("%s\n",text);
   printf("%s\n",t2);

}

//do zampamietywania lancuchow
void test_sprintf(){
    char *imie = "kot";
    char *drugie ="bobo";
    char tab[20];
    sprintf(tab,"%s %s",imie,drugie); //laczy dwa stringi
    puts(tab);
}
/*To jest program z rodzialu pierwszego opisujacy wejscia wyjsca
* Jeżeli w windows chcesz sprawdzic error lever to wpisz echo %ErrorLevel%
*
*/

#include <stdio.h>

int main()
{

  int card_cout = 11;
  char podaj_imie[20];

  //  printf("Nowy tekst");
  printf("podaj liczbe\n");

  scanf("%i", &card_cout);
  printf("some text");

  printf("\nJest to liczba %i", card_cout);
  puts("\n--------------------------------");

  puts("\npodaj swoje imie");
  scanf("%s", &podaj_imie);
  printf("oto twoje imie %s", &podaj_imie);

  //Program karta
  char card_name[3];
  puts("\nWpisz symbol karty ");
  scanf("%2s", &card_name); //informacja ze 2 pierwsze znaki beda pobierane
  if (card_name[0] == 'Q')
  {
    puts("Goooooooooood");
    printf("\nFull card names is %s",&card_name);
  }
  else
  {
    puts("Baaaaaaaaaaaaad");
  }

  return 0;
}

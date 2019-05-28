//te funkcje sa rownowazne obie maja do piewszej kolumny wskazniki
//void pewnafunkcja( int (* wsk)[4] );
//void pewnafunkcja( int wsk[][4] );

//poniewaz tab jest wskaznikiem to kompilator nie wie ile ma miejsc przeskoczyc po inkrementacji
//o jeden w drugim przypadku przeskoczy o 4 x 4(int) =16 miejsc
//int sumuj2(int tab[][], int wiersze); // wadliwa deklaracja
//int sumuj2(int ar[][4], int wiersze); // poprawna deklaracja

//ten przypadek dla wielowymiarowej tablicy (pierwszy pusty bo i tak ignorowany bo to wskaznik);
//int sumuj4d(int tab[][12][20][30], int wiersze);
//bez nawiasow to bedzie tablica wskaznikow
//int sumuj4d(int (*tab)[12][20][30], int wiersze); // tab jako wskaznik (zapis rownowazny z wyzej)

// const float * pf; /* pf wskazuje na stala wartosc float*/
// float * const pt; /* pt jest stalym wskaznikiem*/
// const float * const ptr; //staly wskaznik do stalej wartosci
//float const * pfc === const float * pfc //rownowazne
/*  
słowo const, wstawione na lewo od * powoduje, że stałe stają się
dane, a const na prawo od * oznacza, że stały ma być wskaźnik.
*/


// int tab[10];
// int * restrict rest_tab = (int *) malloc(10 * sizeof(int));
// int * wtab = tab;
//wskaznik rest_tab ma wylaczny dostep do pamieci bo jest restrict pozwala to na optymalizacje
//kompilatora


// int byki; // zwyczajna deklaracja
// byki = 12; // zwyczajne przypisanie
// można zastąpić poniższym:
// _Atomic int byki; // deklaracja zmiennej o niepodzielnym dostępie
// atomic_store(&byki, 12); // przypisanie przez makrodefinicję z stdatomic.h
//stdatomic.h i threads.h. 


//void slownie(int * const a1, int * restrict a2, int n); // stary sposob
//void slownie(int a1[const], int a2[restrict], int n); // nowy sposob z C99
//drugi ten sam ale widac ze wartosc jest const a w drugim przypadku restrict

//Język C posiada kwalifikatory typu const, volatile i restrict. K
//W języku C zdefiniowano następujące klasy zmiennych:
//automatyczna, rejestrowa,statyczna bez lacznosci, statyczna z lacznoscia wew lub zew
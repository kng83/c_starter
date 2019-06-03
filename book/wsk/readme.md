<!-- 
int plansza[8][8]; // tablica tablic typu int
int ** wsk; // wskaznik do wskaznika do int
int * domy[10]; // 10-elementowa tablica wskaznikow do int
int (* tomy)[10]; // wskaznik do 10-elementowej tablicy typu int
int * uff[3][4]; // tablica 3 x 4 wskaznikow do int
int (* puff)[3][4]; // wskaznik do tablicy 3 x 4 wartosci int
int (* huff[3])[4]; // 3-elementowa tablica wskaznikow do
 // 4-elementowych tablic typu int


char * flip(int); // funkcja zwracajaca wskaźnik do char
char (* flap)(int); // wskaznik do funkcji, ktora zwraca  wartosc typu char
char (* flop[3])(int); // tablica 3 wskaznikow do funkcji


void DuzeLit(char *); // przetwarza male litery na duze
void (*wf)(char *); // wf jest wskaznikiem do funkcji
void *wf(char *); // wf jest funkcja, która zwraca wskaznik


//Jak wskaznik do funkcji
void DuzeLit(char *);
void MaleLit(char *);
int zaokr(double);
void (*wf)(char *);
wf = DuzeLit; // prawidlowe, DuzeLit jest adresem funkcji
wf = MaleLit; // prawidlowe, MaleLit jest adresem funkcji
wf = zaokr; // nieprawidlowe, zaokr jest funkcja niewlasciwego typu
wf = MaleLit(); // nieprawidlowe, MaleLit() nie jest adresem


//Dwie rownowazne metody wywolania funkcji
void DuzeLit(char *);
void MaleLit(char *);
void (*wf)(char *);
char mis[] = "Nina Metier";
wf = DuzeLit;
(*wf)(mis); /* stosuje funkcje DuzeLit do zmiennej mis (składnia 1) */
wf = MaleLit;
wf(mis); /* stosuje funkcje MaleLit do zmiennej mis (składnia 2) */
str 682

void pokaz(void (* fw)(char *), char * lan);
funckja ktorej pierwszym argumentem jest wskaznik do funkcji nastepnym tablica

// mozna jeszcze zrobic tablice wskaznikow do funkcji
typedef void (*V_WF_WCHAR)(char *);
void pokaz(V_WF_WCHAR wp, char *);
V_WF_WCHAR wfun;
//Pozniej taka deklaracja funckji
V_WF_WCHAR tabwf[4] = {DuzeLit, MaleLit, Odwroc, Atrapa};
str 683

//Prosty przyklad z wskanikiem do funkcji

#include <math.h> /* deklaruje double sin(double) */
...
double (*pdf)(double);
double x;
pdf = sin;
x = (*pdf)(1.2); // wywoluje sin(1.2)
x = pdf(1.2); // takze wywoluje sin(1.2)
...
 -->
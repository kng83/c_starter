#include <stdio.h>
#include <ctype.h>
#define TRIM ' '
#define FALSE 4>6

//mozna tak odczytac plik hello.exe < in.txt strumien z in do hello.ex
//a tak jest odwrotny strumien ktory  dziala co hello.exe > out.txt (tyloko dzila na nowym pliku);
//prawdopodobnie code go mieli
//a tak wyglad kopia pliku hello.exe <in.txt> kopia_in.txt
int main(){
    char ch;
    //give EOF to end of file
    while((ch=getchar())!=EOF){
        putchar(ch);
    }
   
    return 0;
}
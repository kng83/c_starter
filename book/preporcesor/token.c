#include <stdio.h>
#include <stdlib.h>

#define NSify(x) NS##x
#define gLogginEnabled 1
#define LOG(string)                                  \
    do                                               \
    {                                                \
        if (gLogginEnabled)                          \
            printf("\nConditional log: %s", string); \
    } while (0)

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define loop() for( ; ; )

//debug pattern
#define DEBUG
#ifdef DEBUG
#define D(s) \
    do       \
    {        \
        s;   \
    } while (0)
#else
#define D(s) \
    do       \
    { /**/   \
    } while (0)
#endif


int main()
{
    int NSify(String) = 4; // gives NSString
    printf("there i is %i", NSString);
    LOG("kot i pies");
    printf("\nmax is %i", MAX(4, 5));
    D(printf("\nhelp me out"));

    loop(){
        break;
    }
}
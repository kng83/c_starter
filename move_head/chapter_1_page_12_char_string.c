#include <stdio.h>
//declarations
void print_information();

int main()
{
    //def lancuchu znakow
    char s[4] = {'a', 'b', 's', '\0'}; // musimy zakonczyc lancuch znakow bo inaczej jest balagan

    printf("\nlancuch znakow %s", s);

    for (int i = 0; i < 2; i++)
    {
        print_information();
    }

    int card = 2;
    if (card > 1)
    {
        card = card - 1;
        if (card < 7)
            puts("Niska karta");
        else
            puts("As!");
    }
    return 0;
}

void print_information()
{
    puts("\nThis is some information");
}

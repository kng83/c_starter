/* rand0.c -- generuje liczby losowe */
/* stosujac przenosny algorytm ANSI C */
// uzycie w pliku obok
//zmienna ponizej ma zasieg plikowy bo static
static unsigned long int nast = 1; /* ziarno (ang. seed) */
int rand0(void)
{
    /* magiczna formula generujace liczby pseudolosowe */
    nast = nast * 1103515245 + 12345;
    return (unsigned int)(nast / 65536) % 32768;
}
void srand0(unsigned int ziarno)
{
 nast = ziarno;
}
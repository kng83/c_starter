#include <stdio.h>
#include <string.h>
 
typedef struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;

/* function declaration */
void printBook( struct Books book );

int main( ) {

   Books Book1;        /* Declare Book1 of type Book */
   Books Book2;        /* Declare Book2 of type Book */
 
   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* print Book1 info */
   printBook( Book1 );
   printBook( Book2 );

   Books *book_pointer;
   book_pointer = &Book1;
   book_pointer = &Book2;
   printf("to jest ksiazka o tytule %s",book_pointer->title);

   FILE *fp;
   char buff[255];
   fp = fopen("test.txt", "w+");
   printf("\n");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);

   fp = fopen("test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   //** tutaj jest bufor juz pomniejszony o fscanf
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   //** tu buffor jest znowu wyzerowany;
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);


   return 0;
}

void printBook(Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}
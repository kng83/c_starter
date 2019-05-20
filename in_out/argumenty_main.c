
//dodajemy argumenty 
//mozna zrobic program z argumentami
int main(int argc, char *argv[]){
  int counter;
  printf("Command line contains %d arguments :\n", argc-1);
  //argv[0] to nazwa programu dlatego od 1
  for(counter =1;counter<argc;counter++){
      printf("%d: %s\n", counter, argv[counter]);
  }
  printf("\n");
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bt/inc/btree.h"

#define MAX 30

void correct(char *s) {
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == '_')
      s[i] = ' ';
}


void readFile(FILE *f1, BTA *book) {
  char buff[100];
  char *name = (char*)malloc(30 * sizeof(char));	
  char* number = (char*)malloc(30 * sizeof(char));
	while(fgets(buff,100,f1) != NULL) {
		sscanf(buff, "%s %s", name, number);
		correct(name);
		btins(book,name,number,MAX);
	}
	free(name);
  free(number);
}

void find_key(BTA *book) {
  char name[30];
  char number[30];
  int rsize;
  fgets(name,MAX,stdin);
  if (name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';

  int val = btsel(book, name, number, MAX, &rsize);
  printf("val = %d\n", val);
  printf("number: %s\n",number);
  printf("rsize = %d\n",rsize);

}


int main()
{
  btinit();
  BTA *book = btopn("phonebook_bt", 0, 0);
  // FILE* f1 = fopen("phonebook.txt","r");
  // if (book == NULL) return 0;

  // readFile(f1,book);

  // fclose(f1);


  find_key(book);
  btcls(book);
  return 0;
}





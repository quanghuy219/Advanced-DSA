#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bt/inc/btree.h"

#define MAX 500

void create(BTA *dict, FILE *fin) {
	char *buff = (char*)malloc(MAX * sizeof(char));
	BTint val = 0;
	while (fgets(buff,MAX,fin) != NULL) {
		binsky(dict,buff,val++);
	}
}

int main()
{
	btinit();

	BTA *dict = btopn("dict",0,0);
	char word[MAX];
	char mean[MAX];
	int rsize;
	fgets(word,MAX,stdin);
	while(word[strlen(word) - 1] == '\n') word[strlen(word) - 1] = '\0';

	int val = btsel(dict, word, mean, MAX * sizeof(char), &rsize);

	if(val == 0) {
		printf("val = %d\n",val );
		printf("mean: %s\n",mean );
		printf("size: %d\n",rsize );
	}
	else printf("Not found\n");
	

	btcls(dict);

	return 0;
}
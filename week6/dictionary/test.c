#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bt/inc/btree.h"

#define MAX_WORD 100
#define MAX_DATA 100000

void correct(char *str) {
	while (str[strlen(str) - 1] == '\n') str[strlen(str)-1] = '\0';
}

void split_word(char *word, char* mean) {
	int mark = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		if(word[i] == '/') {
			mark = i;
			break;
		} 
	}
	if(mark != 0) {
	 	//strcat(mean,word+mark);
	 	// for (int i = mark; i < strlen(word); i++)
	 	// {
	 	// 	mean[i-mark] = word[i];
	 	// }
	 	word[mark-1] = '\0';
	}
	 
	for (int i = 0; i < strlen(word); i++)
	{
		word[i] = word[i+1];
	}
}

int readFile(FILE* fi,BTA* dict) {
	int count = 0;
	char word[MAX_WORD];
	char data[MAX_DATA];
	char buff[MAX_DATA];
	int val;

	while(!feof(fi)) {
		fgets(buff, MAX_DATA, fi);

		while(buff[0] != '@') {
			strcat(data, buff);
			if(feof(fi)) break;
			fgets(buff, MAX_DATA, fi);
		}
		correct(data);
		if(strlen(word) != 0 && strlen(data) != 0) {
			val = btins(dict, word, data, 500 * sizeof(char));
			if (val == 0)
			{
				printf("A word added\n");
			}
		}
		count++;
		if (buff[0] == '@')
		{
			word[0] = '\0';
			data[0] = '\0';	
			strcpy(word,buff);
			correct(word);
			split_word(word,data);
		}
		buff[0] = '\0';
	}
	return count;
}



int main(int argc, char const *argv[])
{
	FILE* f1 = fopen("src.txt","r");
	btinit();
	BTA* dict = btcrt("dict",0,0);

	if (dict == NULL)
	{
		printf("Error\n");
		return 0;
	}

	int words = readFile(f1,dict);
	printf("%d\n", words);
	
	fclose(f1);
	btcls(dict);
	return 0;
}
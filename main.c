#include "splitter.h"

int main(){
	char *string = "this|is|a|long|string|which|needs|to|be|splitted\n";
	char ** strings = split(string,'|');
	int count;
	printf("\nOriginal one: %s",string);
	printf("Splitted:");
	while (*strings){
		printf(" %s",*strings++);
		count++;
	}
	printf("Original one not touched: %s\n",string);

	//remember to deallocate once finished
	if (strings){
		strings -= count;
		free(strings);
	}
}

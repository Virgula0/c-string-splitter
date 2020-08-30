#include "splitter.h"

int main(){
	char *string = "this|is|a|long|string|which|needs|to|be|splitted\n";
	char ** strings = split(string,'|');
	int count;
	while (*strings){
		printf(" %s",*strings++);
		count++;
	}

	//remember to deallocate once finished
	if (strings){
		strings -= count;
		free(strings);
	}
}

#include "splitter.h"

int main(){
	char *string = "this|is|a|long|string|which|needs|to|be|splitted\n";
	char ** strings = split(string,'|');
	while (*strings)
		printf(" %s",*strings++);
}

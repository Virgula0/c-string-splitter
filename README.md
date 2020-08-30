# c-string-splitter
String splitter for c language just like split methods given by default by the majority of OOP languages.

Since i never found an easy implemantion and already well-coded function for split strings in c i build my own version.
This script avoid the use of functions like ```strtok``` wich modifies the original passed string to the function. Example of some problems when using strtok: [StackOverflow](https://stackoverflow.com/questions/63151324/segmentation-fault-returned-using-strtok/63151617).

Instead with this function, the passed string will not be manipulated.

# Usage
Include ```splitter.h``` in your code.
```
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
```

# MakeExample

Compile the example given with:

```
make
./main
```

![img](https://i.imgur.com/DNLVel3.png)



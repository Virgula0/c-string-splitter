# c-string-splitter
String splitter in for c language just like split function of OOP languages

Since i never found an easy implementing and already coded function for split strings in c i build my own version.
This avoid using functions just like strtok wich modify the original passed string to the function. Example of some problems while using strtok: [StackOverflow](https://stackoverflow.com/questions/63151324/segmentation-fault-returned-using-strtok/63151617)

# Usage
Include ```splitter.h``` in your code.
```
#include "splitter.h"

int main(){
	char *string = "this|is|a|long|string|which|needs|to|be|splitted";
	char ** strings = split(string,'|');
	while (*strings)
		printf(" %s",*strings++);
}
```

# MakeExample

Compile the example given with:

```
make
./main
```

![img](https://i.imgur.com/CkF90M9.png)



#include "splitter.h"

enum bool {
  FALSE,
  TRUE
};

typedef enum bool boolean;

boolean checkAllocated(char * pointer);
int countWordsOccurrences(char * string, char separator);
char ** getAllocatedSpace(int number, char * string);
char ** split(char * string, char separator);

boolean checkAllocated(char * pointer) {
  return pointer == NULL ? FALSE : TRUE;
}

int countWordsOccurrences(char * string, char separator) {
  char * z = malloc(sizeof(char) * strlen(string) + 1);
  if (!checkAllocated(z)) {
    perror("countWordsOccurences");
    exit(EXIT_FAILURE);
  }
  strncpy(z, string, strlen(string));
  int number = 0;
  for (int i = 0; i < strlen(string); i++) {
    char c = * z++;
    if (c == separator || * z == '\0')
      ++number;
  }
  return number;
}

char ** getAllocatedSpace(int number, char * string) {
  char ** strings = malloc(strlen(string) * sizeof * strings);
  for (int i = 0; i < number; i++) {
    strings[i] = malloc(strlen(string) * sizeof * strings);
  }
  return strings;
}

char ** split(char * string, char separator) {
  int count = 0;
  int inc = 0;
  int number = countWordsOccurrences(string, separator);
  int values[number];
  char * p = malloc(sizeof(char) * strlen(string) + 1);
  if (!checkAllocated(p)) {
    perror("countWordsOccurences");
    exit(EXIT_FAILURE);
  }
  strncpy(p, string, strlen(string));
  char ** strings = getAllocatedSpace(number, string);
  if (!checkAllocated( * strings) || !checkAllocated( & ( ** strings))) {
    perror("countWordsOccurences");
    exit(EXIT_FAILURE);
  }
  while ( * p) {
    char current = * p++;
    ( * strings[count]++) = current;
    inc++;
    if ( * p == separator) {
      *(++strings[count]) = '\0';
      values[count] = inc + 1;
      count++;
      inc = 0;
      p++;
    }
    if ( * p == '\0') {
      *(++strings[count]) = '\0';
      values[count] = inc + 1;
    }
  }
  for (int i = 0; i < number; i++) {
    for (int j = 0; j < values[i]; j++)
      strings[i]--;
  }
  return strings;
}

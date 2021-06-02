#include "map.h"
#include <ctype.h>
#include <stdio.h>

FILE* csv;

void exportline(char *s, int n) {
     fprintf(csv, "%s,%d\n", s, n); 
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "%s: Invalid arguments\n", argv[0]);
    return 1;
  }

  FILE *in = fopen(argv[1], "r");
  if (in == NULL) {
    fprintf(stderr, "%s: No such file\n", argv[1]);
    return 2;
  }

  int ch, i = 0, n;
  char word[100];
  MAP *wordlist = map_create();

  while ((ch = tolower(fgetc(in))) != EOF) {
    if (isalpha(ch)) {
      word[i++] = ch;
    } else if (i > 0) {
      word[i] = '\0';
      i = 0;
      if(map_search(wordlist, word, &n)){
          map_setvalue(wordlist, word, n + 1);
      }
      else{
          map_insert(wordlist, word, 1);
      }
    }
  }
  fclose(in);

  printf("%ld words(s) found\n", map_size(wordlist));

  csv = fopen("words.csv", "w");
  map_foreach(wordlist, exportline);
  fclose(csv);

  map_destroy(wordlist);

  return 0;
}

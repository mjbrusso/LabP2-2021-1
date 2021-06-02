#include "map.h"
#include <ctype.h>
#include <stdio.h>

void show_word(char *s, int n) { printf("%s: %d\n", s, n); }

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

  int ch, i = 0;
  char word[100];
  MAP *wordlist = map_create();

  while ((ch = tolower(fgetc(in))) != EOF) {
    if (isalpha(ch)) {
      word[i++] = ch;
    } else if (i > 0) {
      word[i] = '\0';
      i = 0;
      // TODO
      
    }
  }
  fclose(in);

  printf("%ld words(s) found\n", map_size(wordlist));
  map_foreach(wordlist, show_word);

  map_destroy(wordlist);

  return 0;
}

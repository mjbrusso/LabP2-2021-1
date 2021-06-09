#include "map.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    MAP_ITERATOR *p1 = (MAP_ITERATOR *)a,
                 *p2 = (MAP_ITERATOR *)b;

    int diff = map_value_at(*p2) - map_value_at(*p1);
    return diff != 0 ? diff : strcmp(map_key_at(*p1), map_key_at(*p2));
}

int main(int argc, char **argv)
{
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
            if (map_search(wordlist, word, &n)) {
                map_setvalue(wordlist, word, n + 1);
            } else {
                map_insert(wordlist, word, 1);
            }
        }
    }
    fclose(in);

    size_t nwords = map_size(wordlist);
    printf("%ld words(s) found\n", nwords);

    MAP_ITERATOR *vio = map_get_iterators(wordlist);
	FILE *csv = fopen("words.csv", "w");

    qsort(vio, nwords, sizeof(MAP_ITERATOR), cmp);
    for (int i = 0; i < nwords; i++) {
        fprintf(csv, "%s,%d\n", map_key_at(vio[i]), map_value_at(vio[i]));
    }
    fclose(csv);
    free(vio);

    map_destroy(wordlist);

    return 0;
}

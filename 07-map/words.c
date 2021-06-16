#include "map.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

int cmp(const void *a, const void *b)
{
    MAP_ITERATOR *p1 = (MAP_ITERATOR *)a,
                 *p2 = (MAP_ITERATOR *)b;

    int diff = map_value_at(*p2) - map_value_at(*p1);
    return diff != 0 ? diff : wcscmp(map_key_at(*p1), map_key_at(*p2));
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.utf8");
    if (argc != 2) {
        fprintf(stderr, "%s: Invalid arguments\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "%s: No such file\n", argv[1]);
        return 2;
    }

    int i = 0, n;
    wchar_t word[100];
    wint_t ch;
    MAP *wordlist = map_create();

    while ((ch = towlower(fgetwc(in))) != WEOF) {
        if (iswalpha(ch)) {
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
        fprintf(csv, "%ls,%d\n", map_key_at(vio[i]), map_value_at(vio[i]));
    }
    fclose(csv);
    free(vio);

    map_destroy(wordlist);

    return 0;
}

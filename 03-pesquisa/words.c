#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dict[371000][40];

int main()
{
    FILE *input;
    int n = 0;
    char word[50];

    input = fopen("english_words.txt", "r");
    if (input == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(input, "%s", dict[n]) == 1)
    {
        n++;
    }

    fclose(input);

    printf("Read %d words\n", n);
    printf("Search: ");
    while (scanf("%s", word) == 1)
    {
        if (bsearch(word, dict, n, sizeof(dict[0]), strcmp) == NULL)
        {
            printf("%s not found!\n", word);
        }
    }

    return 0;
}
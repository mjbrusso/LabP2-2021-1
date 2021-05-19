//#include "linkedlist.h"
#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
    printf("ARGC: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("ARGV[%d]=%s\n", i, argv[i]);
    }
    return 0;
}

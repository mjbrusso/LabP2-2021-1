//#include "linkedlist.h"
#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if(argc!=2){
        fprintf(stderr, "%s: Invalid arguments\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if(in==NULL){
        fprintf(stderr, "%s: No such file\n", argv[1]);
        return 2;
    }

    fclose(in);
    return 0;
}

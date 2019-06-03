#include <stdio.h>
#include <stdlib.h>
#include "hashtab.h"
#include <string.h>
#include "wtime.h"

int main()
{
    struct listnode *node;
    hashtab_init(hashtab);

    FILE *word;
    int n = 1000;
    int j = 0, k = 0;
    int conflict = 0;
    long long int o = 0;
    double t;
    char *string = NULL;
    char *string_c = NULL;
    long int *index_copy = NULL;
    index_copy = (long int*) malloc(1000000* sizeof(long int));
    string_c =(char*) calloc(n, sizeof(char));

    word = fopen("input.txt", "r");
    
    while(feof(word) == 0){
        j = 0;
        string =(char*) calloc(n, sizeof(char));
        fgets(string_c, 50, word);
        k++;
        while(string_c[j] != '\n') {
            string[j] = string_c[j];
            ++j;
        }
        if (k < 50001){
            if (k == 50000) {
                t = wtime();
                hashtab_add(hashtab, string, o);
                conflict_counting(string, &conflict, o, index_copy);
                o++;
                t = wtime() - t;
            } else {
                hashtab_add(hashtab, string, o);
                conflict_counting(string, &conflict, o, index_copy);
                o++;
            }
        }
    }
    fclose(word);

    double t_add = t;
    printf("Time hashtab_add = %.10f\n", t_add);

    printf("Conflict: %d", conflict);
    printf("\n");

    double t_lookup;
    t = wtime();
    node = hashtab_lookup(hashtab, "big");
    t = wtime() - t;
    t_lookup = t;
    printf("Time hashtab_lookup = %.10f\n", t_lookup);

    if (node != NULL)
        printf("Node: %s, %d\n", node->key, node->value);
    return 0;
}
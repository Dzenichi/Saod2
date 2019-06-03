#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <string.h>
#include "wtime.h"

int main()
{
    FILE *word;
    int n = 1000;
    double t;
    int i = 0, j = 0, k = 0;
    long long int o = 1;
    char *string = NULL;
    char *string_c = NULL;
    struct bstree *tree, *node, *node_two;
    string_c =(char*) calloc(n, sizeof(char));

    word = fopen("input.txt", "r");

    
    while(feof(word) == 0){
        j = 0;
        fgets(string_c, 100, word);
        string =(char*) calloc(n, sizeof(char));
        if(k < 200001) {
            while(string_c[j] != '\n') {
                string[j] = string_c[j];
                ++j;
            }
            if(i == 0) {
                tree = bstree_create(string, o);
                i = 1;
                ++o;
            }
            else {
                if (k == 200000) {
                    t = wtime();
                    bstree_add(tree, string, o);
                    ++o;
                    t = wtime() - t;
                } else {
                    bstree_add(tree, string, o);
                    ++o;
                }
            }
        } else {
            break;
            free(string);
            free(string_c);
        }
        k++;
    }
    fclose(word);


    double t_add = t;
    printf("Time bstree_add = %.10f\n", t_add);
    printf("%d\n", k);

    //bstree_delete(tree, "zzzxopfrgfid");
    //bstree_delete(tree, "Ashidic");

    /*node = bstree_max(tree);
    printf("Max key: %s, value: %d\n", node->key, node->value);
    
    node = bstree_min(tree);
    printf("Minimal key: %s, value: %d\n", node->key, node->value);*/

    t = wtime();
    node = bstree_lookup(tree, "klewznykklftv");
    printf("Found value for key %s: %d\n", node->key, node->value);
    t = wtime() - t;
    double t_lookup = t;

    printf("Time bstree_lookup = %.10f\n", t_lookup);

    return 0;
}
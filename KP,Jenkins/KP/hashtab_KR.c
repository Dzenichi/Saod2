#include <stdio.h>
#include <stdlib.h>
#include "hashtab.h"
#include <string.h>

unsigned int KRHash(char *key)
{
    unsigned int h = 0, hash_mul = 31;

    while (*key)
        h = h * hash_mul + (unsigned int)*key++;

    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
    int i;
    for (i = 0; i < HASHTAB_SIZE; i++)
        hashtab[i] = NULL;
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
    struct listnode *node;
    int index = KRHash(key);

    node = malloc(sizeof(*node));

    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
    struct listnode *node;

    int index = KRHash(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key))
            return node;
    }
    printf("Node not found\n");
    return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
    struct listnode *node, *prev = NULL;
    int index = KRHash(key);

    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key)) {
            if (prev == NULL)
                hashtab[index] = node->next;
        else
            prev->next = node->next;
        free(node);
        return;
        }
        prev = node;
    }
}

void conflict_counting(char *key, int *conflict, int o, long int *index_copy)
{
    long int index = KRHash(key);
    long int j;
    index_copy[o] = index;
    
    for(j = 0; j < o; ++j){
        if(index_copy[j] == index) {
            ++*conflict;
            break;
        }
    }
}
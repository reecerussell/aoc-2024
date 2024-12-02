#include <stdlib.h>
#include "int_dict.h"

#define TABLE_SIZE 10

unsigned int hash(int key)
{
    return key % TABLE_SIZE;
}

IntDict *create_int_dict()
{
    IntDict *dict = malloc(sizeof(IntDict));
    dict->buckets = malloc(TABLE_SIZE * sizeof(IntNode *));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        dict->buckets[i] = NULL;
    }
    return dict;
}

void insert_int_node(IntDict *table, int key, int value)
{
    unsigned int index = hash(key);
    IntNode *node = table->buckets[index];

    while (node != NULL)
    {
        if (node->key == key)
        {
            node->value = value;
            return;
        }
        node = node->next;
    }

    IntNode *new_node = malloc(sizeof(IntNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int get_int_node(IntDict *table, int key)
{
    unsigned int index = hash(key);
    IntNode *node = table->buckets[index];

    while (node != NULL)
    {
        if (node->key == key)
        {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

void free_int_dict(IntDict *dict)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        IntNode *node = dict->buckets[i];
        while (node != NULL)
        {
            IntNode *temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(dict->buckets);
    free(dict);
}

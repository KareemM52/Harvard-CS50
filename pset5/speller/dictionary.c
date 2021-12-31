#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
const unsigned int N = 26;
unsigned int key;
unsigned int word_count = 0;
node *table[N];
bool check(const char *word)
{
    unsigned int hashvalue = hash(word);
    node *cursor;
    cursor = table[hashvalue];
     while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
          cursor = cursor->next;
        }
    }
    return false;
}
unsigned int hash(const char *word)
{
   unsigned int t = (unsigned int) word[0];
    if (t >= 'a' && t <= 'z')
    {
        t = t - 97;
    }
    else if(t >= 'A' && t <= 'Z')
    {
        t = t - 65;
    }
    return t;
}
bool load(const char *dictionary)
{
    char h[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", h) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        int index = hash(h);
        strcpy(new_node->word, h);
        if (table[index] == NULL)
        {
            table[index] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        word_count++;
    }
    fclose(file);
    return true;
}
unsigned int size(void)
{
    if (word_count > 0)
    {
         return word_count;
    }
    return 0;
}
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
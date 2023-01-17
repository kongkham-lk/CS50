// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int wordCount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Getting hash table's index
    unsigned int key = hash(word);
    //Creating cursor to index each node instead of using head itself
    node *cursor = table[key];
    //Passing cursor through each node and check if the word is existed
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            //if exist then return true
            return true;
        }
        else
        {
            //not exist then move on to the nex node
            cursor = cursor->next;
        }
    }
    //free when reach the last node
    free(cursor);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int key = 0;
    int j = strlen(word);
    //getting the sum of each character
    for (int i = 3; i < j; i++)
    {
        key += (toupper(word[i]) - 'A');
    }
    //remainder N == 26 -> will return from 0 to 25
    return key % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //first open file dictionary in order to access the words
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("dictionary cannot be opened");
        fclose(dict);
        return false;
    }

    //creating buffer for storing word temporarily
    char str [LENGTH + 1];
    //scan and copy each string from dict to buffer until reach end of file
    while (fscanf(dict, "%s", str) != EOF)
    {
        //create new node to store the words
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            free(new_node);
            return false;
        }
        strcpy(new_node->word, str);

        //getting index number and assigned to hashtable
        int key = hash(str);
        //if head stored nth
        if (table[key] == NULL)
        {
            //set new node's pointer to next element as NULL
            new_node->next = NULL;
        }
        //if head store some word
        else
        {
            //set new node's next element as head
            new_node->next = table[key];
        }
        //set new node as head
        //no need to free new node as it already become new head == release itself
        table[key] = new_node;
        //start counting number of stored word
        wordCount++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //return total number of stored word
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //need to enter every single hash table that using malloc
    for (int i = 0; i < N; i++)
    {
        //create 2 additional node to track each node with each hashtable
        //1. cursor and 2. tmp
        //always start by setting cursor from head to keep track to the race
        node *cursor = table[i];
        while (cursor != NULL)
        {
            //in order to allow cursor to move on to the next and free the current
            //need tmp to stay at the current one
            //when cursor move to the next then tmp free the current
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        //lastly when cursor reach the last node, free itself
        free(cursor);
    }
    return true;
}

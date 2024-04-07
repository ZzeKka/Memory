#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h> 

typedef struct node
{
    struct node * next;
    char word[];
}node; 

void add_node_begin(node ** list, const char * word);
void add_node_end(node ** list, const char * word);
void clear_list(node ** list);
void print_linked_list(node * list);
int list_length(node * list);


// MAIN
//___________________________________________

int main(void)
    
{
    srand(time(0));
    node * linked_list = NULL;
    add_node_begin(&linked_list,"ola");
    add_node_begin(&linked_list,"adeus");
    add_node_end(&linked_list,"voltei");
    print_linked_list(linked_list);
    printf("list len is: %d\n", list_length(linked_list));
    clear_list(&linked_list);
    print_linked_list(linked_list);
    printf("list len is: %d\n", list_length(linked_list));
    return 0;
}

//____________________________________________

void add_node_begin(node ** list, const char * word)
{
    size_t length = strlen(word);
    node * new_node = malloc(sizeof(node) + strlen(word) + 1);
    if(new_node == NULL)
    {
        printf("%p\n", ( void * )new_node);
        free(new_node);
        return;
    }
    strcpy(new_node->word, word);
    new_node->next = *list;
    *list = new_node;
}  

void add_node_end(node ** list, const char * word)
{
    size_t length = strlen(word);
    node * new_node = malloc(sizeof(node) + strlen(word) + 1);
    if(new_node == NULL)
    {
        printf("%p\n", ( void * )new_node);
        free(new_node);
        return;
    }
    strcpy(new_node->word, word);
    node * n = *list;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = new_node;
    new_node->next = NULL;
}  


void clear_list(node ** list)
{
    if((*list) == NULL)
    {   
        return;
    }

    clear_list(&(*list)->next); 
    free(*list);
    *list = NULL;
}


void print_linked_list(node * list)
{
    if(list == NULL)
    {
        printf("%s\n","List is empty!");
    } 
    else
    {
        printf("%s","LinkedList");
        node * n = list;
        do
        {
            printf("->|%s|", n->word);
            n=n->next;
        }
        while (n != NULL);
        printf("%s\n","");
    }
}

int list_length(node * list)
{
    int count = 0;
    node * current = list;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }   
    return count;
}


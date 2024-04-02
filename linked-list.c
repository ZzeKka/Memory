#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h> 

#define BUFFER_SIZE 100


typedef struct node
{
    struct node * next;
    char word[];
}node; 

void add_node_begin(node ** list, const char * word);
void print_linked_list(node * list);


// MAIN
//___________________________________________

int main(void)
    
{
    srand(time(0));
    node * linked_list = NULL;
    printf("%p\n",&linked_list);
    add_node_begin(&linked_list,"ola");
    add_node_begin(&linked_list,"adeus");
    return 0;
}

//____________________________________________

void add_node_begin(node ** list, const char * word)
{
    printf("%p\n",*list);
    printf("%p\n",list);
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

void print_linked_list(node * list)
{
}



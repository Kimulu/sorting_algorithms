#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: A pointer to the pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
/*Check if list is NULL or if it contains less than 2 elements*/
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

listint_t *current = (*list)->next;

/*Main sorting loop*/
while (current != NULL)
{
/*Inner loop for insertion*/
listint_t *prev_node = current->prev;
listint_t *next_node = current->next;

while (prev_node != NULL && prev_node->n > current->n)
{
/*Swap nodes*/
if (prev_node->prev != NULL)
prev_node->prev->next = current;
if (current->next != NULL)
current->next->prev = prev_node;

prev_node->next = next_node;
current->prev = prev_node->prev;

prev_node->prev = current;
current->next = prev_node;

if (current->prev == NULL)
*list = current;

/*Print list after each swap*/
print_list(*list);

prev_node = current->prev;
}

current = next_node;
}
}

#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * using the Insertion sort algorithm
 * @list: double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *prev, *next;
curr = (*list)->next;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (curr != NULL)
{
next = curr->next;
prev = curr->prev;
while (prev != NULL && prev->n > curr->n)
{
prev->next = curr->next;
if (curr->next != NULL)
curr->next->prev = prev;
curr->prev = prev->prev;
curr->next = prev;
if (prev->prev != NULL)
prev->prev->next = curr;
else
*list = curr;
prev->prev = curr;
prev = curr->prev;
print_list(*list);
}
curr = next;
}
}

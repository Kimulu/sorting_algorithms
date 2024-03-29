#include "sort.h"

/**
 * swap_nodes_list - Swap nodes in a listint_t list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes_list(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *iter, *insert_node, *tmp_ptr;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (iter = (*list)->next; iter != NULL; iter = tmp_ptr)
{
tmp_ptr = iter->next;
insert_node = iter->prev;
while (insert_node != NULL && iter->n < insert_node->n)
{
swap_nodes_list(list, &insert_node, iter);
print_list(*list);
}
}
}

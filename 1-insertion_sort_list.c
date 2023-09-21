#include "sort.h"

/**
 * swap - Swaps two nodes of a doubly linked list
 *
 * @head: Head pointer of the doubly linked list.
 * @first_node: A pointer to the first node to be swapped.
 * @second_node: The second node to be swapped.
 */
void swap(listint_t **head, listint_t **first_node, listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;

	if ((*first_node)->prev)
		(*first_node)->prev->next = second_node;
	else
		*head = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}
/**
 * insertion_sort_list - Implements the insertion sort algorithm
 *			which sorts a doubly linked list of ints.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i = *list;
	listint_t *tail, *head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (i)
	{
		head = i->next;
		tail = i->prev;
		while (tail && i->n < tail->n)
		{
			swap(list, &tail, i);
			print_list((const listint_t *)*list);
		}
		i = head;
	}
}

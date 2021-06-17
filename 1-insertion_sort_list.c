#include "sort.h"

/**
 * _swap - change node position
 * @a: current node
 * @b: previus node
 * @list: double linked list
 */
void _swap(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->next == NULL)
	{
		b->prev->next = a;
		a->prev = b->prev;
		b->next = NULL;
	}
	else if (b->prev == NULL)
	{
		a->prev = NULL;
		b->next = a->next;
		a->next->prev = b;
		*list = a;
	}
	else
	{
		b->prev->next = a;
		a->prev = b->prev;
		b->next = a->next;
		a->next->prev = b;
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev, *node, *tmp;

	if (!list || !*list)
		return;

	head = *list;

	while (head)
	{
		prev = head->prev;
		tmp = head;
		while (tmp && tmp->prev)
		{
			node = tmp;
			prev = tmp->prev;
			if (node->n < prev->n)
			{
				_swap(node, prev, list);
				node->next = prev;
				prev->prev = node;
				print_list(*list);
			}
			else
				break;
		}
		head = tmp;
		head = head->next;
	}
}

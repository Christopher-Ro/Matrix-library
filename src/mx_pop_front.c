#include "libmx.h"

void mx_pop_front(t_list **head)
{
    if (*head == NULL) return;
    t_list *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

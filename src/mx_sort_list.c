#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *))
{
    void *buf = NULL;
    t_list *curr = list;
    t_list *head = list;
    while (list != NULL)
    {
        curr = list->next;
        while (curr != NULL)
        {
            if (cmp(curr->data, list->data))
            {
                buf = list->data;
                list->data = curr->data;
                curr->data = buf;
            }
            curr = curr->next;
        }
        list = list->next;
    }
    return head;
}

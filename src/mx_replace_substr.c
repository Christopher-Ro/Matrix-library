#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    char *res = NULL;
    char *prev = res;
    char *cur = NULL;
    int sub_len = mx_strlen(sub);
    while (str != NULL)
    {
        cur = mx_strndup(str, mx_get_substr_index(str, sub));
        str = mx_strstr(str, sub);
        res = mx_strjoin(res, cur);
        mx_strdel(&cur);
        mx_strdel(&prev);
        prev = res;
        res = mx_strjoin(res, replace);
        mx_strdel(&prev);
        prev = res;
        if (*(str + sub_len) == '\0') break;
        if (str != NULL) str += sub_len;
    }
    return res;
}

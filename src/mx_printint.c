void mx_printchar(char c);

void mx_printint(int n)
{
    if (n == 0)
    {
        mx_printchar('0');
        return;
    }
    if (n < 0) mx_printchar('-');
    int digits = 0;
    int copy = n;
    while (copy != 0)
    {
        digits++;
        copy /= 10;
    }
    char bufer[digits];
    if (n < 0) bufer[digits - 1] = -(n % 10) + '0';
    else bufer[digits - 1] = n % 10 + '0';
    n /= 10;
    n = n < 0 ? -n : n;
    for (int i = digits - 2; i >= 0; i--)
    {
        bufer[i] = n % 10 + '0';
        n /= 10;
    }
    for (int i = 0; i < digits; i++)
    {
        mx_printchar(bufer[i]);
    }
}

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    char *find;
    char *src;
    int fi;
    int si;

    find = argv[1];
    src = argv[2];
    fi = 0;
    si = 0;
    if (argc != 3)
    {
        ft_putchar('\n');
        return (0);
    }
    while (src[si])
    {
        if (find[fi] == src[si])
            fi++;
        si++;
    }
    if (fi == ft_strlen(find))
    {
        ft_putstr(find);
        ft_putchar('\n');
    }
    else
        ft_putchar('\n');
    return (0);
}
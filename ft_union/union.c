#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int		verif(char *str, char c, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void    ft_union(char *av1, char *av2)
{
    int i;
    int len;

    i = 0;
    while(av1[i])
    {
        if (verif(av1, av1[i], i) == 1)
            ft_putchar(av1[i]);
        i++;
    }
    len = i;
    i = 0;
    while(av2[i])
    {
        if (verif(av2, av2[i], i) == 1)
        {
            if (verif(av1, av2[i], len) == 1)
                ft_putchar(av2[i]);
        }
        i++;
    }
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
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

void    inter(char *av1, char *av2)
{
    int i;
    int k;
    int l;
    char tab[ft_strlen(av2)];

    i = 0;
    l = 0;
    while (av1[i])
    {
        k = 0;
        while(av2[k])
        {
            if (av1[i] == av2[k] && verif(av1, av1[i], i) && verif(tab, av1[i], l))
            {
                tab[l] = av1[i];
                l++;
            }
            k++;
        }
        i++;
    }
    tab[l] = '\0';
    ft_putstr(tab);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        inter(argv[1], argv[2]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}
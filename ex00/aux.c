#include	"header.h"

int	comprobador(char *str, char	*to_find, int booleana, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if ((to_find[j + 1] == '\0') && (str[i + 1] == ' '
					|| str[i + 1] == ':'))
			{
				booleana = 1;
				break ;
			}
			i++;
			j++;
		}
		else
			break ;
	}
	return (booleana);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		booleana;

	i = 0;
	j = 0;
	booleana = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			booleana = comprobador(str, to_find, booleana, i);
			if (booleana == 1)
			{
				return (&str[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void	ft_printf(char *str)
{
	unsigned int	i;
	char			aux;

	i = 0;
	while (str[i] != ':')
	{
		i++;
	}
	i++;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] != '\n')
	{
		aux = str[i];
		write(1, &aux, 1);
		i++;
	}
}

int	myDiccionary(int argc, char *argv[], char *search)
{
	int		fd;
	char	*buf;
	char	*c;

	buf = malloc(sizeof(char) * 5000);
	if (argc == 2)
		fd = open("../ex00/numbers.dict.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-8); //Error al abrir archivo
	else
	{
		c = ft_strstr(buf, search);
		if (!c)
			return (-9); //No ha encontrado la cadena
		ft_printf(c);
	}
	free(buf);
	return (0);
}

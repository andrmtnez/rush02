#include "header.h"

int	ficheroControl(int argc, char *argv[])
{
	int		fd;
	char	*buf;
	ssize_t	n_bytes;

	buf = malloc(sizeof(char) * 5000);
	if (argc == 2)
		fd = open("numbers.dict.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-4); //Error al abrir archivo
	else
	{
		n_bytes = read(fd, buf, 5000);
		close (fd);
		if (n_bytes == 0)
			return (-5); //Archivo vacio
	}
	free(buf);
	return (0);
}

int	errorControl(int argc, char *argv[])
{
	unsigned int	i;
	char			*pt;

	if (argc != 2 && argc != 3)
		return (-1); //Numero de argumentos errones
	i = 0;
	pt = argv[argc - 1];
	while (pt[i] != '\0')
	{
		if (pt[i] < 48 || pt[i] > 57)
			return (-2); //Argumento final no válido
		i++;
	}
	return (0);
}

int	program(int argc, char *argv[])
{
	char	*pt;
	int		i;

	if (argc == 3)
		pt = argv[2];
	else
		pt = argv[1];
	i = myOwnAtoi(pt, argc, argv);
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (errorControl(argc, argv) != 0)
	{
		write(1, "Error\n", 6);
		return (errorControl(argc, argv));
	}
	if (ficheroControl(argc, argv) != 0)
	{
		write(1, "Dict Error\n", 11);
		return (ficheroControl(argc, argv));
	}
	i = program(argc, argv);
	if (i != 0)
	{
		write(1, "Dict Error\n", 11);
		return (i);
	}
}

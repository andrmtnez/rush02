#include "header.h"

int	myOwnAtoi(char *str, int argc, char *argv[])
{
	unsigned int	j;
	unsigned int	i;
	char			*numero;
	char			*numero_primero;
	unsigned int	aux;
	int				k;
	int				space;

	space = 0;
	aux = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (aux < i)
	{
		if (str[aux] != '0')
		{
			if (space == 0)
				space = 1;
			else
				write(1, " ", 1);
			if (str[aux] != 0 && ((i - aux) >= 3))
			{
				if ((i - aux - 1) % 3 != 0 && (i - aux > 3))
				{
					numero_primero = (char *) malloc(sizeof(char) * (i - aux - 1) % 3);
					while (j < ((i - aux - 1) % 3))
					{
						numero_primero[j] = str[aux + j];
						j++;
					}
					myOwnAtoi(numero_primero, argc, argv);
				}
				else
				{
					numero_primero = (char *) malloc(sizeof(char));
					numero_primero[0] = str[aux];
					myDiccionary(argc, argv, numero_primero);
					str[aux] = '1';
					write(1, " ", 1);
				}
			}
			numero = (char *) malloc(sizeof(char) * (i - aux));
			while (j <= (i - aux))
			{
				numero[j] = '\0';
				j++;
			}
			j = 0;
			while (j < (i - aux))
			{
				numero[0 + j] = '0';
				numero[0] = str[aux];
				j++;
			}
			k = myDiccionary(argc, argv, numero);
			if (k < 0)
				return (k);
			j = 0;
		}
		aux++;
	}
	free(numero);
	free(numero_primero);
	write(1, "\n", 1);
	return (0);
}

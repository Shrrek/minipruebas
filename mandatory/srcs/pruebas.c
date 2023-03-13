#include "../incs/minishell.h"

static char **ft_process_string(char **dest, const char *str, char c)
{
	printf("\nPROCESS STRING\n");
	size_t i;
	size_t j;
	size_t start;

	i = -1;
	j = -1;
	start = 0;
	//printf("str del split = %s\n", str);
	while (str[++i])
	{
		//printf("ha entrado\n");
		/* Primero comprueba si empieza por comillas */
		if (str[i] == 34 || str[i] == 39)
		{
			/* Identifica que comilla ha encontrado y procesa su parseo*/
			if (str[i] == 34)
			{
				/* Ahora recorrremos la cadena hasta que encuentre la siguiente comilla y 
				el siguiente caracter a esta sea espacio o fin de cadena. Mientras no cumpla
				con ambas condiciones seguira recorriendo la cadena. Como anteriormente a esto ya hemos
				comprobado que  todas las comillas delimitantes tienen pareja, realmente no nos preocupa
				no encontrarla por que va a estar */
				while (str[++i])
				{
					/* Si encuentra su pareja de comillas toca examinar si su siguiente caracter es un espacio,
					un caracter nulo, o si sigue habiendo contenido */
					if (str[i] == 34)
					{
						while (str[i] != ' ' && str[i])
							i++;
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;
					}
				}
			}
			/* Si la comilla es simple */
			else
			{
				while (str[++i])
				{
					if (str[i] == 39)
					{
						while (str[i] != ' ' && str[i])
							i++;
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;
					}
				}
			}
			i++;
			start = i;
		}
		/* Si empieza por cualquier otro caracter y este es alfanumerico */
		else
		{
			while (str[i] != c && str[i])
			{
				i++;
				if (str[i] == 34)
				{
					i++;
					while (str[i] && str[i] != 34)
						i++;
					if (str[i + 1] == c)
					{
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;			
					}
					while (str[i] && str[i] != c)
						i++;
					dest[++j] = ft_splitdup(str, start, i);
				}
				else if (str[i] == 39)
				{
					i++;
					while (str[i] && str[i] != 39)
						i++;
					if (str[i + 1] == c)
					{
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;			
					}
					while (str[i] && str[i] != c)
						i++;
					dest[++j] = ft_splitdup(str, start, i);
				}
				else if (str[i] == c || i == ft_strlen(str))
					dest[++j] = ft_splitdup(str, start, i);
				
			}
			while (str[i] == c && str[i])
			{
				i++;
				start = i;
			}			
		}
	}
	dest[++j] = NULL;
	//printf("%s\n", dest[j]);
	return (dest);
}
int main(int argc, char **argv, char **envp)
{
	
}
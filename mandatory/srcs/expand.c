#include "../incs/minishell.h"

/* Busca si una variable forma parte de las variables del entorno. Si
la encuentra devuelve su valor, sino devuelve el nombre de la variable. */
char	*ft_get_env_var_val(char *var, char **env)
{
	size_t var_len;
	size_t env_var_len;
	char *env_var_content;
	int i;

	i = -1;
	var_len = ft_strlen(var);
	while (env[++i])
	{
		env_var_len = ft_get_chrlen(env[i], '=');
		if (env_var_len == var_len)
		{
			if (ft_strnstr(env[i], var, var_len))
			{
				env_var_content = ft_strdup(&env[i][env_var_len + 1]);
				return env_var_content;
			}
		}
	}
	return (NULL);
}

/* Si se puede expandir, recibe el contenido despues del $ y lo recorre
y copia en una cadena hasta que encuentra el final de la cadena, unas comillas,
un espacio u otro dolar.*/
char	*ft_get_var(char *str)
{
	int		i;
	char	*var;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39 && str[i] != '$')
		i++;
	var = (char *)malloc(sizeof(char) * i + 1);
	if (!var)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != '$' && str[i] != 39)
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	*ft_expand(char *var, char *var_value, char *str)
{
	char	*new_value;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = -1;
	(void)var;
	new_value = (char *)malloc(sizeof(char) * (ft_strlen(var_value) + ft_strlen(str) - ft_strlen(var)));
	if (!new_value)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			while (var_value[++k])
				new_value[++j] = var_value[k];
			while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != '$' && str[i] != 39) // pensar como meter el dolar
				i++;
			break;
		}
		else
		{
			new_value[++j] = str[i];
			i++;		
		}

	}
	while (str[i])
	{
		new_value[++j] = str[i];
		i++;
	}
	new_value[++j] = '\0';
	return (new_value);
}

/* Recibe un argumento del split*/
char	*ft_var_not_found(char *str, char *var)
{
	int		i;
	int		j;
	char	*new_value;

	i = -1;
	j = -1;
	new_value = (char *)malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(var)));
	if (!new_value)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '$')
		{
			i++;
			while (str[i] && str[i] !=34 && str[i] != '$' && str[i] != 32 && str[i] != 39)
				i++;
		}
		else
			new_value[++j] = str[i];
	}
	new_value[++j] = '\0';
	return (new_value);	
}

void	ft_process_expand(char **str, char **env)
{
	int		i;
	int		j;
	char	*var;
	char	*var_value;


	i = -1;
	/*printf("\n");
	ft_print2dstr(str);
	printf("\n");*/
	while (str[++i])
	{
		//printf("%s\n", str[i]);
		j = 0;
		while (str[i][j])
		{
			//printf("El argumento es =  %s\n", &str[i][j]);
			/* Si se puede expandir */
			if (str[i][j] == '$')
			{
				/* Obtiene el nombre de la variable */
				var = ft_get_var(&str[i][j + 1]);
				//printf("\nEl nombre de la variable es: %s\n", var);
				/* Pilla el valor de la variable */
				var_value = ft_get_env_var_val(var, env);
				if (!var_value)
					str[i] = ft_var_not_found(str[i], var);
				else
					str[i] = ft_expand(var, var_value, str[i]);
				//printf("El argumento es =  %s\n", &str[i][j]);
				while (str[i][j] && str[i][j] !=34 && str[i][j] != '$' && str[i][j] != 32 && str[i][j] != 39)
					j++;
			}
			else
				j++;
		}
	}
}
#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

typedef struct s_mini
{
	char	**mini_env;
	char	*next_line;
	char	*mini_home;
	char	*mini_path;
	char	**next_line_split;
} t_mini;

/* ADD FUCNTIONS */
char	*ft_join_chr(char *str, int c);
char	**ft_split(const char *str, char c);
char	*ft_strtrim(const char *str, char const *set);
char	*ft_substr(const char *str, unsigned int start, size_t len);

/* COMPARE FUNCTIONS */
int		ft_str_equals(const char *str1, const char *str2);

/* COPY FUNCTIONS */
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t n);
char	**ft_2dstrdup(const char **str);
char	**ft_2dstrndup(const char **str, size_t cols);
char	**ft_2dnstrdup(const char **str, size_t rows);
char	**ft_2dnstrndup(const char **str, size_t rows, size_t cols);
char	*ft_swap_str(char *str);
char	**ft_swap_2dstr(char **str);

/* ERROR FUNCTIONS */
/* FREE FUNCTIONS */
void	ft_free_2dstr(char **str);
void	ft_general_free(t_mini *minishell);

/* MINISHELL FUNCTIONS */
void	ft_export(t_mini *minishell);
void	ft_builts(t_mini *minishell);
void	ft_echo(char **next_line);
void	ft_process_expand(char **str, char **env);

/* PARSE FUNCTIONS */
int		ft_parse_quotes(const char *str);
char	*ft_delete_quotes(char *str);
char	*ft_delete_spaces(char *str);

/* PRINT FUNCTIONS */
void	ft_print2dstr(char **str);
/* READ FUNCTIONS */
char	*ft_read_input(char *str);

/* SEARCH FUNCTIONS */
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/* SIGNALS FUNCTIONS */
void	ft_signal_handler(int signal);

/* SIZE FUNCTIONS */
size_t	ft_strlen(const char *str);
size_t	ft_2dstrlen(const char **str);
size_t	*ft_2dstrstrlen(const char **str);
int		ft_get_chramt(const char *str, int c);
int		ft_get_chrlen(const char *str, int c);

#endif
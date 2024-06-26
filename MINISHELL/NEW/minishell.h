#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "mini_def.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>

// Function parameters

// parsing.c

void		parsing_distributor(t_shell *d);

// envp_parse.c

size_t		parse_envp(t_shell *shell, size_t i);

// envp_init.c

char		**create_envp(char **envp);

// utils_syntax.c

bool		syntax_check(const char *line);

// utils_string.c

char		*strdup_index(char *str, size_t	start, size_t end);

// utils_exit.c

void		exit_clean(t_shell *shell, int num, char *message);
// void	exit_va_free(t_shell *d, int num, char *message, int amount, ...);

// utils_freeing.c

void		free_setnull(void **ptr);
void		free_if(void *ptr);
void		free_va(int amount, ...);

// utils_sig_arg_list.c

void		sig_arg_add_back(t_sig_arg **node, t_sig_arg *new);
t_sig_arg	*sig_arg_last(t_sig_arg *node);
t_sig_arg	*sig_arg_new(t_list **cmd_head, char **cmd_array, short token);
void		sig_arg_clear(t_sig_arg **node);
void		sig_arg_delone(t_sig_arg *node);

#endif

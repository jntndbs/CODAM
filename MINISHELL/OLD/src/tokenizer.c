#include "../minish_param.h"

// Assigns tokens to each argument.
// Tokens defined in: minish_def.h
void	tokenizer(t_dad *d)
{
	size_t	i;
	
	i = 0;
	while (d->line[i])
	{
		if (d->line[i] == ' ')
			++i;
		i = parse_env_variable(d, i);
	}
}

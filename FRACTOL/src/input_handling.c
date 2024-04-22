#include "../lib/fractol.h"

// Input error | format: ./name "[type/ set]"(mandelbrot/ julia/ divine) "[optional julia z val]"
int	num_check(t_fractal *f, char *arg, int i)
{
	int	c;
	
	c = 0;
	if (arg[i] == '-')
		i++;
	if (!(ft_isdigit(arg[i])))
		ft_error(f, "Instr...2");
	while (arg[i] && (ft_isdigit(arg[i]) || arg[i] == '.'))
	{
		if (arg[i] == '.')
			c++;
		i++;
	}
	if (c > 1)
		ft_error(f, "Instr...3");
	return (i);
}

bool	arg_check(t_fractal *f, char *arg)
{
	int	i;

	if (!arg || ft_strlen(arg) > 1000 || ft_strlen(arg) < 4)
		ft_error(f, "Instr...1");
	i = 0;
	i = num_check(f, arg, i);
	if (arg[i] != ',' || arg[i + 1] != ' ' || !ft_isdigit(arg[i + 2]))
		ft_error(f, "Instr...4");
	i += 2;
	i = num_check(f, arg, i);
	if (ft_strlen(arg) != i)
		ft_error(f, "Instr...5");
	return (true);
}

static double	ft_atof(char *arg)
{
	double	num;
	int		i;
	int		mult;
	int		c;
	
	i = 0;
	mult = 1;
	num = 0;
	if (arg[i] == '-')
		mult = -1;
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num = num * 10 + (arg[i] - '0');
		i++;
	}
	c = i;
	if (arg[i] != '.')
		return (num * mult);
	i++;
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num += (double)(arg[i] - '0') / pow(10, (double)(i - c));
		i++;
	}
	return (num * mult);
}

void	assign_jul_c(t_fractal *f, char *arg)
{
	f->julia_x = ft_atof(arg);
	while (*arg != ' ')
		arg++;
	f->julia_y = ft_atof(++arg);
}

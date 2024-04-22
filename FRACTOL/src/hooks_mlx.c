#include "../lib/fractol.h"

static void	move_hook(void *param)
{
	t_fractal	*f;
	
	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->offset_y += 0.05 * f->zoom;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->offset_y -= 0.05 * f->zoom;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->offset_x -= 0.05 * f->zoom;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->offset_x += 0.05 * f->zoom;
		f->draw = true;
	}
}

static void	draw_hook(void *param)
{
	t_fractal	*f;
	
	f = param;
	if (f->draw && f->set == mandel)
	{
		printf(">> DRAW MAND\n");// TEST
		ft_draw_mandel(f);
	}
	else if (f->draw && f->set == julia)
	{
		printf(">> DRAW JUL\n");// TEST
		ft_draw_julia(f);
	}
	if (f->color_shift == true)
		color_shift(f);
}

static void	draw_hook_divine(void *param)
{
	t_fractal	*f;
	t_complex	z;
	t_complex	c;
	
	f = param;
	if (f->draw)
	{
		z.x = 0.0;
		z.y = 0.0;
		printf(">> DRAW MAND D\n");// TEST
		ft_draw_mandel_div(f, z);
	}
	if (f->draw_j)
	{
		c.x = f->julia_x;
		c.y = f->julia_y;
		printf(">> DRAW JUL D\n");// TEST
		ft_draw_julia_div(f, c);
	}
}

void	assign_hooks_basic(t_fractal *f)
{
	mlx_close_hook(f->mlx, close_all, f);
	mlx_loop_hook(f->mlx, move_hook, f);
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_key_hook(f->mlx, ft_key_basic, f);
	mlx_resize_hook(f->mlx, ft_image_resize, f);
	mlx_loop_hook(f->mlx, draw_hook, f);
}

void	assign_hooks_divine(t_fractal *f)
{
	mlx_close_hook(f->mlx, close_all, f);
	mlx_key_hook(f->mlx, ft_key_divine, f);
	mlx_scroll_hook(f->mlx, ft_div_scroll, f);
	mlx_loop_hook(f->mlx, draw_hook_divine, f);
	mlx_loop_hook(f->mlx, ft_cursor_to_julia, f);
	mlx_loop_hook(f->mlx, div_move_hook, f);
}

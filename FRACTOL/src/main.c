#include "../lib/fractol.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_window_size_reset(fra_t *f)
{
	mlx_resize_image(f->img, WIDTH, HEIGHT);
	mlx_set_window_size(f->mlx, WIDTH, HEIGHT);
}

bool	ft_cursor_check(fra_t *f)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (x < 0 || y < 0 || x > f->mlx->width || y > f->mlx->height)
		return (false);
	return (true);
}

void	ft_zoom(fra_t *f)
{
	if (ft_cursor_check(f) == false)
		return ;
	printf(">> ZOOM\n");// TEST
}

void	ft_key(mlx_key_data_t keydata, void* param)
{
	fra_t	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(f->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_window_size_reset(f);
	if (keydata.key == MLX_MOUSE_BUTTON_LEFT && keydata.action == MLX_PRESS)
		ft_zoom(f);
}

void	ft_set_pix(fra_t *f, size_t iter)
{
	if (iter == f->iterations)
		mlx_put_pixel(f->img, f->x, f->y, 0x000000FF);
	else
		mlx_put_pixel(f->img, f->x, f->y, 0xFFFF00FF);
}

void	draw(int32_t width, int32_t height, fra_t *f)
{
	c_t	c;
	size_t	iter;
	
	f->y = 0;
	while (f->y < width)
	{
		f->x = 0;
		while (f->x < height)
		{
			c.real = ft_scale(f, f->x, x_ax);
			c.imag = ft_scale(f, f->y, y_ax);
			iter = ft_math(f, c);
			ft_set_pix(f, iter);
			f->x++;
		}
		f->y++;
	}
}

static void ft_image_redraw(int32_t width, int32_t height, void* param)
{
	fra_t	*f;

	f = param;
	printf("WIDTH: %d | HEIGHT: %d\n", width, height);// TEST
	mlx_resize_image(f->img, width, height);
	draw(width, height, f);
}

void	ft_scroll(double xdelta, double ydelta, void* param)
{
	fra_t	*f;
	
	f = param;
	printf(">> SCROLL\n");// TEST
	if (ft_cursor_check(f) == false || ydelta > INT_MAX)
		return ;
	// HOW TO ZOOM INTO FRACTAL?? LEFTOFF DOES NOT WORK!
	f->scale_max_x += xdelta / 10;
	f->scale_min_x -= xdelta / 10;
	f->scale_max_y += xdelta / 10;
	f->scale_min_y -= xdelta / 10;
	ft_image_redraw(f->mlx->width, f->mlx->height, f);
}

void	fractol(char *name, fra_t *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(WIDTH, HEIGHT, name, false);
	if (!f->mlx)
		ft_error();
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error();
	draw(WIDTH, HEIGHT, f);
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_key_hook(f->mlx, ft_key, f);
	mlx_resize_hook(f->mlx, ft_image_redraw, f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	fra_t	f;

	if (argc != 2)
		ft_error();

	f.scale_min_x = -2.2;
	f.scale_max_x = 0.8;
	f.scale_min_y = 1;
	f.scale_max_y = -1;
	f.iterations = 400;
	f.set = mandel;
	f.inp = 1.0;
	
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}

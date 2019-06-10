/*
** EPITECH PROJECT, 2019
** square
** File description:
** sqyare
*/

#include "draw_a_line.h"

void square (void)
{
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_create(800, 600);
    sfVideoMode mode = {800, 600, 32};
    t_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfEvent event;
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    window = sfRenderWindow_create(mode,"window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 1160);
    while (sfRenderWindow_isOpen(window)) {
        sfTexture_updateFromPixels(texture, framebuffer->pixels, framebuffer->width, 
                                    framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        my_put_square(framebuffer);
    }
    sfRenderWindow_destroy(window);
}

void my_put_square(t_framebuffer *buffer)
{
	int radius = random_z();
	int f = 1;
    int x0 = random_x();
    int y0 = random_y();
	int fx = 0;
	int fy = -2 * radius;
	int x = 0;
	int y = radius;

	my_put_pixel(buffer, x0, y0 + radius);
	my_put_pixel(buffer, x0, y0 - radius);
	my_put_pixel(buffer, x0 + radius, y0);
	my_put_pixel(buffer, x0 - radius, y0);
	while (x < y) {
		fycalc(y, fy, f);
		x++;
		fx += 2;
		f += fx - 1;
		my_put_pixel(buffer, x0 + x, y0 + y);
		my_put_pixel(buffer, x0 - x, y0 + y);
		my_put_pixel(buffer, x0 + x, y0 - y);
		my_put_pixel(buffer, x0 - x, y0 - y);
		my_put_pixel(buffer, x0 + y, y0 + x);
		my_put_pixel(buffer, x0 - y, y0 + x);
		my_put_pixel(buffer, x0 + y, y0 - x);
		my_put_pixel(buffer, x0 - y, y0 - x);
	}
}

int fycalc (int y, int fy, int f)
{
	if (f >= 0) {
		y--;
		fy += 2;
		f += fy;
	}
	return (y, fy, f);
}
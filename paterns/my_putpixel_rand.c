/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../draw_a_line.h"

t_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    t_framebuffer *framebuffer = malloc(sizeof(t_framebuffer));
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 4);
    return(framebuffer);
}

void my_putpixel_rand(void)
{
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_create(800, 600);
    sfVideoMode video_mode = {800, 600, 32};
    t_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfEvent event;
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);;
    window = sfRenderWindow_create(video_mode,
                                   "window",
                                   sfResize | sfClose,
                                   NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    
    while (sfRenderWindow_isOpen(window)) {
        sfTexture_updateFromPixels(texture,
                                   framebuffer->pixels,
                                   framebuffer->width,
                                   framebuffer->height,
                                   0, 0);
	sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        put_pixel(framebuffer);
    }
    sfRenderWindow_destroy(window);
}

int put_pixel(t_framebuffer *buffer)
{
    int x = random_x();
    int y = random_y();
    int i = 4 * (y * buffer->width + x);

    buffer->pixels[i]  = 0;
    buffer->pixels[i + 1] = 255;
    buffer->pixels[i + 2] = 0;
    buffer->pixels[i + 3] = 255;
}

int random_x()
{
    srand(time(NULL));
	int z = rand();

	z = rand() % 800 + 1;
	return(z);
}

int random_y()
{
	int z = rand();

	z = rand() % 600 + 1;
    if (z < 0)
        z *= -1;
	return(z);
}

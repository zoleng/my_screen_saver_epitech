/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2018
** File description:
** spiral
*/

#include "draw_a_line.h"
#include <math.h>

void draw_a_spiral(void)
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
     my_put_spiral(framebuffer);
    }
    sfRenderWindow_destroy(window);
}

void my_put_spiral(t_framebuffer *buffer)
{
    int xcenter = random_x();
    int ycenter = random_y();
    static int i = 0;
    int radius = 20 + i;
    int x = 0;
    int y = radius;
    int p = 2 - 2 * radius;
    
    if (i > random_z())
        i = 0;
    i = i + 5;
    while (x < y) {
        if (p < 0) {
            x = x + 1;
            p = p + 4 * x + 6;
        } else {
            x = x + 1;
            y = y - 1;
            if (y < 0)
                y *= -1;
                p = p + 4 * (x - y) + 10;

        }
        pixel (buffer, xcenter, ycenter, x, y);
    }
}

int random_z()
{
    srand(time(NULL));
    return(rand() % (100));
}
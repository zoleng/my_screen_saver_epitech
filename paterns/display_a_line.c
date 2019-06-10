/*
** EPITECH PROJECT, 2018
** deisplay line
** File description:
** display line
*/

#include "../draw_a_line.h"

void my_putline_rand(void)
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
        draw_line(framebuffer);
    }
    sfRenderWindow_destroy(window);
}

void draw_line(t_framebuffer *buffer)
{
    int x1 = random_x();
    int x2 = random_x();
    int y1 = random_y();
    int y2 = random_y();
    int abs_x = abs(x1 - x2);
    int abs_y = abs(y1 - y2);
    int pixel = 0;

    if(abs_x >= abs_y)
        pixel = abs_x;
    else
        pixel = abs_y;
    abs_x = abs_x / pixel;
    abs_y = abs_y / pixel;
    while(pixel != 0)
    {
        my_put_pixel(buffer, x1, y1);
        x1 = x1 + abs_x;
        y1 = y1 + abs_y;
        pixel = pixel - 1;
    }
}

int my_put_pixel(t_framebuffer *buffer, int x, int y)
{
    srand(time(NULL));
    int i = 4 * (y * buffer->width + x);

    buffer->pixels[i]  = rand() % 255;
    buffer->pixels[i + 1] = rand() % 255;
    buffer->pixels[i + 2] = rand() % 255;
    buffer->pixels[i + 3] = 255;
}

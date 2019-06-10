/*
** EPITECH PROJECT, 2018
** draw a circle
** File description:
** draw a circle
*/

#include "../draw_a_line.h"

void draw_a_circle(void)
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
     my_put_circle(framebuffer);
    }
    sfRenderWindow_destroy(window);
}

void my_put_circle(t_framebuffer *buffer)
{
    int xcenter = random_x();
    int ycenter = random_y();
    int radius = random_y();
    int x = 0;
    int y = radius;
    int p = 2 - 2 * radius;

    while (x < y) {
        if (p < 0) {
            x = x + 1;
            p = p + 4 * x + 6;
        } else {
            x = x + 1;
            y = y - 1;
            p = p + 4 * (x - y) + 10;
        }
        pixel (buffer, xcenter, ycenter, x, y);
    }
}

void pixel(t_framebuffer *buffer, int xc, int yc, int x, int y)
{
    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    putpixel(buffer, xc+x, yc+y);
    putpixel(buffer, xc+x, yc-y);
    putpixel(buffer, xc-x, yc+y);
    putpixel(buffer, xc-x, yc-y);
    putpixel(buffer, xc+y, yc+x);
    putpixel(buffer, xc+y, yc-x);
    putpixel(buffer, xc-y, yc+x);
    putpixel(buffer, xc-y, yc-x);
}

int putpixel(t_framebuffer *buffer, int x, int y)
{
    srand(time(NULL));
    int i = 4 * (y * buffer->width + x);

    if (i < 0)
        i *= -1;
    buffer->pixels[i]  = rand() % 255;
    buffer->pixels[i + 1] = rand() % 255;
    buffer->pixels[i + 2] = rand() % 255;
    buffer->pixels[i + 3] = 255;
}

/*
** EPITECH PROJECT, 2019
** texture
** File description:
** texture
*/

void texture(void)
{
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_create(800, 600);
    sfVideoMode video_mode = {800, 600, 32};
    t_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfEvent event;
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    window = sfRenderWindow_create(video_mode,
                                   "window",
                                   sfResize | sfClose,
                                   NULL);
    sfRenderWindow_setFramerateLimit(window, 1160);
}
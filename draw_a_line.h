/*
** EPITECH PROJECT, 2019
** .h
** File description:
** .h
*/

#ifndef DRAW_A_LINE_H_
#define DRAW_A_LINE_H_
#define ERROR 84
#define EXIT_HELP 1
#define EXIT_OPTIONS 2
#define EXIT 0

#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;

void my_put_circle(t_framebuffer *buffer);
void my_put_spiral(t_framebuffer *buffer);
void pixel(t_framebuffer *buffer, int xc, int yc, int x, int y);
int putpixel(t_framebuffer *buffer, int x, int y);
void my_putchar(char c);
void option(void);
void id(void);
int my_putstr(char const *str);
void draw_a_circle(void);
void draw_a_spiral(void);
void my_putline_rand(void);
int my_put_pixel(t_framebuffer *buffer, int x, int y);
int main(int ac, char **av);
t_framebuffer *framebuffer_create(unsigned int width, unsigned int height);
int random_y();
int random_x();
int radius();
void draw_line(t_framebuffer *buffer);
int randomnumber();
int animation(char *animation);
void my_putpixel_rand(void);
int put_pixel(t_framebuffer *buffer);
int random_z();

void square(void);
void my_put_square(t_framebuffer *buffer);

void texture(void);

#endif

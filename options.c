/*
** EPITECH PROJECT, 2018
** option.c
** File description:
** oprtin.c
*/

#include "draw_a_line.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str) {
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

void option(void)
{
    my_putstr("Animation in csfml\n");
    my_putstr("4 different animation\n");
}

void id(void)
{
    my_putstr("different animation\n");
    my_putstr("1 : random pixel on the screen\n");
    my_putstr("2 : random lines on the screen\n");
    my_putstr("3 : random circles on the screen\n");
    my_putstr("4 : beautiful spirals on your screen\n");
    my_putstr("5 : random squares on the screen\n");
}

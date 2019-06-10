/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "draw_a_line.h"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-') {
        if (av[1][1] == 'h')
            option();
        else if (av[1][1] == 'd')
            id();
        else
            return (84);
    }
    animation(av[1]);
}

int animation(char *animation)
{
    if (animation[0] == '1')
        my_putpixel_rand();
    if (animation[0] == '2')
        my_putline_rand();
    if (animation[0] == '3')
        draw_a_circle();
    if (animation[0] == '4')
        draw_a_spiral();
    if(animation[0] == '5')
        square();
    else
        return (84);
}


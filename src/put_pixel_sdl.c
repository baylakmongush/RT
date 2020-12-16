/*
 * Filename: /Users/Student/mandelbrot/put_pixel_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 11:13:05 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "rt.h"

int		get_color(t_color color)
{
	return (color.r << 16) | (color.g << 8) | color.b;
}

void    put_pixel_sdl(t_rt rt_struct, int x, int y, t_color color)
{
    if (x > 0 && x <= SCREEN_WIDTH && y > 0 && y <= SCREEN_HEIGHT)
    {
        rt_struct.pixels[y * SCREEN_WIDTH + x] = get_color(color);
    }
}
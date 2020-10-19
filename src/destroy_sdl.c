/*
 * Filename: /Users/Student/mandelbrot/destroy_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 10:59:35 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "rt.h"

void	destroy_sdl(t_rt rt_struct)
{
	SDL_DestroyTexture(rt_struct.texture);
    SDL_DestroyRenderer(rt_struct.renderer);
    SDL_DestroyWindow(rt_struct.win);
    SDL_Quit();
}
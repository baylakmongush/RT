/*
 * Filename: /Users/Student/mandelbrot/init_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 10:42:02 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "rt.h"

t_rt		init_sdl()
{
	t_rt	rt_struct;

	SDL_Init(SDL_INIT_EVERYTHING);
    rt_struct.win = SDL_CreateWindow("SDL2 Pixel Drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	rt_struct.renderer = SDL_CreateRenderer(rt_struct.win, -1, 0);
   	rt_struct.texture = SDL_CreateTexture(rt_struct.renderer,
        SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
    rt_struct.pixels = malloc(sizeof(Uint32) * 640 * 480);//new Uint32[640 * 480];
    memset(rt_struct.pixels, 255, 640 * 480 * sizeof(Uint32));
	return (rt_struct);
}
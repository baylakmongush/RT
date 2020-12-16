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
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	rt_struct.renderer = SDL_CreateRenderer(rt_struct.win, -1, SDL_RENDERER_ACCELERATED);
   	rt_struct.texture = SDL_CreateTexture(rt_struct.renderer,
        SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    rt_struct.pixels = malloc(sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);//new Uint32[640 * 480];
    memset(rt_struct.pixels, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    SDL_Surface *image;
    image = IMG_Load("src/sample.png");
	rt_struct.background = SDL_CreateTextureFromSurface(rt_struct.renderer, image);
	return (rt_struct);
}
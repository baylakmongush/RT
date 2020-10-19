/*
 * Filename: /Users/Student/mandelbrot/main.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 9:35:08 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "rt.h"
#include <stdio.h>

int             main()
{
    size_t			local = 64;
    t_rt       rt_struct;
	size_t			global[] = {640, 480};
    t_color     color;
    t_cl        cl;

    rt_struct = init_sdl();
    cl = init_cl();
    cl.data = clCreateBuffer(cl.context, CL_MEM_WRITE_ONLY, 640 * 480 * sizeof(Uint32), NULL, &cl.err);
    cl.err  = clSetKernelArg(cl.kernel, 0, sizeof(cl_mem), &cl.data);
    cl.err = clEnqueueNDRangeKernel(cl.commands, cl.kernel, 1, NULL, global, NULL, 0, 0, 0);
    cl.err = clEnqueueReadBuffer(cl.commands, cl.data, CL_TRUE, 0, 640 * 480 * sizeof(Uint32), rt_struct.pixels, 0, NULL, NULL);
   /* if (!cl.err)
    {
        printf("ERROR\n");
        exit(0);
    }*/

    rt_struct.is_running = 1;
    while (rt_struct.is_running) {
        SDL_UpdateTexture(rt_struct.texture, NULL, rt_struct.pixels, 640 * sizeof(Uint32));
        while (SDL_PollEvent(&rt_struct.event)) {
            if (rt_struct.event.type == SDL_QUIT || rt_struct.event.key.keysym.sym == SDLK_ESCAPE) {
                rt_struct.is_running = 0;
       		}
    	}
        SDL_RenderClear(rt_struct.renderer);
        SDL_RenderCopy(rt_struct.renderer, rt_struct.texture, NULL, NULL);
        SDL_RenderPresent(rt_struct.renderer);
	}
    clFinish(cl.commands);
	clReleaseMemObject(cl.data);
    clReleaseCommandQueue(cl.commands);
    clReleaseContext(cl.context);
    destroy_sdl(rt_struct);
    return (0);
}
__kernel void test(__global int* pixels)
{
	int x = get_global_id(0);
    int y = get_global_id(1);
    int i = 0;
    int j = 0;
    i = 0;
    while (i < x % 480)
    {
        j = 0;
        while (j < x)
        {
            pixels[i * 640 + j] = 0xfff000;
            j++;
        }
        i++;
    }
}
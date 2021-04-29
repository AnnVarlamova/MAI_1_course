#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int min(int a, int b)
{
    if (a < b) return a;
    return b;
}

int main (int* height, int heightSize){
    int area = 0;
    int tmp1 = 0;
    int tmp2 = heightSize - 1;

    while(tmp1 <= tmp2)
    {
        area = max(area, min(height[tmp1], height[tmp2]) * (tmp2 - tmp1));
        if(height[tmp1] < height[tmp2])
            tmp1++;

        else
            tmp2--;
    }

    return area;
}

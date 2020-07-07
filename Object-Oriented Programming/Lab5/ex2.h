#include <stdlib.h>
#include <algorithm>
#ifndef ex2
#define ex2

template <typename T>
void bSort(T array[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=size-1;i<j;j--)
        {
            if(array[j]<array[j-1])
            {
                std::swap(array[j],array[j-1]);
            }
        }
    }
}
    

#endif
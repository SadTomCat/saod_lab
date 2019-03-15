#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE 1000000

void  quick(uint32_t *arr, uint32_t first, uint32_t last);

void swap(uint32_t *arr, uint32_t elm1, uint32_t elm2)
{
    uint32_t tmp = arr[elm1];
    arr[elm1] = arr[elm2];
    arr[elm2] = tmp;
}

int main()
{   
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];

    for( uint32_t i = 0; i < ARR_SIZE; i++) 
    {
        arr[i] = rand() % 100000;
    }
    
    float StartTime = time(NULL);
    quick(arr, 0, ARR_SIZE - 1);
    float EndTime = time(NULL);
    printf("%f seconds\n", EndTime - StartTime);

    return 0;
}

void quick( uint32_t *arr,  uint32_t first,  uint32_t last) 
{
     uint32_t left = first;
     uint32_t right = last;
     uint32_t pivot = arr[((last - first) / 2) + left];

    while(left <= right)
    {
        while(arr[left] < pivot)
            left++;
        while(pivot < arr[right])
            right--;
        if(left <= right)
        {
            swap(arr, right, left);
            left++;
            right--;
        }
    }

    if(first < right)
        quick(arr, first, right);
    if(left < last)
        quick(arr, left, last);
}


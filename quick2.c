#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>

#define ARR_SIZE 1000

uint32_t i;

uint32_t part(uint32_t *arr, uint32_t low, uint32_t high);
void quick(uint32_t *arr, uint32_t low, uint32_t high);
double wtime();


int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];

    for( uint32_t i = 0; i < ARR_SIZE; i++) 
    {
        arr[i] = rand() % 100000;
    }
    
    long double StartTime = wtime();
    quick(arr, 0, ARR_SIZE - 1);
    long double EndTime = wtime();
    printf("%Lf seconds\n", EndTime - StartTime);

    return 0;
}

//quick
void quick(uint32_t *arr, uint32_t low, uint32_t high)
{
    if(low < high)
    {
       uint32_t p = part(arr, low, high);
       quick(arr, low, p - 1);
       quick(arr, p + 1, high);
    }
}

//part
uint32_t part(uint32_t *arr, uint32_t low, uint32_t high)
{
    uint32_t pivot = arr[high];
    i = low;
    for(uint32_t j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            uint32_t tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    uint32_t tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    return i;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
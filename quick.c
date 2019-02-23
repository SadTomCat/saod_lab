#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE 100

int quicks(uint32_t *arr)
{

}

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];

    //заполнение массива 
    for(int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % 10000;
    }

    return 0;
}
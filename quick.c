#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define ARR_SIZE 11
#define F 12.00

//сортировка 
int qsort(int *p_arr)
{
    printf("%d", *p_arr);
    return *p_arr;
}

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE]; //неотсортированный массив

    //заполнение массива 
    for(int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand()%30;
    }
    qsort(arr[ARR_SIZE / 2]);
    printf("%d", qsort(arr[ARR_SIZE / 2]));

}
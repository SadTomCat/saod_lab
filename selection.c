#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE 1000000

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE]; //неотсортированный массив
    uint32_t swap;   //переменная нужная для обмена 
    uint32_t min;  //указавает на элемент с которым произойдет обмен 

    //заполнение массива 
    for(int i = 0; i < ARR_SIZE; i++) 
    {
        arr[i] = rand()%100000;
    }

    signed long long int StartTime = time(NULL);
    //сортировка
    for(int i = 0; i < ARR_SIZE - 1; i++) 
    {
        min = i;
        int search = i + 1;

        while(search < ARR_SIZE) 
        {
            if(arr[min] > arr[search])
            {
                min = search;
            }
            search++;
        }

        swap = arr[i];
        arr[i] = arr[min];
        arr[min] = swap;
    }
    signed long long int EndTime = time(NULL);
    printf("%lli seconds\n", EndTime - StartTime);

    return 0; 
}
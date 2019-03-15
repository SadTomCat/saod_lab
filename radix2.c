#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define ARR_SIZE 1000000
#define NUM 10

void CountSort(uint32_t *arr, uint32_t exp);
uint32_t i;

void print(uint32_t *arr, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test(uint32_t *arr)
{
  
    uint32_t good = 0;
    for (uint32_t i = 0; i < ARR_SIZE - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            good++;
    }
    printf("\n");
    if (good == ARR_SIZE - 1)
        printf("good\n");
    else
        printf("bad job man\n");
}


int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];
    uint32_t max = 0;
    
    for( i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = rand() % 100000;
        if(arr[i] > max)
            max = arr[i];  
    }

    printf("%d\n", max);

    for(uint32_t i = 1; max / i > 0; i *= 10)
    {

        CountSort(arr, i);
    }

    test(arr);

    return 0;
}

void CountSort(uint32_t *arr, uint32_t exp)
{
    uint32_t NewArr[ARR_SIZE] = {0};
    uint32_t CountArr[NUM] = {0};

    for(i = 0; i < ARR_SIZE; i++)
    {
        CountArr[(arr[i] / exp) % 10]++;
    }
    
    for(i = 1; i < NUM; i++)
    {
        CountArr[i] += CountArr[i - 1];
    }
    
    for(i = ARR_SIZE - 1; i > 0; i--)
    {
        NewArr[CountArr[(arr[i] / exp) % 10] - 1] = arr[i];
        CountArr[(arr[i] / exp) % 10]--;
    }

    NewArr[CountArr[(arr[0] / exp) % 10] - 1] = arr[0];
    


    for(i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = NewArr[i];
    }  

}

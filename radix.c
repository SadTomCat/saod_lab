#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define ARR_SIZE 1000000
#define NUM 10

void CountSort(uint32_t *arr, uint32_t exp);

void test(uint32_t *arr)
{

    uint32_t good = 0;
    for (uint32_t i = 0; i < ARR_SIZE - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            good++;
    }

    if (good == ARR_SIZE - 1)
        printf("good\n");
    else
        printf("bad job man\n");
}

void print(uint32_t *arr, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];
    uint32_t max = 0;
    
    for(uint32_t i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = rand() % 100000;
        if(arr[i] > max)
            max = arr[i];  
    }

    float StartTime = time(NULL);
    for(int i = 1; max/i > 0; i *= 10)
    {
        CountSort(arr, i);
    }
    float EndTime = time(NULL);
    printf("%f seconds\n", EndTime - StartTime);

    test(arr);

    return 0;
}

void CountSort(uint32_t *arr, uint32_t exp)
{
    uint32_t CountArr[NUM] = {0};
    uint32_t NewArr[ARR_SIZE] = {0};
    
    for(uint32_t i = 0; i < ARR_SIZE; i++)
        CountArr[(arr[i] / exp) % 10]++;
    
    uint32_t index = 0;
    for(uint32_t i = 0; i < NUM; i++)
    {
        if(CountArr[i] > 0)
        {
            for(uint32_t j = 0; j < ARR_SIZE; j++)
            {
                if((arr[j] / exp) % 10 == i)
                {
                    NewArr[index] = arr[j];
                    index++;
                }
            }
        }
    } 

    for(uint32_t i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = NewArr[i];

    }  


}
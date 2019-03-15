#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE 100000

void selection(uint32_t *arr); 
void test(uint32_t *arr);

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE]; 
    
    for(int i = 0; i < ARR_SIZE; ++i) 
    {
        arr[i] = rand() % 100000;
    }

    signed long long int StartTime = time(NULL); 
    selection(arr);
    signed long long int EndTime = time(NULL);
    printf("%lli seconds\n", EndTime - StartTime);
    test(arr);

    return 0; 
}

void selection(uint32_t *arr) 
{
    int min, search, i;
    uint32_t tmp;

    for(i = 0; i < ARR_SIZE; ++i)  
    {
        min = i;
        search = i + 1;
        while(search < ARR_SIZE) 
        {
            if(arr[min] > arr[search]) 
            {
                min = search;
            }
            ++search;
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void test(uint32_t *arr)
{
    uint32_t good = 0;
    for(uint32_t i = 0; i < ARR_SIZE; i++)
    {
        if(arr[i] <= arr[i + 1])
            good++;
    }
    if(good == ARR_SIZE)
        printf("good\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE 10000

void selection(uint32_t *arr);

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE]; 
  
    for(uint32_t i = 0; i < ARR_SIZE; i++) 
    {
        arr[i] = rand()%100000;
    }

    signed long long int StartTime = time(NULL);
	selection(arr);
    signed long long int EndTime = time(NULL);
    printf("%lli seconds\n", EndTime - StartTime);
    
    uint32_t good = 0;
    for(uint32_t i = 0; i < ARR_SIZE; i++)
    {
		if(arr[i] <= arr[i + 1])
		{
			good++;
		}
	}
	if(good == ARR_SIZE)
		printf("\ngood\n");

    return 0; 
}

void selection(uint32_t *arr)
{
	uint32_t min; 
    uint32_t search;
    uint32_t tmp;
    
	for(uint32_t i = 0; i < ARR_SIZE - 1; i++) 
    {
        min = i;
        search = i + 1;

        while(search < ARR_SIZE) 
        {
            if(arr[min] > arr[search])
            {
                min = search;
            }
            search++;
        }

        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define ARR_SIZE 1000000

void quicks(uint32_t *arr, uint32_t first, uint32_t last);

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];

    for(uint32_t i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
    
    signed long long int StartTime = time(NULL);
    quicks(arr, 0, ARR_SIZE - 1);
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
    signed long long int EndTime = time(NULL);
    printf("%lli seconds\n", EndTime - StartTime);
    
}

void  quicks(uint32_t *arr, uint32_t first, uint32_t last)
{
	uint32_t left = first;
	uint32_t right = last;
	uint32_t pivot = arr[(right + left) / 2];
	uint32_t tmp;
	
	while(left <= right)
	{
		while(arr[left] < pivot)
			left++;
		while(pivot < arr[right])
			right--;
		if(left <= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
	
	if(right > first)
		quicks(arr, first, right);
	if(last > left)
		quicks(arr, left, last);
}

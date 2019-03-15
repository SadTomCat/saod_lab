#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define ARR_SIZE 850000
#define NUM 10

uint32_t i;

double wtime();
void test(uint32_t *arr);
void swap(uint32_t *arr, uint32_t elm1, uint32_t elm2);
void selection(uint32_t *arr); 
void radix(uint32_t *arr, uint32_t exp);
void quick(uint32_t *arr, uint32_t first, uint32_t last);

int main()
{
    srand(time(NULL));
    uint32_t arr[ARR_SIZE];
    long double start_time, end_time;

    //selection sort
    for (i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = rand() % 100000;
    }

    start_time = wtime(); 
    //selection(arr);
    end_time = wtime();
    printf("selection: %Lf seconds\n", end_time - start_time);
    test(arr);

    //quick sort
    srand(time(NULL));
    for (i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = rand() % 100000;
    }

    start_time = wtime(); 
    quick(arr, 0, ARR_SIZE - 1);
    end_time = wtime();
    printf("quick: %Lf seconds\n", end_time - start_time);
    test(arr);

    //radix sort
    srand(time(NULL));
    uint32_t max = 0;
    for (i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = rand() % 100000;
        if(arr[i] > max)
            max = arr[i];
    }

    start_time = wtime(); 
    for(uint32_t i = 1; max / i > 0; i *= 10)
    {
        radix(arr, i);
    }
    end_time = wtime();
    printf("radix: %Lf seconds\n", end_time - start_time);
    test(arr);

    return 0;
}

//selection sort
void selection(uint32_t *arr) 
{
    uint32_t min, search, i;

    for (i = 0; i < ARR_SIZE; ++i)  
    {
        min = i;
        search = i + 1;
        while (search < ARR_SIZE) 
        {
            if (arr[min] > arr[search]) 
            {
                min = search;
            }
            ++search;
        }
        swap(arr, i, min);
    }
}

//quick sort
void quick(uint32_t *arr, uint32_t first, uint32_t last) 
{
    uint32_t left = first;
    uint32_t right = last;
    uint32_t pivot = arr[((last - first) / 2) + left];

    while (left <= right)
    {
        while (arr[left] < pivot)
            left++;
        while (pivot < arr[right])
            right--;
        if (left <= right) {
            swap(arr, right, left);
            left++;
            right--;
        }
    }

    if (first < right)
        quick(arr, first, right);
    if (left < last)
        quick(arr,left, last);
}

//radix
void radix(uint32_t *arr, uint32_t exp)
{
    uint32_t count_arr[NUM] = {0};
    uint32_t add_arr[ARR_SIZE] = {0};

    for(i = 0; i < ARR_SIZE; i++)
        count_arr[(arr[i] / exp) % 10]++;

    for(i = 1; i < NUM; i++)
        count_arr[i] += count_arr[i - 1];
    
    for(i = ARR_SIZE - 1; i > 0; i--)
    {
        add_arr[count_arr[(arr[i] / exp) % 10] - 1] = arr[i];
        count_arr[(arr[i] / exp) % 10]--;
    }
    add_arr[count_arr[(arr[0] / exp) % 10] - 1] = arr[0];

    for(i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = add_arr[i];
    }  
}

//next three functions are swap, test and wtime
void swap(uint32_t *arr, uint32_t elm1, uint32_t elm2)
{
    uint32_t tmp = arr[elm1];
    arr[elm1] = arr[elm2];
    arr[elm2] = tmp;
}

void test(uint32_t *arr)
{
    uint32_t good = 0;
    for (i = 0; i < ARR_SIZE - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            good++;
    }
    if (good == ARR_SIZE - 1)
        printf("good\n");
    else
        printf("bad job man\n");
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

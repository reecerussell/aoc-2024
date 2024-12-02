#include <stdlib.h>
#include <stdio.h>
#include "problem_01.h"

int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort(int arr[], int size)
{
    qsort(arr, size, sizeof(int), comp);
}

int reconcile(int a[], int b[], int size)
{
    sort(a, size);
    sort(b, size);

    int distance = 0;

    for (int i = 0; i < size; i++)
    {
        int sub_distance = abs(a[i] - b[i]);

        printf("%d - %d == %d (total=%d)\n", a[i], b[i], sub_distance, distance);

        distance += sub_distance;
    }

    return distance;
}

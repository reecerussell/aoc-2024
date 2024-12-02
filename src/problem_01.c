#include <stdlib.h>
#include "problem_01.h"
#include "common/int_dict.h"

static int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

static void sort(int arr[], int size)
{
    qsort(arr, size, sizeof(int), comp);
}

int calc_distance(int a[], int b[], int size)
{
    sort(a, size);
    sort(b, size);

    int distance = 0;

    for (int i = 0; i < size; i++)
    {
        int sub_distance = abs(a[i] - b[i]);

        distance += sub_distance;
    }

    return distance;
}

int calc_similarity(int a[], int b[], int size)
{
    IntDict *occurances = create_int_dict();
    for (int i = 0; i < size; i++)
    {
        int current = get_int_node(occurances, b[i]);
        insert_int_node(occurances, b[i], current + 1);
    }

    int score = 0;
    for (int i = 0; i < size; i++)
    {
        int n = get_int_node(occurances, a[i]);
        score += a[i] * n;
    }

    // Clean up dict
    free_int_dict(occurances);

    return score;
}
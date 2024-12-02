#include <assert.h>
#include <stdio.h>

#include "../src/problem_01.h"

int read_file(int **col1, int **col2, int *size)
{
    FILE *file = fopen("inputs/01.txt", "r");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int capacity = 10; // Initial capacity
    *col1 = malloc(capacity * sizeof(int));
    *col2 = malloc(capacity * sizeof(int));
    if (!*col1 || !*col2)
    {
        perror("Error allocating memory");
        fclose(file);
        return -1;
    }

    *size = 0;
    int num1, num2;
    while (fscanf(file, "%d %d", &num1, &num2) == 2)
    {
        // Resize arrays if necessary
        if (*size >= capacity)
        {
            capacity *= 2;
            *col1 = realloc(*col1, capacity * sizeof(int));
            *col2 = realloc(*col2, capacity * sizeof(int));
            if (!*col1 || !*col2)
            {
                perror("Error reallocating memory");
                fclose(file);
                return -1;
            }
        }
        (*col1)[*size] = num1;
        (*col2)[*size] = num2;
        (*size)++;
    }

    fclose(file);
    return 0; // Success
}

int main()
{
    int *col1 = NULL, *col2 = NULL;
    int size = 0;

    if (read_file(&col1, &col2, &size) == 0)
    {
        int distance = reconcile(col1, col2, size);

        printf("Distance: %d\n", distance);

        // Free allocated memory
        free(col1);
        free(col2);
    }
    else
    {
        printf("Failed to read the file.\n");
    }

    // assert(distance == 11);

    return 0;
}

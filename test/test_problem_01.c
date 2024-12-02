#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/problem_01.h"

static int read_file(int **col1, int **col2, int *size)
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
        int distance = calc_distance(col1, col2, size);

        printf("Distance: %d\n", distance);

        assert(distance == 1222801);

        int sim_score = calc_similarity(col1, col2, size);
        printf("Similarity score: %d\n", sim_score);

        assert(sim_score == 22545250);

        // Free allocated memory
        free(col1);
        free(col2);

        return 0;
    }
    else
    {
        printf("Failed to read the file.\n");

        return 1;
    }
}

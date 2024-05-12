#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Comparator function for sorting in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int i;
    int randomNumber;

    // Seed the random number generator
    srand(time(NULL));

    // Open a file for writing
    FILE *file = fopen("numbers_desc.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int numbers[1000000];
    for(i = 0; i < 1000000; i++) {
        // Generate a random number between 0 and 200, then subtract 100
        randomNumber = rand() % 201 - 100;
        numbers[i] = randomNumber;
    }

    // Sort the array in descending order
    qsort(numbers, 10000, sizeof(int), compare);

    // Write sorted numbers to file
    for(i = 0; i < 10000; i++) {
        fprintf(file, "%d ", numbers[i]); // Write to file with space as separator
    }

    // Close the file
    fclose(file);

    printf("Random numbers written to file in descending order successfully.\n");

    return 0;
}

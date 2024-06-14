#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

// Function prototypes
void generateArray(int array[], int size);
void printArray(const int array[], int size);
void bubbleSort(int array[], int size);

int main()
{
    int array[N];

    // Initialize the random number generator
    srand(time(NULL));

    // Generate and print the array
    generateArray(array, N);
    printArray(array, N);

    // Sort the array using bubble sort and print it again
    bubbleSort(array, N);
    printf("\n\nSorted Array:\n");
    printArray(array, N);

    return 0;
}

// Function to generate an array with random numbers
void generateArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
}

// Function to print the elements of an array
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }
}

// Function to sort an array using bubble sort
void bubbleSort(int array[], int size)
{
    for (int pass = 1; pass < size; pass++)
    {
        for (int i = 0; i < size - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

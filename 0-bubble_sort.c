#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               bubble sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array (size_t is an unsigned integer type)
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the array to be printed
 * @size: Number of elements in the array (size_t is an unsigned integer type)
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

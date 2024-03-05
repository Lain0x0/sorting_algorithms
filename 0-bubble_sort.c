#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @x: 1st integer to swap.
 * @y: 2nd integer to swap.
 */
void swap_int(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(array + j, array + j + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}

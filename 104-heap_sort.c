#include "sort.h"

void swaps_int(int *y, int *z);
void max_heapfy(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swaps_int - Swap two integers in an array.
 * @y: The first integer to swap.
 * @z: The second integer to swap.
 */
void swaps_int(int *y, int *z)
{
	int tmp;

	tmp = *y;
	*y = *z;
	*z = tmp;
}

/**
 * max_heapfy - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapfy(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swaps_int(array + root, array + large);
		print_array(array, size);
		max_heapfy(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapfy(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swaps_int(array, array + i);
		print_array(array, size);
		max_heapfy(array, size, i, 0);
	}
}

#include "sort.h"

/**
 *swap - Swaps two values
 *
 *@a: First num
 *@b: Second num
 *
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 *partition - Partions the array
 *
 *@array: The array
 *@low: Lower bound
 *@high: Higher bound
 *@size: Size of the list
 *
 *Return: Index of the partition
*/
int partition(int *array, int low, int high, size_t size)
{
	int *pivot, i, j;

	pivot = array + high;
	i = j = low;
	while (j < high)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
		j++;
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}
/**
* quick_sort_main - A helper function for our quick_sort
*		    function
*
* @array: The array to be sorted
* @low: Lower bound
* @high: Higher bound
* @size: Size of the array
*/
void quick_sort_main(int *array, int low, int high, size_t size)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, low, high, size);
		quick_sort_main(array, low, part - 1, size);
		quick_sort_main(array, part + 1, high, size);
	}
}
/**
* quick_sort - Implements the quicksort algorithm using the Lomuto partition
*	       scheme which sorts an array of integers
*
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_main(array, 0, size - 1, size);
}

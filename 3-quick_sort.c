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
 *
 *Return: Index of the partition
*/
int partition(int *array, int low, int high)
{
	int i = low - 1, j, pivot;

	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array + i, array + j);
			print_array(array, high + 1);
		}
	}
	swap(array + i + 1, array + high);
	print_array(array, high + 1);
	return (i + 1);
}
/**
* quick_sort_main - A helper function for our quick_sort
*		    function
*
* @array: The array to be sorted
* @low: Lower bound
* @high: Higher bound
*/
void quick_sort_main(int *array, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high);
		quick_sort_main(array, low, part - 1);
		quick_sort_main(array, part + 1, high);
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
	quick_sort_main(array, 0, size - 1);
}

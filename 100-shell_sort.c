#include "sort.h"

/**
* swap - Swaps two values
*
* @p: First value
* @q: Second value
*/
void swap(int *p, int *q)
{
	int tmp = *p;

	*p = *q;
	*q = tmp;
}
/**
* insertion_sort - Performs the insertion sort
*
*@array: The array to be sorted
*@size: Size of the array
*@gap: Point in which sorting should start
*/
void insertion_sort(int *array, size_t size, size_t gap)
{
	size_t i, j;

	for (i = gap; i < size; i++)
	{
		j = i;
		while (j >= gap && array[j - gap] > array[j])
		{
			swap(array + j, array + (j - gap));
			j -= gap;
		}
	}
}
/**
* get_gap - Calculates the gap value until it is less than one-third
*	    of the size of the array
*
*@size: Size of the array
*
*Return: The gap
*/
size_t get_gap(size_t size)
{
	size_t gap;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	return (gap);
}
/**
* shell_sort - Implements the shell sort algorithm which sorts
*		an array of integers
*
* @array: The array to be sorted
* @size: Size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap;

	if (!array || size < 2)
		return;
	for (gap = get_gap(size); gap >= 1; gap /= 3)
	{
		insertion_sort(array, size, gap);
		print_array(array, size);
	}
}

#include "sort.h"

/**
* swap - Swap two values
*
* @p: First num
* @q: Second num
*/
void swap(int *p, int *q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}
/**
* selection_sort - Implements the selection sort algorithm
*		   which sorts the elements of an array
*
*@array: The array to be sorted
*@size: Size of the array
*/
void selection_sort(int *array, size_t size)
{
	int *min_idx;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;

		if ((array + i) != min_idx)
		{
			swap(array + i, min_idx);
			print_array(array, size);
		}
	}
}

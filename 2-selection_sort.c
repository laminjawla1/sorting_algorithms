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
	size_t i, j, num_pos;
	int tmp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		num_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[num_pos])
				num_pos = j;
		}
		if (i != num_pos)
		{
			tmp = array[i];
			array[i] = array[num_pos];
			array[num_pos] = tmp;
			print_array(array, size);
		}
	}
}

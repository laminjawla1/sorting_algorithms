#include "sort.h"

/**
 * swap - Swaps two values
 *
 *@p: Array one
 *@q: Array two
 *
 */
void swap(int *p, int *q)
{
	int tmp = *p;

	*p = *q;
	*q = tmp;
}
/**
* bubble_sort - Sorts elements using the bubble
*		sort algorithm
*
* @array: The array to be sorted
* @size: Size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array + j, array + j + 1);
			print_array(array, size);
		}
	}
}

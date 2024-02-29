#include "binary_trees.h"

/**
 * array_to_heap - Make a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array
 * @size: the number of element in the array
 *
 * Return: a pointer to the dRoot node
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *dRoot = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&dRoot, array[i]);

	return (dRoot);
}
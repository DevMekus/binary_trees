#include "binary_trees.h"

/**
 * array_to_bst - Binary search tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node 
 * 			Else: NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *binaryTree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (bst_insert(&binaryTree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (binaryTree);
}

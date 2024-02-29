#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: Pointer to the root node
 * @value: The value to search
 *
 * Return: If the tree is NULL , NULL.
 *         Else, a pointer to the node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}

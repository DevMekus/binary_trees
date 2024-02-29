#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: pointer to the root node
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivotPoint, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivotPoint = tree->right;
	temp = pivotPoint->left;
	pivotPoint->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivotPoint;
	pivotPoint->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivotPoint;
		else
			temp->right = pivotPoint;
	}

	return (pivotPoint);
}

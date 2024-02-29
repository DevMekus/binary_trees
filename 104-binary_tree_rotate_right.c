#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: pointer to the root node
 *
 * Return: A pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivotPoint, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivotPoint = tree->left;
	temp = pivotPoint->right;
	pivotPoint->right = tree;
	tree->left = temp;
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

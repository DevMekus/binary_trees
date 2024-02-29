#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t treeSize = 0;

	if (tree)
	{
		treeSize += 1;
		treeSize += binary_tree_size(tree->left);
		treeSize += binary_tree_size(tree->right);
	}
	return (treeSize);
}

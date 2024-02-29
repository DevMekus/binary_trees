#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child
 * @tree: A pointer to the root node
 * Return: If tree is NULL, return 0,
 * 			else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t treeNode = 0;

	if (tree)
	{
		treeNode += (tree->left || tree->right) ? 1 : 0;
		treeNode += binary_tree_nodes(tree->left);
		treeNode += binary_tree_nodes(tree->right);
	}
	return (treeNode);
}

#include "binary_trees.h"

/**
 * create_tree - Builds an AVL tree via recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middleNode;

	if (size == 0)
		return;

	middleNode = (size / 2);
	middleNode = (size % 2 == 0) ? middleNode - 1 : middleNode;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middleNode]);
		create_tree(&((*node)->left), array, middleNode, 1);
		create_tree(&((*node)->left), array + middleNode + 1, (size - 1 - middleNode), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middleNode]);
		create_tree(&((*node)->right), array, middleNode, 1);
		create_tree(&((*node)->right), array + middleNode + 1, (size - 1 - middleNode), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rootNode;
	size_t middleNode;

	rootNode = NULL;

	if (size == 0)
		return (NULL);

	middleNode = (size / 2);

	middleNode = (size % 2 == 0) ? middleNode - 1 : middleNode;

	rootNode = binary_tree_node(rootNode, array[middleNode]);

	create_tree(&rootNode, array, middleNode, 1);
	create_tree(&rootNode, array + middleNode + 1, (size - 1 - middleNode), 2);

	return (rootNode);
}
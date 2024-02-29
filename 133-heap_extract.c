#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_height(tree->left);

	if (tree->right)
		right_height = 1 + tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
/**
 * tree_size_h - sum of heights of a binary tree
 * @tree: pointer to the root node
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_size_h(tree->left);

	if (tree->right)
		right_height = 1 + tree_size_h(tree->right);

	return (left_height + right_height);
}

/**
 * _preorder - loops through a binary tree by pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: The last node in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - Gets the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *right_heap, *node;

	if (!root || !*root)
		return (0);
	right_heap = *root;
	value = right_heap->n;
	if (!right_heap->left && !right_heap->right)
	{
		*root = NULL;
		free(right_heap);
		return (value);
	}

	_preorder(right_heap, &node, tree_height(right_heap));

	right_heap->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(right_heap);
	*root = right_heap;
	return (value);
}
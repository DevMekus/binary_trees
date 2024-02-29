#include "binary_trees.h"

/**
 * heap_insert - Put a value in Max Binary Heap
 * @root: Double pointer to the root node
 * @value: the value to store in the node
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *newNode, *flp;
	int size, leaf, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (level = 0, sub = 1; leaf >= sub; sub *= 2, level++)
		leaf -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaf & bit ? tree->right : tree->left;

	newNode = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = newNode) : (tree->left = newNode);

	flp = newNode;
	for (; flp->parent && (flp->n > flp->parent->n); flp = flp->parent)
	{
		temp = flp->n;
		flp->n = flp->parent->n;
		flp->parent->n = temp;
		newNode = newNode->parent;
	}

	return (newNode);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

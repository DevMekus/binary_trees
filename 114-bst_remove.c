#include "binary_trees.h"

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);

/**
 * inorder_successor - Returns the minimum value
 * @root: pointer to the root node
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node
 * @node: A pointer to the node to delete
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parentNode = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parentNode != NULL && parentNode->left == node)
			parentNode->left = node->right;
		else if (parentNode != NULL)
			parentNode->right = node->right;
		if (node->right != NULL)
			node->right->parent = parentNode;
		free(node);
		return (parentNode == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parentNode != NULL && parentNode->left == node)
			parentNode->left = node->left;
		else if (parentNode != NULL)
			parentNode->right = node->left;
		if (node->left != NULL)
			node->left->parent = parentNode;
		free(node);
		return (parentNode == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree.
 * @root: Pointer to the root node
 * @node: Pointer to the current node
 * @value: The value to remove from the BST.
 *
 * Return: Pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: Pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

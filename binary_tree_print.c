#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Saves recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left_side, right_side, isleft, i;

	if (!tree)
		return (0);
	isleft = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left_side = print_t(tree->left, offset, depth + 1, s);
	right_side = print_t(tree->right, offset + left_side + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left_side + i] = b[i];
	if (depth && isleft)
	{
		for (i = 0; i < width + right_side; i++)
			s[depth - 1][offset + left_side + width / 2 + i] = '-';
		s[depth - 1][offset + left_side + width / 2] = '.';
	}
	else if (depth && !isleft)
	{
		for (i = 0; i < left_side + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left_side + width / 2] = '.';
	}
	return (left_side + width + right_side);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	left_height = tree->left ? 1 + _height(tree->left) : 0;
	right_height = tree->right ? 1 + _height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t treeHeight, index, j;

	if (!tree)
		return;
	treeHeight = _height(tree);
	s = malloc(sizeof(*s) * (treeHeight + 1));
	if (!s)
		return;
	for (index = 0; index < treeHeight + 1; index++)
	{
		s[index] = malloc(sizeof(**s) * 255);
		if (!s[index])
			return;
		memset(s[index], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (index = 0; index < treeHeight + 1; index++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[index][j] != ' ')
				break;
			s[index][j] = '\0';
		}
		printf("%s\n", s[index]);
		free(s[index]);
	}
	free(s);
}

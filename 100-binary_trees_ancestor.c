#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL,
 * 		else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *mother, *pops;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mother = first->parent, pops = second->parent;
	if (first == pops || !mother || (!mother->parent && pops))
		return (binary_trees_ancestor(first, pops));
	else if (mother == second || !pops || (!pops->parent && mother))
		return (binary_trees_ancestor(mother, second));
	return (binary_trees_ancestor(mother, pops));
}

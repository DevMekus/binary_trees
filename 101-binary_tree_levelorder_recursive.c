#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 * @tree: Pointer to the root node.
 * @func: Pointer to a function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *treeChildren = NULL;

	func(tree->n);
	treeChildren = get_children(treeChildren, tree);
	levels_rec(treeChildren, func);

	free_list(treeChildren);
}

/**
 * levels_rec - Calls func on all nodes at each level.
 * @head: Pointer to head
 * @func: Pointer to a function.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - appends children of parent to linked list.
 * @head: Pointer to head of linked list
 * @parent: Pointer to node
 * Return: Pointer to head
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a newNode node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, Else
 * 	NULL on failure
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *newNode = NULL, *lastNode = NULL;

	newNode = malloc(sizeof(*newNode));
	if (newNode)
	{
		newNode->node = btnode;
		newNode->next = NULL;
		if (!head)
			head = newNode;
		else
		{
			lastNode = head;
			while (lastNode->next)
				lastNode = lastNode->next;
			lastNode->next = newNode;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */
void free_list(ll *head)
{
	ll *pointer = NULL;

	while (head)
	{
		pointer = head->next;
		free(head);
		head = pointer;
	}
}

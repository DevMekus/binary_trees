#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
			   levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node
 *
 * Return: On an error, NULL.
 *         Else, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *newNode;

	newNode = malloc(sizeof(levelorder_queue_t));
	if (newNode == NULL)
		return (NULL);

	newNode->node = node;
	newNode->next = NULL;

	return (newNode);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: On malloc failure, exits with 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
			   levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *newNode;

	func(node->n);
	if (node->left != NULL)
	{
		newNode = create_node(node->left);
		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
	if (node->right != NULL)
	{
		newNode = create_node(node->right);
		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 * @tree: A pointer to the root node
 * @func: A pointer to a function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *headNode, *tailNode;

	if (tree == NULL || func == NULL)
		return;

	headNode = tailNode = create_node((binary_tree_t *)tree);
	if (headNode == NULL)
		return;

	while (headNode != NULL)
	{
		pint_push(headNode->node, headNode, &tailNode, func);
		pop(&headNode);
	}
}

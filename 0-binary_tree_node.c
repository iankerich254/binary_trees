#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node_ker;

	new_node_ker = malloc(sizeof(binary_tree_t));
	if (new_node_ker == NULL)
		return (NULL);

	new_node_ker->n = value;
	new_node_ker->parent = parent;
	new_node_ker->left = NULL;
	new_node_ker->right = NULL;

	return (new_node_ker);
}

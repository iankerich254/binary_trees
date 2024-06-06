#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node_ker;

	if (parent == NULL)
		return (NULL);

	new_node_ker = binary_tree_node(parent, value);
	if (new_node_ker == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node_ker->right = parent->right;
		parent->right->parent = new_node_ker;
	}
	parent->right = new_node_ker;

	return (new_node_ker);
}

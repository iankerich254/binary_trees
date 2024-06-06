#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node_ker;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);

		if (value < current->n)
		{
			if (!current->left)
			{
				new_node_ker = binary_tree_node(current, value);
				current->left = new_node_ker;
				return (new_node_ker);
			}
			current = current->left;
		}
		else
		{
			if (!current->right)
			{
				new_node_ker = binary_tree_node(current, value);
				current->right = new_node_ker;
				return (new_node_ker);
			}
			current = current->right;
		}
	}

	return (NULL);
}

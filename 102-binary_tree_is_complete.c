#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	binary_tree_t **queue;
	size_t front = 0, back = 0;
	int found_empty = 0;

	queue = malloc(1024 * sizeof(*queue));
	if (!queue)
		return (0);

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		const binary_tree_t *node = queue[front++];

		if (!node)
		{
			found_empty = 1;
		}
		else
		{
			if (found_empty)
			{
				free(queue);
				return (0);
			}
			queue[back++] = node->left;
			queue[back++] = node->right;
		}
	}

	free(queue);
	return (1);
}

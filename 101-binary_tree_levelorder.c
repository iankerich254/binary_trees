#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through binary tree via level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue;
	size_t front = 0, back = 0;

	queue = malloc(1024 * sizeof(*queue));
	if (!queue)
		return;

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		const binary_tree_t *node = queue[front++];
		func(node->n);
		if (node->left)
			queue[back++] = node->left;
		if (node->right)
			queue[back++] = node->right;
	}

	free(queue);
}

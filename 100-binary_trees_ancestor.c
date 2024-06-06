#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;

	if (!first || !second)
		return (NULL);

	while (node1)
	{
		node2 = second;
		while (node2)
		{
			if (node1 == node2)
				return ((binary_tree_t *)node1);
			node2 = node2->parent;
		}
		node1 = node1->parent;
	}

	return (NULL);
}

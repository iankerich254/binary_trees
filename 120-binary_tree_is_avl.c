#include "binary_trees.h"

/**
 * max - returns the maximum of two integers.
 * @a: first integer.
 * @b: second integer.
 *
 * Return: maximum of a and b.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_avl_helper - helper function to check if a binary tree is valid AVL tree.
 * @tree: pointer to the root node of the tree.
 * @min: minimum value allowed.
 * @max: maximum value allowed.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
			is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

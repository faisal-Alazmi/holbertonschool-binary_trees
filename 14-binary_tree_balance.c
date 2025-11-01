#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree
 *                        (used for balance factor calculation)
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height_b(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height_b(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor (left height - right height), or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = (int)binary_tree_height_b(tree->left);
	if (tree->right)
		right_height = (int)binary_tree_height_b(tree->right);

	return (left_height - right_height);
}

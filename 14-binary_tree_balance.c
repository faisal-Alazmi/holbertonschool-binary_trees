#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree for balance factor
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height_b(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height_b(tree->right);

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = (int)binary_tree_height_b(tree->left);
	if (tree->right)
		right_height = (int)binary_tree_height_b(tree->right);

	return (left_height - right_height);
}

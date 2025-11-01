#include "binary_trees.h"

/**
 * height - Helper function to measure height
 * @tree: Pointer to the root node
 *
 * Return: Height
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + height(tree->left) : 0;
	right_h = tree->right ? 1 + height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)height(tree->left) - (int)height(tree->right));
}

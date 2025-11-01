#include "binary_trees.h"

/**
 * binary_tree_height_p - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height, 0 if tree is NULL
 */
size_t binary_tree_height_p(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height_p(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height_p(tree->right);

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_size_p - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size, 0 if tree is NULL
 */
size_t binary_tree_size_p(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size_p(tree->left) +
		binary_tree_size_p(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes, expected_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height_p(tree);
	nodes = binary_tree_size_p(tree);
	expected_nodes = (1 << (height + 1)) - 1;

	return (nodes == expected_nodes);
}

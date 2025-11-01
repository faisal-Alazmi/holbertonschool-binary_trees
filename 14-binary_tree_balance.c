#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left = 0, right = 0;

    if (!tree)
        return 0;

    if (tree->left)
        left = (int)binary_tree_height(tree->left);
    if (tree->right)
        right = (int)binary_tree_height(tree->right);

    return (left - right);
}

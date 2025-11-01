#include "binary_trees.h"

/**
 * binary_tree_height - measures the height in edges of a binary tree
 * @tree: pointer to the root node
 * Return: height (number of edges), 0 if leaf, -1 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left = 0, right = 0;

    if (tree == NULL)
        return (-1);  /* empty tree has height -1 */

    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);

    return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - measures the balance factor
 * @tree: pointer to the root node
 * Return: balance factor (left height - right height)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return ((int)binary_tree_height(tree->left) -
            (int)binary_tree_height(tree->right));
}

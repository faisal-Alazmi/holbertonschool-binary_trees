#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - Measures the height of a binary tree in edges
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree (number of edges), 0 if tree is NULL or leaf
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left = 0, right = 0;

    if (tree == NULL)
        return (0);

    if (tree->left)
        left = 1 + binary_tree_height(tree->left);
    if (tree->right)
        right = 1 + binary_tree_height(tree->right);

    return (left > right ? left : right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor (left subtree height - right subtree height)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return ((int)binary_tree_height(tree->left) -
            (int)binary_tree_height(tree->right));
}

/* Optional main for testing */
#ifdef MAIN
int main(void)
{
    binary_tree_t *root, *node_50, *node_40, *node_60;
    int balance;

    /* Manually create the tree for testing */
    root = binary_tree_node(NULL, 98);
    node_50 = binary_tree_node(root, 50);
    node_40 = binary_tree_node(node_50, 40);
    node_60 = binary_tree_node(root, 60);

    root->left = node_50;
    root->right = node_60;
    node_50->left = node_40;

    balance = binary_tree_balance(root);
    printf("Balance factor for tree with root node (%d): %+d\n",
           root->n, balance);

    /* Optional: print the tree visually */
    binary_tree_print(root);

    /* Free memory if needed */
    _binary_tree_delete(root);

    return (0);
}
#endif

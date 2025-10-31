#include "binary_trees.h"

/**
 * print_t - recursive helper to print a binary tree
 * @tree: pointer to the node to print
 * @offset: horizontal offset
 * @depth: current depth
 * @s: buffer (20 lines x 255 chars)
 */
static void print_t(const binary_tree_t *tree, int offset, int depth, char s[20][255])
{
    char b[6];
    int width, i;

    width = 5;
    if (tree == NULL)
        return;

    sprintf(b, "(%03d)", tree->n);

    for (i = 0; i < width && b[i]; i++)
        s[depth * 2][offset - width / 2 + i] = b[i];

    print_t(tree->left, offset - width, depth + 1, s);
    print_t(tree->right, offset + width, depth + 1, s);
}

/**
 * binary_tree_print - prints a binary tree
 * @tree: pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char s[20][255];
    int i, j;

    if (tree == NULL)
        return;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 255; j++)
            s[i][j] = ' ';
    }

    print_t(tree, 127, 0, s);

    for (i = 0; i < 20; i++)
    {
        s[i][254] = '\0';
        printf("%s\n", s[i]);
    }
}

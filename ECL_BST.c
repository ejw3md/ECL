#include <stdlib.h>
#include <stdio.h>

#include "ECL_BST.h"

static BSTNode * createBSTNode(int val)
{
    BSTNode * new = malloc(sizeof(BSTNode));
    new->left = NULL;
    new->right = NULL;
    new->val = val;
    return new;
}

static BSTNode * BSTinsert(BSTNode * tree, int val)
{
    if(tree==NULL)
    {
        return createBSTNode(val);
    }
    if(val < tree->val)
    {
        tree->left = BSTinsert(tree->left, val);
    }
    else
    {
        tree->right = BSTinsert(tree->right, val);
    }
    return tree;
}

static int BSTNodeSearch(BSTNode * tree, int val)
{
    if(tree == NULL)
        return 0;
    if(tree->val == val)
        return 1;
    if(val < tree->val)
        return BSTNodeSearch(tree->left, val);
    else
        return BSTNodeSearch(tree->right, val);
}

static void BSTNodeWalk(BSTNode * tree)
{
    if(tree != NULL)
    {
        BSTNodeWalk(tree->left);
        printf("%d ", tree->val);
        BSTNodeWalk(tree->right);
    }
}

BST * initBST()
{
    BST * tree = malloc(sizeof(tree));
    tree->contents = NULL;
    return tree;
}

void BSTPush(BST * tree, int val)
{
        tree->contents = BSTinsert(tree->contents, val);
}

int BSTSearch(BST* tree, int val)
{
    return BSTNodeSearch(tree->contents, val);
}

void BSTWalk(BST * tree)
{
    BSTNodeWalk(tree->contents);
    printf("\n");
}

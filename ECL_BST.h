typedef struct bstNode
{
    int val;
    struct bstNode * left;
    struct bstNode * right;
} BSTNode;

typedef struct bst
{
    BSTNode * contents;
} BST;

BST * initBST();
void BSTPush(BST * tree, int val);
int BSTSearch(BST * tree, int val);
void freeBST(BST * tree);
int queueEmpty(BST * tree);
void BSTWalk(BST * tree);

/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is stack
 * simply use push, pop
 * but befor using, please init a base, or it will has error
 * 
 * change the struct to:
typedef struct treeData
{
    unsigned int integer;
}binaryTreeData;
 * and run the test code
*/

#include <stdio.h>
#include "binaryTree.h"

int main()
{
    binaryTreeData rootData = {.integer = 0};
    binaryTree *root = initTreeNode(rootData);

    binaryTree *c1 = initTreeNode(rootData);
    c1->data.integer = 1;

    binaryTree *c2 = initTreeNode(rootData);
    c2->data.integer = 2;

    binaryTree *c3 = initTreeNode(rootData);
    c3->data.integer = 3;

    connectLeft(root, c1);
    connectRight(root, c2);
    connectRight(c1, c3);

    if(findNodeWithDfs(root, c1->data))
    {
        printf("Success at findNodeWithDfs\n");
    }
    if(treenodeDataEqual(root->data, root->data))
    {
        printf("Success at treenodeDataEqual\n");
    }

    toTreeRoot(c1);
    if(c1 == root)
    {
        printf("Success at toTreeRoot\n");
    }
    printf("get the height of this tree: %d\n", getHeight(root));

    printTree(root,1);

    freeSubtree(root);
    printf("free this tree\n");
    printf("reach here means the functions work correctly\n");
    return 0;
}
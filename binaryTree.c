/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is a double linked tree. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTree.h"

int treeerr(int);

binaryTree* initTreeNode(binaryTreeData data)
{
    binaryTree* newNode = malloc(sizeof(binaryTree));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    int i;
    for(i=0;i<MAXCROSS;i++)
    {
        newNode->cross[i] = NULL;
        newNode->unchoose[i] = NULL;
    }
    return newNode;
}

binaryTree* toTreeRoot(binaryTree* node)
{
    binaryTree* pointer = node;
    while(pointer->parent != NULL)
    {
        pointer = pointer->parent;
    }
    return pointer;
}

int findNodeWithDfs(binaryTree* root, binaryTreeData data)
{
    if(treenodeDataEqual(root->data, data))
    {
        return 1;
    }
    else if(root->leftChild == NULL && root->rightChild == NULL)
    {
        return 0;
    }
    else
    {
        binaryTree* nextLevel;
        if(root->leftChild != NULL)
        {
            nextLevel = root->leftChild;
            int left = findNodeWithDfs(nextLevel, data);
            if(left)
            {
                root = nextLevel;
                return left;
            }
        }
        if(root->rightChild != NULL)
        {
            nextLevel = root->rightChild;
            int right = findNodeWithDfs(nextLevel, data);
            if(right)
            {
                root = nextLevel;
                return right;
            }
        }
        return 0;
    }
}

int treenodeDataEqual(binaryTreeData a, binaryTreeData b)
{
    binaryTreeData* pointerA = &a;
    binaryTreeData* pointerB = &b;
    if(!memcmp(pointerA,pointerB,sizeof(binaryTreeData)))
        return 1;
    return 0;
}

void freeSubtree(binaryTree* root)
{
    if(root->leftChild != NULL)
        freeSubtree(root->leftChild);
    if(root->rightChild != NULL)
        freeSubtree(root->rightChild);
    free(root);
}

int connectLeft(binaryTree* parent, binaryTree* child)
{
    if(parent->leftChild != NULL)
    {
        return treeerr(TREEASSIGNERR);
    }
    else
    {
        parent->leftChild = child;
        if(child->parent != NULL)
        {
            return treeerr(TREEASSIGNERR);
        }
        else
        {
            child->parent = parent;
        }
    }
    return 0;
}

int connectRight(binaryTree* parent, binaryTree* child)
{
    if(parent->rightChild != NULL)
    {
        return treeerr(TREEASSIGNERR);
    }
    else
    {
        parent->rightChild = child;
        if(child->parent != NULL)
        {
            return treeerr(TREEASSIGNERR);
        }
        else
        {
            child->parent = parent;
        }
    }
    return 0;
}

int getHeight(binaryTree* root)
{
    if(root->rightChild == NULL && root->leftChild == NULL)
        return 1;
    int leftHeight = 0, rightHeight = 0;
    if(root->leftChild != NULL)
        leftHeight = 1 + getHeight(root->leftChild);
    if(root->rightChild != NULL)
        rightHeight = 1 + getHeight(root->rightChild);
    return (rightHeight>leftHeight)? rightHeight:leftHeight;
}

/**                       +----------------------+----------------------+
 *                        @
 *            +-----------+-----------+
 *            1                       a
 *      +-----+-----+           +-----+-----+
 *      2           3           b           c
 *   +--+--+     +--+--+     +--+--+     +--+--+
 *   4     5     6     7     d     e     f     g
 * +-+-+ +-+-+ +-+-+ +-+-+ +-+-+ +-+-+ +-+-+ +-+-+
 *           8 9   a
 * 
 * 1---2---4
 * |   |
 * |   +---5
 * |
 * +---3
 * This is not finished function!!!
*/
int printTree(binaryTree* root, int offset)
{
    //print offset space
    int i;
    for(i = 0; i > offset; i++)
    {
        printf(" ");
    }
    //print node
    printf("@");
    if(root->leftChild != NULL)
    {
        printf("-+-");
        printTree(root->leftChild,0);
    }
    printf("\n");
    if(root->rightChild != NULL)
    {
        for(i = 0; i > offset; i++)
        {
            printf(" ");
        }
        printf(" |\n");
        for(i = 0; i > offset; i++)
        {
            printf(" ");
        }
        printf(" +-");
        printTree(root->rightChild,1);
    }
    return 0;
}

int treeerr(int code)
{
    if(code == 0)
    {
        return 0;
    }
    printf("Error here.\nerr code: ");
    switch (code)
    {
    case TREEASSIGNERR:
        printf("%d TREE ASSIGNERR!\n",code);
        break;
    default:
        break;
    }
    exit(1);
}
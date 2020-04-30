/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is a double linked list. 
 */

/**
 * can change it if needed
 */
#define MAXCROSS 10
typedef struct treeData
{
    int CostFromStartPoint;
    char parentX;
    char parentY;
    char parentDir;
    char leftChildX;
    char leftChildY;
    char leftChildDir;
    char rightChildX;
    char rightChildY;
    char rightChildDir;

    char crossX[MAXCROSS], crossY[MAXCROSS], crossDir[MAXCROSS];
    char location[2];

    //for dijkstra
    char unchooseX[MAXCROSS],unchooseY[MAXCROSS], unchooseDir[MAXCROSS];
}binaryTreeData;

typedef struct tree
{
    struct tree *parent;
    struct treeData data;
    struct tree *leftChild;
    struct tree *rightChild;

    struct tree *cross[MAXCROSS];
    //for dijkstra
    struct tree *unchoose[MAXCROSS];
}binaryTree;


/**
 * descreption: init a tree node
 * input: the data of this node
 * output: a node contains data and Null links
 */
binaryTree* initTreeNode(binaryTreeData);

/**
 * descreption: go to the head of this tree
 * input: the tree need to be run
 * output: the root node of this list
 */
binaryTree* toTreeRoot(binaryTree*);

/**
 * descreption: using bfs to search is the node in this subtree
 * input: the subtree root need to be run, data of this node
 * output:  1 found
 *          0 not found
 * the node will be moved to the leaf node or the found node
 */
int findNodeWithDfs(binaryTree*, binaryTreeData);

/**
 * descreption: check two data is the same or not
 * input: two data
 * output: 1 equal / 0 not the same
 */
int treenodeDataEqual(binaryTreeData, binaryTreeData);

/**
 * descreption: free the tree
 * input: two data
 * output: 
 */
void freeSubtree(binaryTree*);

/**
 * descreption: connect left child
 * input: two nodes(parent, child)
 * output: 
 */
int connectLeft(binaryTree*, binaryTree*);

/**
 * descreption: connect right child
 * input: two nodes(parent, child)
 * output: 
 */
int connectRight(binaryTree*, binaryTree*);

/**
 * descreption: get the height of this subtree
 * input: root
 * output: the len of this tree
 */
int getHeight(binaryTree*);

/**
 * descreption: print this subtree
 * input: root, the level of this node(original is 1)
 * output: not def now
 */
int printTree(binaryTree*, int);

/**
 * descreption: error code
 */
#define TREEASSIGNERR 0x1
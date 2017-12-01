#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTree {
    int value;
    struct BTree *left, *right;
} BTree;

BTree *insert(BTree *root, int value);
BTree * searchValue(BTree * r, int n);
bool isAList(BTree * r);
bool twoOrZeroChildren(BTree * r);

int main()
{
    int sample[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BTree *root = NULL;
    int i;

    int ct, sum, sumST;
    BTree * nodeSearchedValue;
    bool list, children;

    for (i = 0; sample[i] > 0; i++)
        root = insert(root, sample[i]);

    printTree(root);

    ct = numberOfNodes(root);
    printf("number of nodes : %d \n", ct);

    sum = sumOfNodes(root);
    printf("sum of nodes : %d \n", sum);

    nodeSearchedValue = searchValue(root, 789);
    if(nodeSearchedValue) printf("value of the node : %d \n", nodeSearchedValue->value);
    else printf("Value not found in any nodes \n");

    negateTree(root);
    printTree(root);
    nodeSearchedValue = searchValue(root, -10);
    if(nodeSearchedValue) printf("value of the node : %d \n", nodeSearchedValue->value);
    else printf("Value not found in any nodes \n");
    negateTree(root);

    sumST = santaClauss(root);
    printf("number of presents : %d \n", sumST);
    printTree(root);

    list = isAList(root);
    if(list) printf("This tree is a list \n");
    else printf("This tree is not a list \n");

    children = twoOrZeroChildren(root);
    if(children) printf("each node of the tree has two or zero children \n");
    else printf("one of the node of the tree has just one child \n");

    deleteTree(root);

    return 0;
}

BTree *insert(BTree *root, int value)
{
    if (root == NULL) {
        BTree *new_node = (BTree*) malloc(sizeof(BTree));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (value < root->value) {        /* insert left */
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {   /* insert right */
        root->right = insert(root->right, value);
    }
    else {
        /* already in the tree */
    }
    return root;
}

void printTree(BTree * r)
{
    if(r == NULL) return;
    printTree(r->left);
    printf("%d \n", r->value);
    printTree(r->right);
}

void deleteTree(BTree * r)
{
    if(r == NULL) return;
    deleteTree(r->left);
    deleteTree(r->right);
    free(r);
}

int numberOfNodes(BTree * r)
{
    if(r == NULL) return 0;
    return numberOfNodes(r->left) + numberOfNodes(r->right) + 1;
}

int sumOfNodes(BTree * r)
{
    if(r == NULL) return 0;
    return sumOfNodes(r->left) + sumOfNodes(r->right) + r->value;
}

BTree * searchValue(BTree * r, int n)
{
    if(r == NULL) return r;
    if(r->value == n) return r;
    if (n < r->value) return searchValue(r->left, n);
    else return searchValue(r->right, n);
}

void negateTree(BTree * r)
{
    if(r ==NULL) return;

    BTree * temp = NULL;

    r->value = -r->value;
    negateTree(r->left);
    negateTree(r->right);

    temp = r->left;
    r->left = r->right;
    r->right = temp;
}

int santaClauss(BTree * r)
{
    if(r == NULL) return 0;
    r->value = santaClauss(r->left) + santaClauss(r->right) + r->value;

    if(r->left != NULL) r->left->value = 0;
    if(r->right != NULL) r->right->value = 0;

    return r->value;
}

bool isAList(BTree * r)
{
    if(r == NULL) return true; //test for the root of the tree
    if(!r->left && !r->right) return true; //if the two sides of the node are NULL, return true
    if(r->left && !(r->right)) return isAList(r->left);
    if (!(r->left) && r->right) return isAList(r->right);
    return false; //if the two sides of the node are not NULL, return false
}

bool twoOrZeroChildren(BTree * r)
{
    if(r == NULL) return true; //test for the root of the tree
    if(!r->left && !r->right) return true;
    if(r->left && r->right) return (twoOrZeroChildren(r->left) && twoOrZeroChildren(r->right));
    return false;
}

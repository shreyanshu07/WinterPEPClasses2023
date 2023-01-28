/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namspace std;

/******************* TREES ***************************/

/*Hierchial Data Structure => Real life implementation of the tree is the folder system in the file explorer. Every file is stored under a folder which is the parent node of sub-folder.

Tree contains N nodes and N-1 nodes and this fact implies that there are only one path from one node to other node.

It is also referred as Acyclic connected Graph

Binary Tree => A node which has atmost 2 children.
Height of tree => How many levels are there of tree => Maximum possible height is O(n) and minimum possible height is O(log n)

Recursion is super useful in case of trees and it helps to solve a bigger problem in much simpler way.
Most important node is the rootNode as head of the whole tree. Tree edges are directed and unidirectional.*/

struct Node{
    int val;
    Node* left;
    Node* right;
}

//Ques: Count the number of nodes in a tree 
int count(Node* root){
    if(root==NULL) return 0;
    return count(root->left)+count(root->right)+1;
}

//Ques: Count the number of leaves in tree 
int countLeaves(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 1;
    return countLeaves(root->left)+countLeaves(root->right);
}

//Ques: Mirror Image of a Tree 
void mirrorImage(Node* root){
    if(root==NULL){
        return;
    }
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
}

//Ques: Symmetric Tree || Check if the tree is a symmetric tree 
//Sol : BruteForce => Create a new tree which is mirrorImage of the given tree and then compare both the trees.
// Optimal Approach (Without creating a new tree)

bool checkMI(Node* root1,Node* root2){
    if(!root1 and !root2){
        return true;
    }
    if(!root1 or !root2){
        return false;
    }
    return (root1->data==root2->data) and checkMI(root1->left,root2->left) and checkMI(root1->right,root2->right);
}
bool checkSymmetric(Node* root){
    if(!root) return true;
    return checkMI(root->left,root->right);
    
}

//Ques: Find the height of the tree (longest path from root to leaf)

int height(Node* root){
    if(!root) return 0;
    return max(height(root->left)+height(root->right))+1;
}

//Ques: Minimum Depth of Binary tree 

int minHeight(Node* root){
    if(root==NULL) return INT_MAX;
    if(root->right==NULL and root->left==NULL) return 1;
    return 1+min(minHeight(root->left),minHeight(root->right));
}

//Ques : Print all root to leaf Paths

void print(Node* root,int temp[],int size){
    if(root->left==NULL and root->right==NULL){
        print(temp);
        return ;
    }
    temp[size]=root->data;
    print(root->left,size+1);
    print(root->right,size+1);
}

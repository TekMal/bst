#ifndef __TREE_HPP_
#define __TREE_HPP_

#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
  node * parent, * left, * right;
  int key;

};

//x=='node'

class BST
{ 
private:
	node * maxNode(node * x);
    node * minNode(node * x);
    void Insert_node(int key, node * x);
    void Del_node(node * x);
    
public:
    node * root;  
    int Lnode;       
    BST();
    ~BST();
   
    node * Search(int key);
    node * Successor(node * x);
    node * Predecessor(node * x);
    node * Remove_node(node * x);
    int       MaxKey(node * x);
    int       MinKey(node * x);
    void      Preorder(node * x);
    void      Inorder(node * x);
    void Insert_node(int key);

};

void Test_Insert(BST * T);
void Test_Remove_node(BST * T);
void Test_MinMax(BST * T);
void Test_Suc_Predecessor(BST * T);
void Test_Search(BST * T);
void Test_Preorder(BST * T);
void Test_Inorder(BST * T);
void Number_of_nodes(BST * T);
void Menu(BST * T);


#endif

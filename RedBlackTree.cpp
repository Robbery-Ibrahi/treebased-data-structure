#include "RedBlackTree.h"

RedBlackTree::~RedBlackTree()
{

}

void RedBlackTree::insert(int newdata)
{
	size++;
	Node_of_RedBlackTree* node = root;
	while (node->data)
	{
		if (newdata <= node->data)
			node = node->leftchild;
		node = node->rightchild;
	}
	node->data = newdata;
	Node_of_RedBlackTree* leftleaf = new Node_of_RedBlackTree(0, black, node, nullptr, nullptr);
	Node_of_RedBlackTree* righttleaf = new Node_of_RedBlackTree(0, black, node, nullptr, nullptr);
	node->leftchild = leftleaf;
	node->rightchild = righttleaf;
	while (node != root && node->colour == red)
	{
		if (node->parent == node->parent->parent->leftchild)
		{
			Node_of_RedBlackTree* right = node->parent->parent->rightchild;
			if (right->colour == red)
			{
				//case 1
				node->parent->parent->colour = red;
				right->colour = black;

				Node_of_RedBlackTree* temp = right;
				node->parent->parent->rightchild = node;
				node->parent = node->parent->parent;

				node->parent->leftchild->rightchild = temp;
				temp->parent = node->parent->leftchild;
			}
			else if (node == node->parent->rightchild)
			{
				//case 2
				Node_of_RedBlackTree* y = node->parent;
				node->parent = y->parent;
				y->leftchild = node;
				y->rightchild = node->leftchild;
				node->leftchild->parent = y;
				y->parent = node;
				node->leftchild = y;

				//Case 3
				node->colour = black;
				node->parent->colour = red;

				Node_of_RedBlackTree* x = node->rightchild;
				x->parent = node->parent;
				x->parent->leftchild = x;

				node->rightchild = x->parent;
				x->parent->parent = node;

			}
		}
	}
	
}

bool RedBlackTree::remove(int existdata)
{
	size--;
	Node_of_RedBlackTree* node = root;
	while (node->data)
	{
		if (existdata == node->data)
		{
			
			return true;
		}
		else if (existdata < node->data)
			node = node->leftchild;
		else
			node = node->rightchild;
	}
	return false;
}
#include "Treap.h"

void Treap::insert(int data)
{
	TreatNode* node = root;
	while (node)
	{
		if (data < node->key)
			node = node->leftchild;
		else
			node = node->rightchild;
	}	
	TreatNode* newNode = new TreatNode(data, node->parent);
	delete node;
	newNode->priority = rand();
	while (newNode != root && newNode->priority < newNode->parent->priority)
	{
		if (newNode == newNode->parent->leftchild)
		{
			//RIGHT-ROTATE (T, p[x])
			TreatNode* change = newNode->parent;
			change->parent = newNode;
			change->leftchild = newNode->rightchild;
			newNode->rightchild = change;
			newNode->rightchild->parent = change;
			if (change == change->parent->leftchild)
				newNode->parent = change->leftchild;
			else
				newNode->parent = change->rightchild;
		}
		else
		{
			//LEFT-ROTATE (T, p[x])
			TreatNode* change = newNode->parent;
			change->parent = newNode;
			change->rightchild = newNode->leftchild;
			newNode->leftchild = change;
			newNode->leftchild->parent = change;
			if (change == change->parent->leftchild)
				newNode->parent = change->leftchild;
			else
				newNode->parent = change->rightchild;
		}
	}
}
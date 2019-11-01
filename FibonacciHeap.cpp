#include "FibonacciHeap.h"

FibonacciHeap::~FibonacciHeap()
{

}

void FibonacciHeap::insert(int newdata)
{
	Node_of_FibonacciHeap* rootnode = min;
	while (rootnode->rightbrother)
	{
		rootnode = rootnode->rightbrother;
	}
	Node_of_FibonacciHeap* addednode = new Node_of_FibonacciHeap(newdata, nullptr, rootnode, nullptr);
	rootnode->rightbrother = addednode;
	degree++;
}

FibonacciHeap FibonacciHeap::merge(FibonacciHeap& h1, FibonacciHeap& h2)
{
	FibonacciHeap x = h1;
	Node_of_FibonacciHeap* h1_rootnode = h1.min;
	while (h1_rootnode->rightbrother)
	{
		h1_rootnode = h1_rootnode->rightbrother;
	}
	Node_of_FibonacciHeap* h2_rootnode = h2.min;
	while (h2_rootnode->leftbrother)
	{
		h2_rootnode = h2_rootnode->leftbrother;
	}
	h1_rootnode->rightbrother = h2_rootnode;
	h2_rootnode->leftbrother = h1_rootnode;
	return x;
}


int FibonacciHeap::findmin()
{
	return min->key;
}

void FibonacciHeap::extractMin()
{
	degree = degree - 1 + min->degree;
	Node_of_FibonacciHeap* newroot = min->firstchild;
	Node_of_FibonacciHeap* oldleft = min->leftbrother;
	Node_of_FibonacciHeap* oldright = min->rightbrother;
	delete min;
	oldleft->rightbrother = newroot;
	newroot->leftbrother = oldleft;
	Node_of_FibonacciHeap* topnode = newroot;
	while (topnode->rightbrother)
	{
		topnode = topnode->rightbrother;
	}
	topnode->rightbrother = oldright;
	oldright->leftbrother = topnode;
	while (oldleft->leftbrother)
	{
		oldleft = oldleft->leftbrother;
	}
	bool change = true;
	while (change)
	{
		change = false;
		Node_of_FibonacciHeap** root = new Node_of_FibonacciHeap * [degree];
		int i = 0;
		while (oldleft->rightbrother)
		{
			root[i] = oldleft;
			oldleft = oldleft->rightbrother;
		}
		for (int i = 0; i < degree; i++)
		{
			for (int j = i + 1; j < degree; j++)
			{
				if (root[i]->degree == root[j]->degree)
				{
					change = true;
					if (root[i]->key <= root[j]->key)
					{
						root[i]->degree++;
						root[j]->rightbrother->leftbrother = root[j]->leftbrother;
						root[j]->leftbrother->rightbrother = root[j]->rightbrother;
						Node_of_FibonacciHeap* x = root[i]->firstchild;
						while (x->rightbrother)
						{
							x = x->rightbrother;
						}
						x->rightbrother = root[j];
						root[j]->leftbrother = x;
					}
					else
					{
						root[j]->degree++;
						root[i]->rightbrother->leftbrother = root[i]->leftbrother;
						root[i]->leftbrother->rightbrother = root[i]->rightbrother;
						Node_of_FibonacciHeap* x = root[j]->firstchild;
						while (x->rightbrother)
						{
							x = x->rightbrother;
						}
						x->rightbrother = root[i];
						root[i]->leftbrother = x;
					}
				}

			}
		}
		delete root;
	}


}
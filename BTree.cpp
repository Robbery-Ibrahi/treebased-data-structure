#include "BTree.h"

void BTree::insert(int data)
{
	BTreeNode* insert = root;
	while (insert)
	{
		int i = 0;
		for (; i < insert->size; i++)
		{
			if (data < insert->key[i])
			{
				insert = insert->children[i];
				break;
			}
		}
		if (i == insert->size)
			insert = insert->children[i];
	}
	insert = insert->parent;
	if (insert->size < insert->order)
	{
		for (int i = 0; i < insert->size; i++)
		{
			if (data < insert->key[i])
			{
				for (int j = insert->size; j > i; j--)
				{
					insert->key[j] = insert->key[j - 1];
					insert->size++;
				}
				insert->key[i] = data;
				return;
			}
		}
		insert->key[insert->size] = data;
		insert->size++;
		return;
	}
	else
	{
		insertto(data, insert);
	}
}

void BTree::insertto(int data, BTreeNode* up)
{
	//up is full, so slit it
	int* temp = new int[order];
	for (int i = 0; i < order - 1; i++)
	{
		temp[i] = up->key[i] > data ? data : up->key[i];
	}
	int* t1 = new int[order / 2];
	int* t2 = new int[order / 2];
	for (int i = 0; i < order / 2; i++)
	{
		t1[i] = temp[i];
	}
	for (int i = order / 2 + 1; i < order; i++)
	{
		t2[i] = temp[i];
	}
	BTreeNode* slipA = new BTreeNode(0, order / 2, up);
	BTreeNode* slipB = new BTreeNode(order / 2 + 1, order, up);
	int xx = up->key[order / 2];
	delete up, temp;
	while (slipA != root)
	{
		insertto(xx, slipA->parent);
	}
	
}

void BTree::remove(int data)
{

}
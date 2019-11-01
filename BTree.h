#pragma once

class BTree;

class BTreeNode
{
public:
	int order;// Order > 1
	int size;
	int* key;
	BTreeNode** children;
	BTreeNode* parent;
	BTreeNode(int newOrder): order(newOrder), key(new int[order - 1]), children(new BTreeNode*[order]), size(0)
	{}
	BTreeNode(int start, int end, BTreeNode* up):parent(up->parent), key(new int[end - start]), size(up->size / 2), order(up->order)
	{
		int i = start, j = 0;
		for (; i < end; i++, j++)
		{
			key[j] = up->key[i];
			children[j] = up->children[i];
		}
		children[j] = up->children[i];
	}
	BTreeNode();
	~BTreeNode()
	{
		delete key;
		delete children;
	}
};

class BTree
{
private:
	BTreeNode* root;
	int order;
public://order > 1
	BTree(int newOrder):root(new BTreeNode(newOrder))
	{}
	~BTree();
	void insert(int data);
	void insertto(int data, BTreeNode* up);
	void remove(int data);
};


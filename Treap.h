#pragma once
#include <cstdlib>

class Treap;

class TreatNode
{
public:
	int key, priority;// all priorities are distinct and also that all keys are distinct
	TreatNode* leftchild, * rightchild, * parent;
	TreatNode(int data, TreatNode* f):key(data), leftchild(nullptr), rightchild(nullptr), parent(f)
	{}
	~TreatNode()
	{
		leftchild = nullptr;
		rightchild = nullptr;
	}
};

class Treap
{
private:
	TreatNode* root;
	int size;
public:
	Treap(int data):root(new TreatNode(data, nullptr))
	{
		root->priority = rand();
	}
	~Treap();
	void insert(int data);
	void remove(int data);
};


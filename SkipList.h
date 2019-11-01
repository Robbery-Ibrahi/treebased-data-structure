#pragma once
#include <cstdlib>

class SkipList;

class Node_of_SkipList
{
	friend class SkipList;
public:
	int data;
	Node_of_SkipList* next;
	Node_of_SkipList* above, * below;
	Node_of_SkipList(int newdata): data(newdata), next(nullptr), above(nullptr), below(nullptr)
	{}
	Node_of_SkipList(int newdata, Node_of_SkipList* local):data(newdata), next(nullptr), above(nullptr), below(local)
	{}
	~Node_of_SkipList()
	{
		next = nullptr;
		above = nullptr;
		below = nullptr;
	}
};

class SkipList
{
private:
	Node_of_SkipList* head, * tophead;
	int size, level;
public:
	SkipList(int headdata);
	~SkipList();
	void insert(int newdata);
	bool remove(int existdata);
};


#pragma once

class FibonacciHeap;

class Node_of_FibonacciHeap
{
	friend class FibonacciHeap;
public:
	int key;
	int degree;
	Node_of_FibonacciHeap* father, * leftbrother, * rightbrother, * firstchild;
	bool mark;
	Node_of_FibonacciHeap(int data, Node_of_FibonacciHeap* dad, Node_of_FibonacciHeap* left, Node_of_FibonacciHeap* right):key(data), leftbrother(left), father(dad), rightbrother(right)
	{}
	Node_of_FibonacciHeap()
	{}
	~Node_of_FibonacciHeap();
};

class FibonacciHeap
{
private:
	Node_of_FibonacciHeap* min;
	int size;
	int degree;
public:
	FibonacciHeap(int key) : min(new Node_of_FibonacciHeap(key, nullptr, nullptr, nullptr))
	{
		min->degree = 0;
		min->firstchild = nullptr;
		degree = 1;
	}
	~FibonacciHeap();
	void insert(int newdata);
	FibonacciHeap merge(FibonacciHeap& h1, FibonacciHeap& h2);
	void remove(int x);
	int findmin();
	void extractMin();
};


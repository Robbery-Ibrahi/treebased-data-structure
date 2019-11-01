#pragma once
constexpr auto red = true;
constexpr auto black = false;

class RedBlackTree;

class Node_of_RedBlackTree
{
	friend class Node_of_RedBlackTree;
public:
	bool colour;//true-red, false-black
	int data;
	Node_of_RedBlackTree* leftchild, * rightchild, *parent;
	Node_of_RedBlackTree(int newdata, bool color, Node_of_RedBlackTree* parents, Node_of_RedBlackTree* left, Node_of_RedBlackTree* right): data(newdata), colour(color), leftchild(left), rightchild(right), parent(parents)
	{}
	Node_of_RedBlackTree(int signal, bool color, Node_of_RedBlackTree* left, Node_of_RedBlackTree* right) :data(signal), colour(color), leftchild(left), rightchild(right)
	{}
	~Node_of_RedBlackTree()
	{
		leftchild = nullptr;
		rightchild = nullptr;
	}


};

class RedBlackTree
{
private:
	Node_of_RedBlackTree* root;
	int size;
	int length_of_black;
public:
	RedBlackTree(int rootdata)
	{
		Node_of_RedBlackTree* root = new Node_of_RedBlackTree(0, black, nullptr, nullptr, nullptr);
		Node_of_RedBlackTree* leftleaf = new Node_of_RedBlackTree(0, black, root, nullptr, nullptr);
		Node_of_RedBlackTree* righttleaf = new Node_of_RedBlackTree(0, black, root, nullptr, nullptr);
		root->leftchild = leftleaf;
		root->rightchild = righttleaf;
	}
	~RedBlackTree();
	void insert(int newdata);
	bool remove(int existdata);

};


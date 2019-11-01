#include "SkipList.h"

SkipList::SkipList(int headdata):head(new Node_of_SkipList(headdata)), size(1),level(1), tophead(head)
{

}

SkipList::~SkipList()
{

}

void SkipList::insert(int newdata)
{
	Node_of_SkipList* ahead = tophead;
	int levels = level;
	while (levels != 0)
	{
		while (ahead->next != nullptr && ahead->next->data < newdata)
		{
			ahead = ahead->next;
		}
		ahead = ahead->below;
		levels--;
	}
	Node_of_SkipList* newbuttomnode = new Node_of_SkipList(newdata);
	newbuttomnode->next = tophead->next;
	tophead->next = newbuttomnode;
	size++;
	Node_of_SkipList* uphead = head;
	int levell = 1;
	while (rand() % 2 == 1)
	{
		levell++;
		if (levell > level)
		{
			Node_of_SkipList* newhead = new Node_of_SkipList(head->data, tophead);
			tophead = newhead;
		}
		Node_of_SkipList* uplevel = new Node_of_SkipList(newdata, newbuttomnode);
		newbuttomnode->above = uplevel;
		newbuttomnode = uplevel;
		uphead = uphead->above;

		Node_of_SkipList* upthing = uphead;
		while (upthing->next != nullptr && upthing->next->data < newdata)
		{
			upthing = upthing->next;
		}
		uplevel->next = upthing->next;
		upthing->next = uplevel;
		level++;
	}
}

bool SkipList::remove(int existdata)
{
	Node_of_SkipList* top = tophead;
	while (top->below != nullptr)
	{
		if (top->next->data == existdata)
		{
			Node_of_SkipList* x = top->next;
			top->next = top->next->next;
			delete x;
		}
		if (top->next->data < existdata)
		{
			top = top->below;
			continue;
		}
		top = top->next;
	}
	while (top->next != nullptr)
	{
		if (top->next->data == existdata)
		{
			Node_of_SkipList* x = top->next;
			top->next = top->next->next;
			delete x;
			return true;
		}
		top = top->next;
	}
	return false;
}
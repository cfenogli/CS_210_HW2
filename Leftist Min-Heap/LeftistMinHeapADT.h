#pragma once
#include <cstddef>

template <class T>
class LeftistHeap;

template <class T>
class LeftistNode
{
	T element;
	LeftistNode* left;
	LeftistNode* right;
	int spl;

	LeftistNode(const T& theElement, LeftistNode* lt = NULL, LeftistNode* rt = NULL, int np = 1) :
		element(theElement), left(lt), right(rt), spl(np)
	{
	}

	friend class LeftistHeap<T>;
};

template <class T>
class LeftistHeap
{
public:
	LeftistHeap();
	LeftistHeap(const LeftistHeap& rhs);
	void insert(const T& x);
	void deleteMin();
	void merge(LeftistHeap& rhs);
	void showLH() const;
	void showLHHelper(LeftistNode<T>* p, int level) const;
	void showSPL() const;
	void showSPLHelper(LeftistNode<T>* p, int level) const;

private:
	LeftistNode<T>* root;
	LeftistNode<T>* merge1(LeftistNode<T>* h1, LeftistNode<T>* h2) const;
	LeftistNode<T>* merge2(LeftistNode<T>* h1, LeftistNode<T>* h2) const;
	void swapChildren(LeftistNode<T>* t) const;
};
#include "LeftistMinHeapADT.h"

#include <iostream>

using namespace std;

//default constructor
template <class T>
LeftistHeap<T>::LeftistHeap()
{
	root = NULL;
}

//copy constructor
template <class T>
LeftistHeap<T>::LeftistHeap(const LeftistHeap& rhs)
{
	this->merge(rhs);
}

//swap children of node t
template <class T>
void LeftistHeap<T>::swapChildren(LeftistNode<T>* t) const
{
	LeftistNode<T>* temp = t->left;
	t->left = t->right;
	t->right = temp;
}

//Merge the rhs leftist heap into the leftist heap
//rhs becomes empty
template <class T>
void LeftistHeap<T>::merge(LeftistHeap& rhs)
{
	root = merge1(root, rhs.root);
	rhs.root = NULL;
}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge1(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{
	if (h1 == NULL)
	{ 
		return h2;
	}
	if (h2 == NULL)
	{
		return h1;
	}

	if (h1->element < h2->element)
	{
		return merge2(h1, h2);
	}
	else
	{
		return merge2(h2, h1);
	}
}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge2(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{
	//recursively merge right subtree of h1 with h2
	h1->right = merge1(h1->right, h2);
	//swap children if needed
	if (h1->right != NULL)
	{
		if (h1->left == NULL || h1->left->spl < h1->right->spl)
		{
			swapChildren(h1);
		}
		if (h1->right != NULL)
		{
			//update the spl of merged root
			h1->spl = h1->right->spl + 1;
		}
	}
	return h1;
}

template <class T>
void LeftistHeap<T>::insert(const T& x)
{
	root = merge1(new LeftistNode<T>(x), root);
}

template <class T>
void LeftistHeap<T>::deleteMin()
{
	LeftistNode<T>* oldRoot = root;
	root = merge1(root->left, root->right);
	delete oldRoot;
}

//prints the elements/priority values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showLH() const
{
	if (root == 0)
	{
		cout << "Empty tree" << endl;
	}
	else
	{
		cout << endl;
		showLHHelper(root, 1);
		cout << endl;
	}
}

//recursive helper for showLH
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showLHHelper(LeftistNode<T>* p, int level) const
{
	int j;
	if (p != 0)
	{
		//right subtree
		showLHHelper(p->right, level + 1);
		for (j = 0; j < level; j++) cout << "\t";

		//node pointed to by p itself
		cout << " " << p->element;

		if ((p->left != 0) && (p->right != 0)) cout << "<";
		else if (p->right != 0) cout << "/";
		else if (p->left != 0) cout << "\\";
		cout << endl;

		//left subtree
		showLHHelper(p->left, level + 1);
	}
}

//prints the SPL values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showSPL() const
{
	if (root == 0)
	{
		cout << "Empty tree" << endl;
	}
	else
	{
		cout << endl;
		showSPLHelper(root, 1);
		cout << endl;
	}
}

//recursive helper for showSPL
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showSPLHelper(LeftistNode<T>* p, int level) const
{
	int j;
	if (p != 0)
	{
		//right subtree
		showSPLHelper(p->right, level + 1);
		for (j = 0; j < level; j++) cout << "\t";

		//node pointed to by p itself
		cout << " " << p->spl;

		if ((p->left != 0) && (p->right != 0)) cout << "<";
		else if (p->right != 0) cout << "/";
		else if (p->left != 0) cout << "\\";
		cout << endl;

		//left subtree
		showSPLHelper(p->left, level + 1);
	}
}
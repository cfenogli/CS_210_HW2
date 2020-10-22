#include "LeftistMinHeapADT.cpp"

#include <iostream>

using namespace std;

int main()
{
	cout << "Supplied test cases:\n**********" << endl;

	//LH1
	LeftistHeap<int> lhInt1 = LeftistHeap<int>();
	lhInt1.insert(5);
	lhInt1.insert(6);
	lhInt1.insert(12);
	lhInt1.insert(15);
	cout << "LH1:\n" << endl;
	cout << "Print SPL values:" << endl;
	lhInt1.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt1.showLH();
	cout << endl;

	//LH2
	LeftistHeap<int> lhInt2 = LeftistHeap<int>();
	lhInt2.insert(7);
	lhInt2.insert(14);
	lhInt2.insert(3);
	lhInt2.insert(8);
	lhInt2.insert(11);
	cout << "LH2:\n" << endl;
	cout << "Print SPL values:" << endl;
	lhInt2.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt2.showLH();
	cout << endl;

	//merge
	cout << "Merge(LH1,LH2):\n" << endl;
	lhInt1.merge(lhInt2);
	cout << "Print SPL values:" << endl;
	lhInt1.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt1.showLH();
	cout << endl;

	//LH3
	LeftistHeap<int> lhInt3 = LeftistHeap<int>();
	lhInt3.insert(77);
	lhInt3.insert(22);
	lhInt3.insert(9);
	lhInt3.insert(68);
	lhInt3.insert(16);
	lhInt3.insert(34);
	lhInt3.insert(13);
	lhInt3.insert(8);
	cout << "LH3:\n" << endl;
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;

	//deleteMin
	cout << "DeleteMin(LH3):\n" << endl;
	lhInt3.deleteMin();
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;
	cout << "DeleteMin(LH3):\n" << endl;
	lhInt3.deleteMin();
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;

	cout << "Our group's test cases:\n**********" << endl;

	//LH4
	LeftistHeap<int> lhInt4 = LeftistHeap<int>();
	lhInt4.insert(20);
	lhInt4.insert(1);
	lhInt4.insert(10);
	lhInt4.insert(43);
	lhInt4.insert(-5);
	cout << "LH4:\n" << endl;
	cout << "Print SPL values:" << endl;
	lhInt4.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt4.showLH();
	cout << endl;
	cout << "DeleteMin(LH4):\n" << endl;
	lhInt4.deleteMin();
	cout << "Print SPL values:" << endl;
	lhInt4.showSPL();
	cout << endl;
	cout << "Print priority values:" << endl;
	lhInt4.showLH();
	cout << endl;

}
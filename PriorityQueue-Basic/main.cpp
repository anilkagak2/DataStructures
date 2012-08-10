/*	Created by Anil Kag (anilkagak2@gmail.com)

	Priorty Queue Usage
	Using a binary max heap tree for implementation
*/

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
	PriorityQueue p;

	p.insert(100,5);
	p.insert(101,4);
	p.insert(102,7);
	p.insert(103,4);
	p.insert(104,2);

	p.print();
	p.delMax();
	p.delMax();
	p.delMax();

	p.print();
	p.insert(105,10);
	p.delMax();
	p.insert(106,7);

	p.print();

	return 0;
}

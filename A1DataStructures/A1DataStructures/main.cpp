#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
	
	OrderedArray<int> orderedarray(5);
	orderedarray.push(6);
	orderedarray.push(4);
	orderedarray.push(10);
	orderedarray.push(1);
	orderedarray.push(3);
	orderedarray.Print();

	return 0;
}
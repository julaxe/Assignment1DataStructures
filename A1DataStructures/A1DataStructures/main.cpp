#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
	
	OrderedArray<int> orderedarray(5);
	orderedarray.push(6);
	orderedarray.push(4);
	orderedarray.push(10);
	orderedarray.push(1);
	orderedarray.push(3);
	orderedarray.Print("Ordered Array: ");

	auto unordered = new UnorderedArray<int>(3);
	unordered->push(6);
	unordered->push(4);
	unordered->push(10);
	unordered->push(1);
	unordered->push(3);
	unordered->Print("UnOrdered Array: ");


	return 0;
}
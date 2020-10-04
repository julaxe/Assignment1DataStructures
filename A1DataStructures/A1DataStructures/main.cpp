// Assignment 1 Data Structures
// Julian Escobar Echeverri
// Student Number: 101286557

#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {

	OrderedArray<int> orderedarray(5, false); // true-> for duplicate data
	orderedarray.push(6);
	orderedarray.push(4);
	orderedarray.push(10);
	orderedarray.push(1);
	orderedarray.push(1);
	orderedarray.push(1);
	orderedarray.push(1);
	orderedarray.push(3);
	orderedarray.push(6);
	
	orderedarray.Print("Ordered Array: ");

	auto* unordered = new UnorderedArray<int>(1); // checking expand by increasing value
	unordered->push(6);
	unordered->push(4);
	unordered->push(10);
	unordered->push(1);
	unordered->push(3);
	unordered->push(20);
	unordered->push(7);
	unordered->push(7);
	unordered->push(7);
	unordered->Print("UnOrdered Array: ");


	return 0;
}
/*
https://www.geeksforgeeks.org/c-program-hashing-chaining/
*/

#include <iostream> 
#include <list> 
using namespace std;

class Hash
{
	int chain;    // number of chains 

	// Pointer to an array containing buckets 
	list<int> *table;
public:
	Hash(int V);  // Constructor 

	// inserts a key into hash table 
	void insertItem(int x);

	// find a key in hash table 
	void findItem(int key);

	// deletes a key from hash table 
	void deleteItem(int key);

	// hash function to map values to key 
	int hashFunction(int x) {
		return (x % chain);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	chain = b;
	table = new list<int>[chain];
}

void Hash::insertItem(int key)
{
	cout << "Insert Item: " << key << endl;
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::findItem(int key)
{
	cout << "FindItem: " << key << endl;

	// get the hash index of key 
	int index = hashFunction(key);

	// find the key in (inex)th list 
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	if (i != table[index].end()) {
		cout << "Found at index: " << index << endl;
	}
	else {
		cout << "Not found" << endl;
	}
}


void Hash::deleteItem(int key)
{
	cout << "deleteItem: " << key << endl;

	// get the hash index of key 
	int index = hashFunction(key);

	// find the key in (inex)th list 
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it 
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table 
void Hash::displayHash()
{
	cout << "displayHash" << endl;
	for (int i = 0; i < chain; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
	cout << endl;
}

// Driver program  
int main()
{
	// array that contains keys to be mapped 
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash table 
	Hash h(4);   // 4 is count of buckets in 
				 // hash table 
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	// display the Hash table 
	h.displayHash();

	// delete 12 from hash table 
	h.deleteItem(12);

	// display the Hash table 
	h.displayHash();

	h.findItem(12);

	return 0;
}

#include <iostream>
#include <stack>

using namespace std;

int main (int argc,char *argv[]) {
	stack<int> sint;
	sint.push (1);
	sint.push (2);
	sint.push (3);
	sint.push (4);
	sint.push (5);
	sint.push (6);

	cout << "Size is " << sint.size () << endl;

	// buggy piece of code due to sint.size () as this will change on each sint.pop ()
	/*
	for (int i=0; i < sint.size (); i++) {
		cout << i  << " " << sint.top () << endl;
		sint.pop ();
	}*/
	while (!sint.empty ()) {
		cout << " " << sint.top () << endl;
		sint.pop ();
	}

	sint.pop ();
	sint.pop ();

	return 0;
}

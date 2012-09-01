#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main (int argc,char *argv[]) {
	stack<string> sint;
	sint.push ("anil");
	sint.push ("kag");
	sint.push ("CSE");
	sint.push ("hello world");
	sint.push ("pintos");
	sint.push ("linux");

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

	return 0;
}

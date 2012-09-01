#include <iostream>
#include <map>
#include <string>

using namespace std;

int main () {
	map<string,float> cpi_map;
	map<string,float>::iterator it;

	cpi_map["anil"] = 9.32;
	cpi_map["dummy1"] = 9.69;
	cpi_map["dummy2"] = 9.12;
	cpi_map["dummy3"] = 9.37;
	cpi_map["dummy4"] = 9.10;

	it = cpi_map.find("dummy3");
	if (it != cpi_map.end ())
		cout << it->first << "'s CPI is " << it->second << "\n";

	cpi_map.erase (it);

	for (it = cpi_map.begin (); it !=cpi_map.end () ; it++)
		cout << it->first << "'s CPI is " << it->second << "\n";

	return 0;



}

#include <iostream>
#include <string>
using namespace std;

class Baseball
{
public:
	string guess(const string & str)
	{
		throw length_error("Must be three letters.");
		return "12";
	}
};
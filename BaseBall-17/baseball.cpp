#include <iostream>
#include <string>
using namespace std;

class Baseball
{
public:
	string guess(const string & str)
	{
		if (str.length() != 3)
		{
			throw length_error("Must be three letters.");
		}
		
	}
};
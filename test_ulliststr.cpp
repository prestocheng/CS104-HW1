#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  for(int count = 0; count < 4; ++count)
	{
		list.push_back("test");

		cout << list.get(0) << endl;

		list.pop_back();

		cout << list.size() << list.empty() << endl;
	}
}

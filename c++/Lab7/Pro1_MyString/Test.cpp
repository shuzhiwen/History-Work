#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
	MyString s1("zhang3");
	MyString s2(s1);

	MyString s3 = s1 + s2;
	
	cout << s3 << endl;
	return 0;
}
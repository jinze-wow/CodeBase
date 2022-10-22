#include <iostream>
using namespace std;
#include <string>
void printf(int i) {
	cout << "ÕûÊýint£º" << i << endl;
}
void printf(const string s) {
	cout << "×Ö·û´®string:" << s << endl;
}
int main() {
	int a = 10;
	string s = "my name is Cui";
	printf(a);
	printf(s);
}

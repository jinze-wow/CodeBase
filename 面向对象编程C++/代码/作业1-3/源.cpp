#include <iostream>
using namespace std;
#include <string>
void printf(int i) {
	cout << "����int��" << i << endl;
}
void printf(const string s) {
	cout << "�ַ���string:" << s << endl;
}
int main() {
	int a = 10;
	string s = "my name is Cui";
	printf(a);
	printf(s);
}

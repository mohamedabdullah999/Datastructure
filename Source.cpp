#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack <int> st;
	st.push(5);
	st.push(4);
	st.push(2);
	st.display();
	st.pop();
	st.display();
	int x = 0;
	st.pop_last(x);
	cout << x << endl;
	st.display();
	return 0;
}
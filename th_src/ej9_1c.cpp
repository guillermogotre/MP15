#include <iostream>
using namespace std;

void SliceString(char string[], int ini, int end);

int main(){
	char w1[] = "Hola Mundo",
		w2[] = "Hola Mundo",
		w3[] = "Hola Mundo";

	SliceString(w1, 0, 100);
	SliceString(w2, 3, 9);
	SliceString(w3, -10, 0);

	cout << w1 << endl
		<< w2 << endl
		<< w3 << endl;
}

// SliceString() modify the string from
// the "ini" to the "end" (not included)
// or the former end position if this is 
// greater than the C string size
void SliceString(char string[], int ini, int end){
	int i = 0,
		w = 0;
	ini = (ini >= 0)? ini:0;
	while(string[i] != '\0' && i < end){
		if(i >= ini)
			string[w++] = string[i];
		i++;
	}
	string[w] = '\0';
}
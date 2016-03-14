#include <iostream>
using namespace std;

void StringInsert(char origin[], char to_add[], int pos);
int StringSize(char string[]);

int main(){
	char to_add[] = "ABC",
		str1[30] = "Aq\"\"ui",
		str2[30] = "Aqui\"",
		str3[30] = "\"Aqui";
	StringInsert(str1, to_add, 3);
	StringInsert(str2, to_add, 50);
	StringInsert(str3, to_add, -50);

	cout << str1 << endl
		<< str2 << endl
		<< str3 << endl;
}

// Insert a to_add[] CString into origin[] CString
// at a given position, the developer must be sure
// that the given array has enough positions in
// memory for both CStrings.
void StringInsert(char origin[], char to_add[], int pos){
	int origin_size = StringSize(origin),
		to_add_size = StringSize(to_add);
	
	pos = (pos<0)? 0:pos;
	pos = (pos>origin_size)? origin_size:pos;

	for(int i = origin_size-1; i >= pos; i--)
		origin[i + to_add_size] = origin[i];
	
	for(int i = 0; i < to_add_size; i++)
		origin[i + pos] = to_add[i];

	origin[origin_size + to_add_size] = '\0';
}

int StringSize(char string[]){
	int i;
	for(i=0; string[i] != '\0'; i++)
		;
	return i;
}
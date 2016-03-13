#include <iostream>

using namespace std;

void RemoveSpaces(char array[], int &size);

int main(){
	char array[]={' ','a','h',' ',' ',' ','c'};
	int size = 7;
	RemoveSpaces(array,size);
	cout << '"';
	for(int i=0; i < size; i++)
		cout << array[i];
	cout << '"' << endl;
}

void RemoveSpaces(char array[], int &size){
	int w_pos,
		r_pos;
	bool space,
		next_space,
		last_pos;

	for(w_pos = r_pos = 0; r_pos < size; r_pos++){
		space = array[r_pos] == ' ';
		last_pos = r_pos+1 == size;
		next_space= last_pos? false : array[r_pos+1] == ' ';
		if(!(space && next_space))
			array[w_pos++] = array[r_pos];
	}
	size = w_pos;
}
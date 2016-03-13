#include <iostream>
using namespace std;

void QuickSort(double array_ori[], double array_dest[], int ini, int end);
void PrintArray(const double array[], int size);

int main(){
	const int SIZE = 200000;
	double array_ori[SIZE],
		array_dest[SIZE];

	for(int i=0; i< SIZE; i++)
		cin >> array_ori[i];

	start_time = clock();

	QuickSort(array_ori, array_dest, 0, SIZE);

	PrintArray(array_dest, SIZE);
}

// array_dest is just for memory purpouse, they'll end up
// with the same values in both arrays.
// It's up to you to preserve the original one.
void QuickSort(double array_ori[], double array_dest[], int ini, int end){
	double pivot = array_ori[ini];
	int size1 = 0,
		size2 = 0;

	//We order the values:
	//Highers from the left
	//Lowers from the right	
	for(int i = ini+1; i < end; i++){
		if(array_ori[i] > pivot){
			array_dest[ini + size1] = array_ori[i];
			size1++;
		}
		else{
			array_dest[end -1 - size2] = array_ori[i];
			size2++;
		}
	}

	//We set the pivot in its position
	array_ori[size1 + ini] = array_dest[size1 + ini] = pivot;

	//We check the size of the left part
	if(size1>1)
		//Call QuickSort if >1
		QuickSort(array_dest, array_ori, ini, ini + size1);
	else if(size1 == 1)
		//Else we fix the value in the origin too
		array_ori[ini] = array_dest[ini];

	//The same in here for the right part
	if(size2>1)
		QuickSort(array_dest, array_ori, end - size2, end);
	else if(size2 == 1)
		array_ori[end-1] = array_dest[end-1];
}

void PrintArray(const double array[], int size){
	for(int i=0; i<size; i++)
		cout << array[i] << " ";
	cout << endl;
}
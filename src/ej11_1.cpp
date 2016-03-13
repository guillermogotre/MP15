#include <iostream>
using namespace std;

const int FIL = 30
		, COL = 30;

int SumaDiagonal(const int matriz[][COL], int tamanio);

int main(){
	int diag1[FIL][COL] = {{1}},
		diag2[FIL][COL] = {{1,2,3},{4,1,6},{7,8,1}};
	cout << SumaDiagonal(diag1,1) << endl;
	cout << SumaDiagonal(diag2,3) << endl;
}

int SumaDiagonal(const int matriz[][COL], int tamanio){
	int acum = 0;
	for (int i=0; i < tamanio; i++)
		acum += matriz[i][i];
	return acum;
}

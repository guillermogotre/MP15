#include <iostream>
using namespace std;

const int ROW = 50,
		COL = 4;

void KFirstValuesF(int k, double table[][COL]);
void PrintMatrix(double table[][COL], int row, int col);

int main(){
	double table[ROW][COL];
	KFirstValuesF(ROW, table);
	PrintMatrix(table, ROW, COL);
}

void KFirstValuesF(int k, double table[][COL]){
	table[0][0] = 0,
	table[0][1] = table[0][2] = table[0][3] = 1;
	for(int i=1; i < k; i++){
		//k value
		table[i][0] = i;
		//a value
		table[i][1] = table[i-1][2];
		//b value
		table[i][2] = table[i-1][1] + 2*table[i-1][2];
		//a/b value
		table[i][3] = table[i][1]/table[i][2];
	}
}
		
void PrintMatrix(double table[][COL], int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << table[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}
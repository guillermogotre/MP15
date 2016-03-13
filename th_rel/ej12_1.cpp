#include <iostream>
using namespace std;

const int ROW = 50,
	COL = 50;

void Transpose(const int matrix_ori[][COL], int matrix_dest[][COL], int row_u, int col_u);
void PrintMatrix(const int matrix[][COL], int row_u, int col_u);
void ExchangeVar(int &var1, int &var2);

int main(){
	int matrix1[ROW][COL]={{1,2,3},{4,5,6}},
		matrix2[ROW][COL]={{1,2},{3,4},{5,6}},
		matrix3[ROW][COL],
		row_u1 = 2,
		col_u1 = 3,
		row_u2 = 3,
		col_u2 = 2;
	
	Transpose(matrix1, matrix3, row_u1, col_u1);
	PrintMatrix(matrix1, row_u1, col_u1);
	ExchangeVar(row_u1, col_u1);
	PrintMatrix(matrix3, row_u1, col_u1);
	
	Transpose(matrix2, matrix3, row_u2, col_u2);
	PrintMatrix(matrix2, row_u2, col_u2);
	ExchangeVar(row_u2, col_u2);
	PrintMatrix(matrix3, row_u2, col_u2);
}

void Transpose(const int matrix_ori[][COL], int matrix_dest[][COL], int row_u, int col_u){
	for(int i=0; i < row_u; i++)
		for(int j=0; j < col_u; j++)
			matrix_dest[j][i] = matrix_ori[i][j];
}

void PrintMatrix(const int matrix[][COL], int row_u, int col_u){
	for(int i=0; i<row_u; i++){
		for (int j=0; j<col_u; j++)
			cout << matrix[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}

void ExchangeVar(int &var1, int &var2){
	int var_temp = var1;
	var1 = var2;
	var2 = var_temp;
}


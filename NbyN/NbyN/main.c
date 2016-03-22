#include <stdio.h>
#include <stdlib.h>

int count;

void print(int array[100][100], int row, int col);
void up(int array[100][100], int row, int col);
void left(int array[100][100], int row, int col);
void down(int array[100][100], int row, int col);
void right(int array[100][100], int row, int col);

int main(){

	int n;
	int row, col, temp;
	int array[100][100]={0, };

	do{
		printf("input a number :");
		scanf("%d", &n);

		if(n < 1 || n > 100){
			printf("out of range (1 ~ 100)\n");
		}
	}while(n < 1 || n > 100);

	count = n*n;
	temp = 1;
	for(row = 0; row < n; row++){
		for(col = 0; col < n; col++){
			array[row][col] = temp;
			temp++;
		}
	}

	for(row = 0; row < n; row++){
		for(col = 0; col < n; col++){
			if(array[row][col] != 0)
				printf("%3d", array[row][col]);	
		}
		printf("\n");
	}

	
	print(array, n-1, n-1);
	
}

void print(int array[100][100], int row, int col){
	up(array, row, col);
}

void up(int array[100][100], int row, int col){
	
	while(1){
		printf("%3d", array[row][col]);
		array[row][col] = 0;
		count--;
		if (count == 0)
			return;

		if(array[row-1][col] ==0 || row == 0){
			left(array, row, --col);
			return;
		}
		row--;
	}
}
void left(int array[100][100], int row, int col){

	while(1){
		printf("%3d", array[row][col]);
		array[row][col] = 0;
		count--;
		if (count == 0)
			return;

		if(array[row][col-1] ==0 || col == 0){
			down(array, ++row, col);
			return;
		}
		col--;
	}
}
void down(int array[100][100], int row, int col){

	while(1){
		printf("%3d", array[row][col]);
		array[row][col] = 0;
		count--;
		if (count == 0)
			return;

		if(array[row+1][col] == 0){
			right(array, row, ++col);
			return;
		}
		row++;
	}
}
void right(int array[100][100], int row, int col){

	while(1){
		printf("%3d", array[row][col]);
		array[row][col] = 0;
		count--;
		if (count == 0)
			return;

		if(array[row][col+1] ==0){
			up(array, --row, col);
			return;
		}
		col++;
	}
}


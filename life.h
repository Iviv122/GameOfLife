#include <stdio.h>
#include <stdlib.h>



void setLife(int** matrix,int posX,int posY){

matrix[posX][posY] = 1;
}


void unsetLife(int** matrix,int posX,int posY){

matrix[posX][posY] = 0;
}

int getNeighbors(int** matrix, int x, int y){

	int count = 0;
	
	for(int i=-1;i<=1;i++){
	for(int j=-1;j<=1;j++){

	if(i == 0 && j == 0) continue;
	int nx = x+i;
	int ny = y+j;


	if(nx >= 0 && ny >=0 && ny < 500 && nx <500 ){
		if(matrix[nx][ny] != 0) count++;

	}}}

	return count;

}

void updateLife(int** matrix, int ** newmatrix, int x, int y){
	int count = getNeighbors(matrix,x,y);
	if(count <2 || count > 3){
	unsetLife(newmatrix,x,y);
	}else if(count == 3){
	setLife(newmatrix,x,y);
	}else if(count ==2 && matrix[x][y] == 1){
	setLife(newmatrix,x,y);
	}

}


#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "life.h"

int main(void){

	GLFWwindow* window;


	int WIDTH =500;
	int HEIGHT = 500;

	float scale = (float)1/WIDTH;

	int**	matrix = (int**)calloc(WIDTH,sizeof(int*));
	int**	tempmatrix = (int**)calloc(WIDTH,sizeof(int*));
	
	for(int i=0;i<WIDTH;i++){
	matrix[i] = (int*)calloc(HEIGHT,sizeof(int));
	tempmatrix[i] = (int*)calloc(HEIGHT,sizeof(int));	
	}

	if (matrix == NULL || tempmatrix == NULL) {
    		fprintf(stderr, "Memory allocation failed for matrix rows\n");
    		exit(EXIT_FAILURE);
	}

	for(int i=-10;i<10;i++){
	setLife(matrix,249,250+i);
	}
	if(!glfwInit()) return-1;

	window = glfwCreateWindow(WIDTH,HEIGHT,"GameOfLife",NULL,NULL);	
	if (!window)
	{
	glfwTerminate();
	return -1;
	}
	glfwMakeContextCurrent(window);


	while(!glfwWindowShouldClose(window)){

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glScalef(scale*2,scale*2,scale*2);
	glBegin(GL_POINTS);
	
	for(int x=0;x<WIDTH;++x){
	for(int y=0;y<HEIGHT;++y){
	
	updateLife(matrix,tempmatrix,x,y);
	if(matrix[x][y]!=0) glVertex2f(x-(WIDTH/2),y-(HEIGHT/2));
	

	}
	}
	
	int** temp = matrix;
	matrix = tempmatrix;
	tempmatrix = temp;

	glEnd();
	

	glfwSwapBuffers(window);
	glfwPollEvents();
}
free(matrix);
glfwTerminate();
return 0;	
}

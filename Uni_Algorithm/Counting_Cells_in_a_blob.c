/*
 * test.c
 *
 *  Created on: 2019. 9. 28.
 *      Author: IoT-30
 */

#include <stdio.h>
#define BACKGROUND_PIXEL 0
#define IMAGE_PIXEL 1
#define COUNTED 2

int cells[][8]={
		{0,0,1,0,0,0,0,1},
		{1,1,0,0,0,1,0,0},
		{0,0,1,0,1,0,1,0},
		{0,0,0,0,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{1,0,0,0,1,1,0,0},
		{0,1,1,0,0,0,1,1}
};

int countCells(int x, int y){
	int count=0;
	if((cells[x][y]==BACKGROUND_PIXEL)||(cells[x][y]==COUNTED)||x*y<0||x*y>64){
		return 0;
	}
	else{
		count++;
		cells[x][y]=COUNTED;
		count=count+countCells(x-1,y+1)+countCells(x-1,y)
		+countCells(x-1,y-1)+countCells(x,y+1)+countCells(x,y-1)
		+countCells(x+1,y)+countCells(x+1,y-1)+countCells(x+1,y+1);
	}
	return count;
}

int main(){
	printf("%d\n",countCells(3,5));
}

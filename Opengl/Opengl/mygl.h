#ifndef _MYGL_H_
#define _MYGL_H_


#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void putPixel(int x, int y,int r, int g, int b, int a){
	int s= 4 * x + 4 * y * IMAGE_WIDTH + 0;
	printf("  %d  ",s);
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 0] = r;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 1] = g;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 2] = b;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 3] = a;
}

void drawLine(int x, int y,int r, int g, int b, int a,int x1, int y1,int r1, int g1, int b1, int a1){
int dx= x1-x,dy=y1-y;
int intery=y,interx=x1;//intersection
	printf("delta %d %d ",dx,dy);
	printf("|x %d %d",x,y);
	printf("and y %d to %d |",y,y1);
	if(dx<0){
		dx=-dx;
		int aux=x;
		x=x1;
		x1=aux;
		
	}
	if(dy<0){
		dy=-dy;
		int aux=y;
		y=y1;
		y1=aux;
		
	}
	for(int i =x;i<=x1;i++){
		putPixel(i,intery,255,0,0,255);
	}
	for(int i =y;i<=y1;i++){
		putPixel(interx,i,255,0,0,255);
	}

	printf("| %d to %d ",x,x1);
	printf("and y %d to %d |",y,y1);
}


#endif // _MYGL_H_


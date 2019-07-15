#ifndef _MYGL_H_
#define _MYGL_H_


#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void putPixel(int x, int y,color c){
	int s= 4 * x + 4 * y * IMAGE_WIDTH + 0;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 0] = c.r;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 1] = c.g;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 2] = c.b;
	FBptr[4 * x + 4 * y * IMAGE_WIDTH + 3] = c.a;
}

 color mixColors(color c, color c1, float porcent){
	c.r= c.r*(1.0f-porcent)+c1.r*porcent;
	c.g= c.g*(1.0f-porcent)+c1.g*porcent;
	c.b= c.b*(1.0f-porcent)+c1.b*porcent;
	return c;
}


void drawLine(int x, int y,color c,int x1, int y1,color c1){
int dx= x1-x,dy=y1-y, pX,pY,p;
float step, fullstep, percent;//fullstep para criar interpolação
int intery=y,interx=x1;//intersection

//define quadrantes
	dx < 0 ? pX = -1 : pX = 1;
	dy < 0 ? pY = -1 : pY = 1;



	if(dx<0){
		dx=-dx;
	
		
	}
	if(dy<0){
		dy=-dy;
	
		
	}
	//pega o maior deslocamento x ou y
	dx> dy ? step = dx : step = dy;
	p=step/2;
	putPixel(x,y,c);
	fullstep= step;
	while(step > 0){
		percent = step/fullstep;
		printf("%f ",percent);
		if(dx> dy){
			x+= pY;
			p-=dx;
			
			if(p>=dx){
				y+=pY;
				p-=dx;
			}
		}else{
			y+= pY;
			p += dx;
			
			if(p >=dy){
				x += pX;
				p -=dy;
			}
		}
		color cf;
		if(pX>1){
			 cf= mixColors(c,c1,percent);
		}else{
			cf= mixColors(c1,c,percent);
		}
		
		putPixel(x,y,cf);
		printf(" %d %d %d \n",cf.r,cf.g,cf.b);
		step--;
	}

	/*for(int i =x;i<=x1;i++){
		putPixel(i,intery,255,0,0,255);
	}
	for(int i =y;i<=y1;i++){
		putPixel(interx,i,255,0,0,255);
	}

	printf("| %d to %d ",x,x1);
	printf("and y %d to %d |",y,y1);*/
}
void drawTriangule(int x, int y, color c, int x1, int y1, color c1, int x2, int y2, color c2){
	drawLine(x,y,c,x1,y1,c1);
	drawLine(x1,y1,c1,x2,y2,c2);
	drawLine(x2,y2,c2,x,y,c);
}

#endif // _MYGL_H_


#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
	int x,y,x1,y1,x2, y2;
	color c,c1,c2;

	/****** para desenhar linhas******

	scanf("%d %d",&x,&y);
	
	scanf("%d %d %d %d",&c.r,&c.g,&c.b,&c.a);
	
	putPixel(x,y,c);
	*/

	/****** para desenhar linhas******

	scanf("%d %d",&x,&y);
	scanf("%d %d",&x1,&y1);
	scanf("%d %d %d %d",&c.r,&c.g,&c.b,&c.a);
	scanf("%d %d %d %d",&c1.r,&c1.g,&c1.b,&c1.a);
	drawLine(x,y,c,x1,y1,c1);
	*/
	//para desenhar triangulos
	scanf("%d %d",&x,&y);
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);
	scanf("%d %d %d %d",&c.r,&c.g,&c.b,&c.a);
	scanf("%d %d %d %d",&c1.r,&c1.g,&c1.b,&c1.a);
	scanf("%d %d %d %d",&c2.r,&c2.g,&c2.b,&c2.a);
	drawTriangule(x,y,c,x1,y1,c1,x2,y2,c2);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}


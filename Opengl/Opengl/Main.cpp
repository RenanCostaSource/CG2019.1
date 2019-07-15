#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	/* 	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			putPixel(i,j,255,0,0,255);
			
		
			
		}
	}*/
	int x,y,x1,y1;
	scanf("%d %d",&x,&y);
	scanf("%d %d",&x1,&y1);
	drawLine(x,y,0,0,0,0,x1,y1,0,0,0,0);
/* for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			putPixel(i, j, 0,0, 0, 0);
			
		}
	}*/
	
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


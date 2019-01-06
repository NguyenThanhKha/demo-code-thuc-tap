#include<stdio.h>
#include<graphics.h>
#include<coino.h>
int main()
{
	int mh=0,mode=0;
	initgraph(&mh,&mode,"");
	closegraph();
	printf("\ gia tri%d:",mh);
	getch();
}

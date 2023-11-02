#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

//DUONG TRON
void circle(int xc, int yc, int x, int y, int color){
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc + y, color);
	putpixel(xc - x, yc - y, color);
	putpixel(xc + x, yc - y, color);
	
	putpixel(xc + y, yc + x, color);
	putpixel(xc - y, yc + x, color);
	putpixel(xc - y, yc - x, color);
	putpixel(xc + y, yc - x, color);
}

void bres(int xc, int yc, int r){
	int x = 0;
	int y = r;
	int d = 3 - 2*r;
	while(x < y){
		circle(xc, yc, x, y, 4);
		if(d < 0)
		d = d + 4*x +6;
		else{
			d = d + 4*(x-y) + 10;
			y--;
		}
		x++;
	}
}

void midPoint(int xc, int yc, int r){
	int x= 0;
	int y = r;
	float p = 5/4 - r;
	while(x < y){
		circle(xc, yc, x, y, 3);
		if(p < 0)
			p = p + 2*x +3;
		else{
			p = p + 2*(x-y) + 5;
			y--;
		}
		x++;
	}
}

//ELIP
void elip(int xc, int yc, int x, int y, int color){
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc + y, color);
	putpixel(xc - x, yc - y, color);
	putpixel(xc + x, yc - y, color);
}

void midPoint1(int xc, int yc, int rx, int ry){
	int x = 0;
	int y = ry;
	
	//VE MIEN 1
	float p1 = round(ry*ry - rx*rx*ry + rx*rx/4);
	int px = 0;
	int py = 2*rx*rx*y;
	while(px < py){
		elip(xc, yc, x, y, 5);
		px = px + 2*ry*ry;
		x++;
		if(p1 < 0)
			p1 = p1 + ry*ry + px;
		else {
			y--;
			py = py - 2*rx*rx;
			p1 = p1 + ry*ry + px - py;
		}
	}
	
	//VE MIEN 2
	float p2 = round(ry*ry*x*x + rx*rx*y*y - rx*rx*ry*ry);
	while(y > 0){
		elip(xc, yc, x, y, 5);
		py = py - 2*rx*rx;
		y--;
		if(p2 > 0)
			p2 = p2 + rx*rx -py;
		else{
			x++;
			px = px + 2*ry*ry;
			p2 = p2 + rx*rx - py + px;
		}
	}
}


int main(){
	initwindow(500, 500);
	
	//DUONG TRON
	bres(100,100,50);
	midPoint(150, 100, 50);
	
	//ELIP
	midPoint1(200, 200, 200, 70);
	getch();
}

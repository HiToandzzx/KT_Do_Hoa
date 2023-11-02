#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;


//DDA voi A(2, 3) B(12, ??
void drawLine1(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc + 1 va ysau = ytruoc + m
	int xsau = xa;
	float ysau = ya;
	for(; xsau<=xb; xsau++){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau+=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(12, ?? B(2, 3)
void drawLine2(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc - 1 va ysau = ytruoc - m
	int xsau = xa;
	float ysau = ya;
	for( ; xsau>=xb; xsau--){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau-=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(2, ?? B(12, 3)
void drawLine3(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc + 1 va ysau = ytruoc + m
	int xsau = xa;
	float ysau = ya;
	for(; xsau<=xb; xsau++){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau+=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(12, 3) B(2, ??
void drawLine4(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc - 1 va ysau = ytruoc - m
	int xsau = xa;
	float ysau = ya;
	for(; xsau>=xb; xsau--){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau-=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(3, 2) B(8, 12)
void drawLine5(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc + 1 va ysau = ytruoc + m
	int xsau = xa;
	float ysau = ya;
	for(; xsau<=xb; xsau++){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau+=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(8, 12) B(3, 2)
void drawLine6(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc - 1 va ysau = ytruoc - m
	int xsau = xa;
	float ysau = ya;
	for(; xsau>=xb; xsau--){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau-=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(8, 2) B(3, 12)
void drawLine7(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc - 1 va ysau = ytruoc - m
	int xsau = xa;
	float ysau = ya;
	for(; xsau>=xb; xsau--){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau-=m;
		putpixel(xsau, round(ysau), color);
	}
}

//DDA voi A(3, 12) B(8, 2)
void drawLine8(int xa, int ya, int xb, int yb, int color){
	float m = float(yb-ya)/(xb-xa);
	cout<<"He so goc = "<<m<<endl;
	//xsau = xtruoc + 1 va ysau = ytruoc - m
	int xsau = xa;
	float ysau = ya;
	for(; xsau<=xb; xsau++){
		cout<<"x = "<<xsau<<"; y = "<<round(ysau)<<endl;
		ysau+=m;
		putpixel(xsau, round(ysau), color);
	}
}


int main(){
	initwindow(500, 500);
	//line(10, 10, 200, 200);
	drawLine1(20, 30, 120, 80, 255);
	drawLine2(120, 80, 20, 30, 3);
	drawLine3(20, 80, 120, 30, 4);
	drawLine4(120, 30, 20, 80, 5);
	drawLine5(30, 20, 80, 120, 6);
	drawLine6(80, 120, 30, 20, 7);
	drawLine7(80, 20, 30, 120, 8);
	drawLine8(30, 120, 80, 20, 15);
	getch(); //press any key to out
}

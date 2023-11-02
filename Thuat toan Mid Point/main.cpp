#include<winbgim.h>
#include<iostream>
using namespace std;


// A(2, 3) B(12, 8)
void midPoint1(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) A + B/2;
	for(; x<=xb; x++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M <= 0)
			M += A;
		else{
			M = M + A + B;
			y++;
		}
	}
}

void midPoint2(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) -A - B/2;
	for(; x>xb; x--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M <= 0)
			M -= A;
		else{
			M = M - A - B;
			y--;
		}
	}
}

void midPoint3(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float)B/2 - A;
	for(; x>xb; x--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M >= 0)
			M = M - A;
		else{
			M = M - A + B;
			y++;
		}
	}
}

void midPoint4(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) B/2 - A;
	for(; x<xb; x++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M >= 0)
			M += A;
		else{
			M = M + A - B;
			y--;
		}
	}
}

//TRUONG HOP M > 1

// A(3, 2) B(8, 12)
void midPoint5(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M=(float) A/2 + B;
	for(; y<=yb; y++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M >= 0)
			M += B;
		else{
			M = M + B + A;
			x++;
		}
	}
}

void midPoint6(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) -A/2 - B;
	for(; y>yb; y--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M >= 0)
			M -= B;
		else{
			M = M - B - A;
			x--;
		}
	}
}

void midPoint7(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) -A/2 + B;
	for(; y<=yb; y++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M <= 0)
			M=M+B;
		else{
			M = M + B - A;
			x--;
		}
	}
}

void midPoint8(int xa, int ya, int xb, int yb, int color){
	int A = yb - ya;
	int B = -(xb-xa);
	int x = xa;
	int y = ya;
	float M = (float) A/2 - B;
	for(; y>yb; y--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tM = "<<M<<endl;
		putpixel(x, y, color);
		delay(1);
		if(M >= 0)
		{
			M = M - B + A;
			x++;
		}
		else
			M -= B;
	}
}

int main()
{
	initwindow(200,200);
	//TRUONG HOP M < 1
//	midPoint1(20, 30, 120, 80, 2);
//		cout<<"\n";
//	midPoint2(120, 80, 20, 30, 5);
//		cout<<"\n";
	midPoint3(12, 3, 2, 8, 6);
		cout<<"\n";
//	midPoint4(20, 80, 120, 30, 7);
//		cout<<"\n";
//	//TRUONG HOP M > 1
//	midPoint5(30, 20, 80, 120, 9);
//		cout<<"\n"; 
//	midPoint6(80, 120, 30, 20, 10);
//		cout<<"\n";
//	midPoint7(80, 20, 30, 120, 6);
//		cout<<"\n";
//	midPoint8(30, 120, 80, 20, 15);
	getch();
}

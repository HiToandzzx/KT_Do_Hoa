#include <winbgim.h> 
#include <iostream>
using namespace std;

//TRUONG HOP M < 1

// (2, 3) (12, 8)
void Bre1(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = dx - 2*dy;
	int x = xa;
	int y = ya;
	for(; x<=xb; x++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q + 2*dx - 2*dy;
			y++;
		}else
			Q = Q - 2*dy;
	}	
}

// (12, 8) (2, 3)
void Bre2(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = 2*dy - dx;
	int x = xa;
	int y = ya;
	for(; x>=xb; x--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q - 2*dx + 2*dy;
			y--;
		}else
			Q = Q + 2*dy;
	}	
}

// (2, 8) (12, 3)
void Bre3(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = dx + 2*dy;
	int x = xa;
	int y = ya;
	for(; x<=xb; x++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q + 2*dx + 2*dy;
			y--;
		}else
			Q = Q + 2*dy;
	}	
}

// (12, 3) (2, 8)
void Bre4(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = - dx - 2*dy;
	int x = xa;
	int y = ya;
	for(; x>=xb; x--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q - 2*dx - 2*dy;
			y++;
		}else
			Q = Q - 2*dy;
	}	
}

//TRUONG HOP M > 1

// A(3, 2) B(8, 12)
void Bre5(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = 2*dx - dy;
	int x = xa;
	int y = ya;
	for(; y<=yb; y++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x, y, color);
		delay(1);
		if(Q > 0){
			Q = Q + 2*dx - 2*dy;
			x++;
		}else
			Q = Q + 2*dx;
	}
}

void Bre6(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = - 2*dx + dy;
	int x = xa;
	int y = ya;
	for(; y>=yb; y--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q > 0){
			Q = Q - 2*dx + 2*dy;
			x--;
		}else{
			Q = Q - 2*dx;
		}
	}
}

void Bre7(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = -2*dx - dy;
	int x = xa;
	int y = ya;
	for(; y<=yb; y++){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q - 2*dx - 2*dy;
			x--;
		}else{
			Q = Q - 2*dx;
		}
	}
}

void Bre8(int xa, int ya, int xb, int yb, int color){
	int dx = xb - xa;
	int dy = yb - ya;
	int Q = 2*dx + dy;
	int x = xa;
	int y = ya;
	for(; y>=yb; y--){
		cout<<"x= "<<x<<"\ty= "<<y<<"\tQ= "<<Q<<endl;
		putpixel(x,y,color);
		delay(1);
		if(Q < 0){
			Q = Q - 2*dx - 2*dy;
			x++;
		}else{
			Q = Q - 2*dx;
		}
	}
}

int main()
{
	initwindow(500,500);
	// TRUONG HOP M < 1
//	Bre1(20, 30, 120, 80, 2);
//		cout<<"\n";
//	Bre2(120, 80, 20, 30, 5);
//		cout<<"\n";
//	Bre3(20, 80, 120, 30, 6);
//		cout<<"\n";
//	Bre4(120, 30, 20, 80, 7);
//		cout<<"\n";
//	// TRUONG HOP M > 1
//	Bre5(30, 20, 80, 120, 9);
//		cout<<"\n";
//	Bre6(8, 12, 3, 2, 10);
//		cout<<"\n";
	Bre7(8, 2, 3, 12, 4);
		cout<<"\n";
//	Bre8(30, 120, 80, 20, 15);
	getch();
}

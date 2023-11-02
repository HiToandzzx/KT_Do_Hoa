#include <graphics.h>
#include <stdio.h>

// TOA DO CUA SO CAT
int xwmin = 100; //LEFT
int xwmax = 300; //RIGHT
int ywmin = 100; //BOT
int ywmax = 300; //TOP
int x0, y0, x1, y1; //TOA DO DOAN THANG SAU KHI XEN TIA
int temp_x, temp_y; //TOA DO CUA DIEM TAM THOI
float m;

void khoiTaoWindow(){
	setcolor(15);
	// HAM STYLE FOR ALL LINE OF HCN
	setlinestyle(1, 0, 2);
	// HAM VE HCN
	rectangle(xwmin, ywmax, xwmax, ywmin);
}

// MA HOA DOAN THANG
int maHoa(int x, int y){
	//DIEM(X, Y) NAM HOAN TOAN BEN TRONG CUA SO
	if(x >= xwmin && x <= xwmax &&
	   y >= ywmin && y <= ywmax)
	{
		return 0;		
	}
	
	//DIEM(X, Y) NAM BEN TREN CUA SO
	if(x >= xwmin && x <= xwmax && y > ywmax)
	{
		return 8;		
	}
	
	//DIEM(X, Y) NAM BEN DUOI CUA SO
	if(x >= xwmin && x <= xwmax && y < ywmin)
	{
		return 4;		
	}
	
	//DIEM(X, Y) NAM BEN TRAI CUA SO
	if(x < xwmin && y >= ywmin && y <= ywmax)
	{
		return 1;		
	}
	
	//DIEM(X, Y) NAM BEN PHAI CUA SO
	if(x > xwmax && y >= ywmin && y <= ywmax)
	{
		return 2;		
	}
	
	//DIEM(X, Y) NAM GOC TREN BEN TRAI CUA SO
	if(x < xwmin && y > ywmax)
	{
		return 9;		
	}
	
	//DIEM(X, Y) NAM GOC TREN BEN PHAI CUA SO
	if(x > xwmax && y > ywmax)
	{
		return 10;		
	}
	
	//DIEM(X, Y) NAM GOC DUOI BEN TRAI CUA SO
	if(x < xwmin && y < ywmin)
	{
		return 5;		
	}
	
	//DIEM(X, Y) NAM GOC DUOI BEN PHAI CUA SO
	if(x > xwmax && y < ywmin)
	{
		return 6;		
	}
}

void timGiaoDiem(int x, int y){
	switch(maHoa(x, y)){
		//DIEM(X, Y) NAM HOAN TOAN BEN TRONG CUA SO
		case 0:
			temp_x = x;
			temp_y = y;
			break;
			
		// DIEM(X, Y) NAM BEN PHAI CUA SO
		case 2:
			temp_x = xwmax;
			temp_y = y + m*(temp_x - x);
			break;
			
		// DIEM(X, Y) NAM BEN TREN CUA SO
		case 8:
			temp_y = ywmax;
			temp_x = x + (temp_y - y)/m;
			break;
			
		// DIEM(X, Y) NAM BEN TRAI CUA SO
		case 1:
			temp_x = xwmin;
			temp_y = y + m*(temp_x - x);
			break;
			
		// DIEM(X, Y) NAM BEN DUOI CUA SO
		case 4:
			temp_y = ywmin;
			temp_x = x + (temp_y - y)/m;
			break;
			
		// DIEM(X, Y) NAM GOC TREN BEN TRAI CUA SO
		case 5:
			temp_y = ywmin;
			temp_x = x + (temp_y - y)/m;
			
			if(temp_x < xwmin){
				temp_x = xwmin;
				temp_y = y + m*(temp_x - x);
			}
			break;
			
		// DIEM(X, Y) NAM GOC DUOI BEN TRAI CUA SO
		case 9:
			temp_y = ywmax;
			temp_x = x + (temp_y - y)/m;
			
			if(temp_x < xwmin){
				temp_x = xwmin;
				temp_y = y + m*(temp_x - x);
			}
			break;
			
		// DIEM(X, Y) NAM GOC DUOI BEN PHAI CUA SO
		case 6:
			temp_x = xwmax;
			temp_y = y + m*(temp_x - x);
			
			if(temp_y < ywmin){
				temp_y = ywmin;
				temp_x = x + (temp_y - y)/m;
			}
			break;
			
		// DIEM(X, Y) NAM GOC TREN BEN PHAI CUA SO
		case 10:
			temp_y = ywmax;
			temp_x = x + (temp_y - y)/m;
			
			if(temp_x > xwmax){
				temp_x = xwmax;
				temp_y = y + m*(temp_x - x);
			}
			break;
	}
}

// THUAT TOAN XEN TIA COHEN_SUTHERLAND
void Cohen_Sutherland(int xa, int ya, int xb, int yb){
	// TIM HE SO GOC
	if(ya == yb){
		m = 0;
	}
	
	if(xa != xb && ya != yb){
		m = (float)(yb - ya)/(xb - xa);
	}
	
	if(xa == xb){
		m = 99999999;
	}
	
	// VE DOAN THANG CAN XEN TIA
	setcolor(2);
	line(xa, ya, xb, yb);
	
	printf("\nMa hoa A(%d, %d) = %d va B(%d, %d) = %d", xa, ya, maHoa(xa, ya), xb, yb, maHoa(xb, yb));
	
	// XET DIEM A TRUOC
	timGiaoDiem(xa, ya);
		x0 = temp_x;
		y0 = temp_y;
	// XET DIEM B SAU
	timGiaoDiem(xb, yb);
		x1 = temp_x;
		y1 = temp_y;
		
	// IN TOA DO SAU XEN TIA
	printf("\nx0 = %d, y0 = %d, x1 = %d, y1 = %d", x0, y0, x1, y1);
	
	// VE DUONG THANG NOI 2 TOA DO SAU XEN TIA
	// KIEM TRA GIAO DIEM CO THUOC CUA SO KHONG?
	if(x0 < xwmin || x0 > xwmax || y0 < ywmin || y0 > ywmax ||
	   x1 < xwmin || x1 > xwmax || y1 < ywmin || y1 > ywmax )
	{
		// KHONG LAM GI
	}else{
		delay(500);
		setcolor(13);
		line(x0, y0, x1, y1);
	}	
}

int main(){
	initwindow(500, 500);
	
	khoiTaoWindow();
	
///////////////////A TRONG, B NGOAI///////////////////////
	
	// AB NAM BEN TRONG
	Cohen_Sutherland(150, 280, 260, 150);
	
	// A TRONG, B PHAI
	Cohen_Sutherland(150, 280, 360, 150);
	
	// A TRONG, B TREN
	Cohen_Sutherland(150, 160, 150, 450);
	
	// A TRONG, B TRAI
	Cohen_Sutherland(200, 160, 20, 160);
	
	// A TRONG, B DUOI
	Cohen_Sutherland(150, 160, 150, 20);
	
///////////////////A NGOAI, B TRONG///////////////////////
	
	// B TRONG, A PHAI
	Cohen_Sutherland(360, 160, 160, 280);
	
	// B TRONG, A TREN
	Cohen_Sutherland(160, 450, 160, 140);
	
	// B TRONG, A TRAI
	Cohen_Sutherland(20, 160, 200, 160);
	
	// B TRONG, A DUOI
	Cohen_Sutherland(160, 20, 160, 200);
	
///////////////////A NGOAI, B NGOAI///////////////////////
	
	// A TRAI, B PHAI
	Cohen_Sutherland(50, 200, 350, 200);
	
	// A TREN, B DUOI
	Cohen_Sutherland(200, 50, 200, 350);
	
	// A TRAI, B TREN
	Cohen_Sutherland(50, 200, 200, 350);
	
	// A TRAI, B DUOI
	Cohen_Sutherland(50, 200, 350, 50);
	
	// A PHAI, B TREN
	Cohen_Sutherland(350, 200, 150, 350);
	
	// A PHAI, B DUOI
	Cohen_Sutherland(350, 200, 150, 350);
	
///////////////////A TREN, B TRONG///////////////////////

	// B TRONG, A TREN TRAI
	Cohen_Sutherland(50, 10, 150, 140);
	Cohen_Sutherland(10, 50, 150, 140);
	
///////////////////A DUOI, B TRONG///////////////////////

	// B TRONG, A DUOI TRAI
	Cohen_Sutherland(90, 450, 150, 140);
	Cohen_Sutherland(10, 450, 150, 140);
	
	// B TRONG, A DUOI PHAI
	Cohen_Sutherland(450, 30, 200, 170);
	Cohen_Sutherland(330, 10, 200, 170);
	
		
	// B TRONG, A DUOI PHAI
	Cohen_Sutherland(450, 430, 200, 170);
	Cohen_Sutherland(330, 410, 200, 170);
	
///////////////////A TRAI, B TREN (NGOAI CUA SO)///////////////////////
	Cohen_Sutherland(30, 200, 140, 450);
	getch();
}

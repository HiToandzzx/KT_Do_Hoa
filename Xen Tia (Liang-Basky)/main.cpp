#include <graphics.h>
#include <stdio.h>

// KHAI BAO BIEN
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;

// VE CUA SO CAT
void khoiTao(){
	setcolor(15);
	setlinestyle(1, 0, 2);
	rectangle(xwmin, ywmax, xwmax, ywmin);
}

float max(float a, float b){
	return (a > b) ? a : b;
}

float min(float a, float b){
	return (a < b) ? a : b;
}

void Liang_Barsky(int xa, int ya, int xb, int yb){
	// VE DT DI QUA A, B
	setcolor(4);
	line(xa, ya, xb, yb);
	
	// IN RA MH TOA DO DIEM A, B
	printf("\nToa do cua diem A(%d, %d) va B(%d, %d)\n", xa, ya, xb, yb);
	
	// TIM pk VA qk
	int dx = xb - xa;
	int dy = yb - ya;
	int p[4] = {-dx, dx, -dy, dy};
	int q[4] = {xa - xwmin, xwmax - xa, ya - ywmin, ywmax - ya};
	
	// IN RA MH pk VA qk
	printf("\npk[]: ");
	for(int i=0; i<4; i++){
		printf("%5d", p[i]);
	} 
	printf("\nqk[]: ");
	for(int i=0; i<4; i++){
		printf("%5d", q[i]);
	} 
	
	// TIM GIAO DIEM: X0, X1, Y0, Y1
	int x0, x1, y0, y1; // TOA DO GIAO DIEM CUA DT VOI CUA SO CAT
	float t1 = 0; // max(0, 
	float t2 = 1; // min(1, 
	for(int i=0; i<4; i++){
		if(p[i] < 0)
			t1 = max(t1, (float)q[i]/p[i]);
		else
			t2 = min(t2, (float)q[i]/p[i]);
	}
	
	// IN RA MAN HINH t1 VA t2
	printf("\nt1 = %.2f \tt2 = %.2f", t1, t2);
	
	// THE T11 T2 VAP PT1 PT2
	x0 = xa + t1*dx;
	y0 = ya + t1*dy;
	x1 = xa + t2*dx;
	y1 = ya + t2*dy;
	
	// IN RA MH GIA TRI X0, Y0, X1, Y1
	printf("\nx0 = %d, y0 = %d, x1 = %d, y1 = %d", x0, y0, x1, y1);
	
	// KIEM TRA GIAO DIEM CO THUOC CUA SO KHONG?
	if(x0 < xwmin || x0 > xwmax || y0 < ywmin || y0 > ywmax ||
	   x1 < xwmin || x1 > xwmax || y1 < ywmin || y1 > ywmax )
	{
		
	}else{
		// VE DT NOI 2 GIAO DIEM
		delay(500);
		setcolor(2);
		line(x0, y0, x1, y1);
	}	
}

int main(){
	initwindow(500, 500);
	khoiTao();
	
///////////////////A TRONG, B NGOAI///////////////////////
	
	// AB NAM BEN TRONG
	Liang_Barsky(150, 280, 260, 150);
	
	// A TRONG, B PHAI
	Liang_Barsky(150, 280, 360, 150);
	
	// A TRONG, B TREN
	Liang_Barsky(150, 160, 150, 450);
	
	// A TRONG, B TRAI
	Liang_Barsky(200, 160, 20, 160);
	
	// A TRONG, B DUOI
	Liang_Barsky(150, 160, 150, 20);
	
///////////////////A NGOAI, B TRONG///////////////////////
	
	// B TRONG, A PHAI
	Liang_Barsky(360, 160, 160, 280);
	
	// B TRONG, A TREN
	Liang_Barsky(160, 450, 160, 140);
	
	// B TRONG, A TRAI
	Liang_Barsky(20, 160, 200, 160);
	
	// B TRONG, A DUOI
	Liang_Barsky(160, 20, 160, 200);
	
///////////////////A NGOAI, B NGOAI///////////////////////
	
	// A TRAI, B PHAI
	Liang_Barsky(50, 200, 350, 200);
	
	// A TREN, B DUOI
	Liang_Barsky(200, 50, 200, 350);
	
	// A TRAI, B TREN
	Liang_Barsky(50, 200, 200, 350);
	
	// A TRAI, B DUOI
	Liang_Barsky(50, 200, 350, 50);
	
	// A PHAI, B TREN
	Liang_Barsky(350, 200, 150, 350);
	
	// A PHAI, B DUOI
	Liang_Barsky(350, 200, 150, 350);
	
///////////////////A TREN, B TRONG///////////////////////

	// B TRONG, A TREN TRAI
	Liang_Barsky(50, 10, 150, 140);
	Liang_Barsky(10, 50, 150, 140);
	
///////////////////A DUOI, B TRONG///////////////////////

	// B TRONG, A DUOI TRAI
	Liang_Barsky(90, 450, 150, 140);
	Liang_Barsky(10, 450, 150, 140);
	
	// B TRONG, A DUOI PHAI
	Liang_Barsky(450, 30, 200, 170);
	Liang_Barsky(330, 10, 200, 170);
	
		
	// B TRONG, A DUOI PHAI
	Liang_Barsky(450, 430, 200, 170);
	Liang_Barsky(330, 410, 200, 170);
	
///////////////////A TRAI, B TREN (NGOAI CUA SO)///////////////////////
	Liang_Barsky(30, 200, 140, 450);
	
	getch();
}

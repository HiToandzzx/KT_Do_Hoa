#include <graphics.h>
#include <stdio.h>
#include <math.h>
#define maxdinh 20
#define INPUT "daGiac.txt"

int dinh[maxdinh][2]; //Toa do cac dinh cua da giac
int n; //So dinh cua da giac
FILE *fp;

void readFile(){
	fp = fopen (INPUT, "r");
	if(fp == NULL)
		printf("File not found");
	else{
		fscanf(fp, "%d", &n);
		printf("So dinh cua da giac: %d", n);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				fscanf(fp, "%d", &dinh[i][j]);
			}
		}
	}
	
	printf("\nToa do cac dinh cua da giac: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			printf("%5d", dinh[i][j]);
		}
	printf("\n");
	}	
}

void draw(){
	dinh[n][0] = dinh[0][0];
	dinh[n][1] = dinh[0][1];
	
	for(int i=0; i<n; i++){
//		setcolor(i+1);
		line(dinh[i][0], dinh[i][1], dinh[i+1][0], dinh[i+1][1]);
	}
}

void tinhTien(int dx, int dy){
	for(int i=0; i<n; i++){
		dinh[i][0] += dx; //x' = x + dx
		dinh[i][1] += dy;
	}
	draw();
}

void quay(int xr, int yr, int phi){
	//x' - xr + (x - xr)*cos - (y - yr)*sin
	//y' - yr + (x - xr)*sin - (y - yr)*cos
	for(int i=0; i<n; i++){
		int dx = dinh[i][0] - xr;
		int dy = dinh[i][1] - yr;
		dinh[i][0] = round(xr + dx*cos(phi*3.1416/180) - dy*sin(phi*3.1416/180));
		dinh[i][1] = round(yr + dx*sin(phi*3.1416/180) + dy*cos(phi*3.1416/180));
	}
	draw();
}

void tyLe(int xr, int yr, float sx, float sy){
	//x' = xr + (x - xr)*sx
	//y' = yr + (y - yr)*sy
	for(int i=0; i<n; i++){
		dinh[i][0] = round(xr + (float)((dinh[i][0] - xr) * sx));
		dinh[i][1] = round(yr + (float)((dinh[i][1] - yr) * sy));
	}
	draw();
}

void doiXung(){
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2); //Duong ngang
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy()); //Duong doc
	
	//DX qua truc y
	for(int i=0; i<n; i++){
		dinh[i][0] += getmaxx()/2;
	}
	draw();
	
	//DX qua truc x
	for(int i=0; i<n; i++){
		dinh[i][1] += getmaxy()/2;
	}
	draw();
	
	//DX qua truc y
	for(int i=0; i<n; i++){
		dinh[i][0] -= getmaxx()/2;
	}
	draw();
}

int main(){
	readFile();
	initwindow(800, 800);
	draw();

//TINH TIEN
//	
//	for(int i=0; i<n; i++){
//		tinhTien(5, 0);
//		delay(200);
//	}

//QUAY
//	for(int i=0; i<360/1; i++){
//		quay(400, 300, 1);
//		delay(10);
//	}

//TYLE
//	for(int i=0; i<20; i++){
//		tyLe(300, 300, 0.9, 0.9);
//		delay(10);
//	}
	
//DOI XUNG
	doiXung();
	
	getch();
}

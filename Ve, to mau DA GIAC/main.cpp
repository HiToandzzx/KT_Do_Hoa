#include<winbgim.h>
#include<stdio.h>
#include<math.h>
#define INPUT "dagiac.txt" 
#define maxdinh 20 //So dinh toi da cua da giac

//Toa do cac dinh da giac
int dinh[maxdinh][maxdinh];
//so dinh thuc te cua da giac
int n; 
//he so goc cac canh cua da giac
float m[maxdinh]; 
FILE *fp; 

//BUOC1: Doc du lieu tu file
void readFile(){
	fp=fopen(INPUT, "r");
	if(fp == NULL)
		printf("File not found!");
	else{
		//Doc so dinh tu tap tin va luu vao bien n
		fscanf(fp, "%d", &n);
		printf("\nSo dinh cua da giac: %d", n);
		//Doc lan luot toa do cac dinh tu tap tin -> dinh[][]
		//Duyet qua cac dinh
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){//0:xi, 1:yi
				fscanf(fp, "%d", &dinh[i][j]);
			}
		}
		//In ra cac dinh cua da giac
		printf("\nToa do cac dinh cua da giac: \n");
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				//in ra cac dinh tren 1 hang
				printf("%5d", dinh[i][j]);
			}
			printf("\n");
		}
		fclose(fp);
	}	
	//Them 1 dinh cua da giac [n] = dinh [0]
	dinh[n][0] = dinh[0][0];
	dinh[n][1] = dinh[0][1];
}

//BUOC2: Ve cac canh cua da giac
void draw(){
	for(int i=0; i<n; i++){
		line(dinh[i][0], dinh[i][1], dinh[i+1][0], dinh[i+1][1]);
		delay(1000);
	}	
}

//BUOC 3: Tinh he so goc cac canh cua da giac
void heSoGoc(){
	for(int i=0; i<n; i++){
		int dy = (dinh[i+1][1] - dinh[i][1]);
		int dx = (dinh[i+1][0] - dinh[i][0]);
		if(dx == 0)
			m[i] = 999999; //vo cung
		if(dy == 0)
			m[i]=1.0;
			//thay m=0 thanh m # 0 , vi du m=1;
		else
			m[i] = (float)(dy)/(dx); //m=dy/dx
	}
	printf("\nHe so goc: ");
	for(int i=0; i<n; i++){
		printf("%.1f ", m[i]);
	}
}

//BUOC4: Tim giao diem
void scanLine(){
	//So giao diem toi da = so dinh
	int xgd[maxdinh]; 
	//Tim ymin va ymax
	int ymin = dinh[0][1]; //y0
	int ymax = dinh[0][1]; //y0
	//duyet tu dinh thu 1 tro di -> het
	for(int i=1; i<n; i++){
		//Tim ymin
		if(ymin > dinh[i][1])
			ymin = dinh[i][1];
		//Tim ymax
		if(ymax < dinh[i][1])
			ymax = dinh[i][1];
	}
	printf("\nymin = %d, ymax = %d", ymin, ymax);
	
	//Tim giao diem giua scanline voi lan luot cac canh cua da giac
	int y = ymin;
	while(y <= ymax){
		//Voi moi dong quet
		int dem = 0; //reset bien dem sau moi lan tang dong quet
		//Duyet qua cac canh cua da giac
		for(int i=0; i<n; i++){
			//KT dieu kien co giao diem
			if((y <= dinh[i][1] && y > dinh[i+1][1]) || (y > dinh[i][1] && y <= dinh[i+1][1])){
				xgd[dem++] = round(dinh[i][0] + (y - dinh[i][1])/m[i]); // x = xtruoc + (y - ytruoc)/m
			}
		}
		//In ra giao diem cua y voi cac canh cua da giac
		for(int i=0; i<n; i++){
			printf("\nGio diem y = %d voi canh (%d, %d) la (%d, %d)", y, dinh[i][0], dinh[i][1], xgd[i], y);
			
		}
		
		//Sap ep tang dan theo hoanh do giao diem
		for(int i=0; i<dem-1; i++){
			for(int j=i+1; j<dem; j++){
				if(xgd[i] > xgd[j]){
				int tam = xgd[i];
				xgd[i] = xgd[j];
				xgd[j] = tam;
				}
			}
		}
		//Ve duong thang noi cac dinh cua da giac
		setcolor(2);
		for(int i=0; i<dem-1; i+=2){
			line(xgd[i], y, xgd[i+1], y);
		}
		//Tang dong quet len 1 pixel
		y++; 
		delay(10);
	}
	
}
int main()
{
	readFile();
	initwindow(500,500);
	draw();
	heSoGoc();
	scanLine();
	getch();
}

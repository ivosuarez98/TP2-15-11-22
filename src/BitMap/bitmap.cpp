/*
 * bitmap.cpp
 *
 *  Created on: 16 nov. 2022
 *      Author: luis
 */
#include "bitmap.h"
using namespace std;

void createBMP(int x, int y, int size){
 	BMP Sample;
 	Sample.SetSize(x*size,y*size);
 	Sample.SetBitDepth(8);
 	Sample.WriteToFile("JuegoDeLaVida.bmp");
}

void setBigPixel(int x, int y, int size,int r, int g ,int b){
	BMP Sample;
 	Sample.ReadFromFile("test2.bmp");
 	for(int i=0;i<size;i++){
 		for(int j=0;j<size;j++){
 			Sample((x*size)+i,(y*size)+j)->Red=r;
 			Sample((x*size)+i,(y*size)+j)->Green=g;
 			Sample((x*size)+i,(y*size)+j)->Blue=b;
 			Sample(x,y)->Alpha=0;
 		}
 	}
 	Sample.WriteToFile("test2.bmp");
}





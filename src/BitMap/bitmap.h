/*
 * bitmap.h
 *
 *  Created on: 16 nov. 2022
 *      Author: luis
 */

#ifndef SRC_BITMAP_BITMAP_H_
#define SRC_BITMAP_BITMAP_H_

#include <iostream>
#include <string>
using namespace std;
#include "EasyBMP.h"

void createBMP(int x, int y, int size);

void setBigPixel(int x, int y, int size,int r, int g ,int b);



#endif /* SRC_BITMAP_BITMAP_H_ */

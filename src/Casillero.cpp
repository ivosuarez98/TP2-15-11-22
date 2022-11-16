/*
 * Casillero.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Casillero.h"

Casillero::Casillero(unsigned int i, unsigned int j, unsigned int k) {
	this->posicion.x=i;
	this->posicion.y=j;
	this->posicion.z=k;
	this->celula=new Celula();
}

unsigned int Casillero::getPosicionX(){
	return (this->posicion.x);
}

unsigned int Casillero::getPosicionY(){
	return (this->posicion.y);
}

unsigned int Casillero::getPosicionZ(){
	return (this->posicion.z);
}

Celula* Casillero::getCelula(){
	return this->celula;
}

Casillero::~Casillero() {
	// TODO Auto-generated destructor stub
}


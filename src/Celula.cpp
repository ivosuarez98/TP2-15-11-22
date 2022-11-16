/*
 * Celula.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Celula.h"

Celula::Celula() {
	this->gen.genAlfa=0;
	this->gen.genBeta=0;
	this->gen.genGamma=0;
	this->estado=muerto;
}

void Celula::setCelulaViva(){
	unsigned int genAleatorio=rand();
	this->gen.genAlfa=(genAleatorio % 256);
	this->gen.genBeta=(genAleatorio % 256);
	this->gen.genGamma=(genAleatorio % 256);
	this->estado=vivo;
}

void Celula::setCelulaMuerta(){
	this->gen.genAlfa=0;
	this->gen.genBeta=0;
	this->gen.genGamma=0;
	this->estado=muerto;
}

void Celula::setCelulaVecina(Celula* vecina, int i){
	this->vecinos[i]=vecina;
}

Estado Celula::mostrarCelulasVecinas(int i){
	Celula* vecino=this->vecinos[i];
	return vecino->getEstado();
}

Estado Celula::getEstado(){
	return this->estado;
}

Gen Celula::getGenes(){
	return this->gen;
}

Celula::~Celula() {
	// TODO Auto-generated destructor stub
}


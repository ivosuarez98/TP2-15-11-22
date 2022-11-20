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

void Celula::setEstado(Estado estado){
	this->estado=estado;
}

void Celula::setGen(){
	unsigned int genAleatorio1=rand();
	this->gen.genAlfa=(genAleatorio1 % 256);
}

void Celula::setCelulaViva(){
	unsigned int genAleatorio1=rand();
	unsigned int genAleatorio2=rand();
	unsigned int genAleatorio3=rand();
	this->gen.genAlfa=(genAleatorio1 % 256);
	this->gen.genBeta=(genAleatorio2 % 256);
	this->gen.genGamma=(genAleatorio3 % 256);
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

Celula* Celula::getVecina(int i){
	Celula* vecina=vecinos[i];
	return vecina;
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


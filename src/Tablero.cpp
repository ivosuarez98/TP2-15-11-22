/*
 * Tablero.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int x, unsigned int y, unsigned int z) {
	this->tablero=new Lista<Lista<Lista<Casillero*>*>*>();
	for (unsigned int i=1; i<=x; i++){
		Lista<Lista<Casillero*>*>* columna=new Lista<Lista<Casillero*>*>();
		for (unsigned int j=1; j<=y; j++){
			Lista<Casillero*>* fila=new Lista<Casillero*>();
			for (unsigned int k=1; k<=z; k++){
				Casillero* plano=new Casillero(i,j,k);
				fila->add(plano);
			}
			columna->add(fila);
		}
		this->tablero->add(columna);
	}
}

void Tablero::setCasillero(int x, int y, int z){
	this->tablero->get(x)->get(y)->get(z)->getCelula()->setCelulaViva();
}

void Tablero::iniciarTablero(){
	this->tablero->reiniciarCursor();
	this->tablero->avanzarCursor();
	for (unsigned int i=1; i<=this->tablero->contarElementos(); i++){
		this->tablero->getCursor()->reiniciarCursor();
		this->tablero->getCursor()->avanzarCursor();
		for(unsigned int j=1; j<=this->tablero->getCursor()->contarElementos(); j++){
			this->tablero->getCursor()->getCursor()->reiniciarCursor();
			this->tablero->getCursor()->getCursor()->avanzarCursor();
			this->tablero->getCursor()->avanzarCursor();
		}
		this->tablero->avanzarCursor();
	}
}

void Tablero::avanzarPlano(){
	for(unsigned int i=1; i<=this->tablero->contarElementos(); i++){
		for(unsigned int j=1; j<=this->tablero->getCursor()->contarElementos(); j++){
			this->tablero->getCursor()->getCursor()->avanzarCursor();
			this->tablero->getCursor()->avanzarCursor();
		}
		this->tablero->avanzarCursor();
	}
}

Casillero * Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z){
	return this->tablero->get(x)->get(y)->get(z);
}

unsigned int Tablero::getColumnas(){
	return this->tablero->contarElementos();
}

unsigned int Tablero::getFilas(){
	iniciarTablero();
	return this->tablero->getCursor()->contarElementos();
}

unsigned int Tablero::getPlanos(){
	iniciarTablero();
	return this->tablero->getCursor()->getCursor()->contarElementos();
}

void Tablero::mostrarTablero(){
	iniciarTablero();
	for(unsigned int k=1; k<=this->tablero->getCursor()->getCursor()->contarElementos(); k++){
		for(unsigned int i=1; i<=this->tablero->getCursor()->contarElementos(); i++){
			for(unsigned int j=1; j<=this->tablero->contarElementos(); j++){
				if(this->tablero->getCursor()->getCursor()->getCursor()->getCelula()->getEstado()==vivo){
					std::cout<<"[0]";
				}else{
					std::cout<<"[ ]";
				}
				this->tablero->getCursor()->avanzarCursor();
				this->tablero->avanzarCursor();
			}
			std::cout<<std::endl;
		}
		avanzarPlano();
		std::cout<<"\n"<<std::endl;
	}
}

bool Tablero::compararPosiciones(unsigned int x, unsigned int y, unsigned int z){
	if (this->tablero->getCursor()->getCursor()->getCursor()->getPosicionX()==x){
		if (this->tablero->getCursor()->getCursor()->getCursor()->getPosicionY()==y){
			if (this->tablero->getCursor()->getCursor()->getCursor()->getPosicionZ()==z){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void Tablero::analizarPlanos(Celula* aux, int &i, unsigned int x, unsigned int y, unsigned int z){
	for(int j=0; j<3; j++){
		if (j==0){
			this->tablero->getCursor()->getCursor()->retrocederCursor();
		}else{
			this->tablero->getCursor()->getCursor()->avanzarCursor();
		}
		if (!compararPosiciones(x, y, z)){
			aux->setCelulaVecina(this->tablero->getCursor()->getCursor()->getCursor()->getCelula(), i);
			i++;
		}
	}
}

void Tablero::analizarFilas(Celula* aux, int &i, unsigned int x, unsigned int y, unsigned int z){
	for (int j=0; j<3; j++){
		if (j==0){
			this->tablero->getCursor()->retrocederCursor();
		}else{
			this->tablero->getCursor()->avanzarCursor();
		}
		this->analizarPlanos(aux, i, x, y, z);
		this->tablero->getCursor()->getCursor()->retrocederCursor();
	}
}

void Tablero::analizarColumnas(Celula* aux, unsigned int x, unsigned int y, unsigned int z){
	int k=0;
	while (k<26){
		if (k==0){
			this->tablero->retrocederCursor();
		}else{
			this->tablero->avanzarCursor();
		}
		analizarFilas(aux, k, x, y, z);
	}
	this->tablero->retrocederCursor();
}

void Tablero::cargarVecinos(){
	iniciarTablero();
	for(unsigned int k=1; k<=this->tablero->getCursor()->getCursor()->contarElementos(); k++){
		for(unsigned int i=1; i<=this->tablero->contarElementos(); i++){
			for(unsigned int j=1; j<=this->tablero->getCursor()->contarElementos(); j++){
				Celula* aux=this->tablero->getCursor()->getCursor()->getCursor()->getCelula();
				analizarColumnas(aux, i, j, k);
			}
			this->tablero->avanzarCursor();
		}
		avanzarPlano();
	}
}
/*
void Tablero::actualizarTablero(int valor){

}*/

Tablero::~Tablero() {
}


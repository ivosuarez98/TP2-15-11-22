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
	this->cargarVecinos();
}

Tablero::Tablero(Tablero* &otroTablero){
	this->tablero=new Lista<Lista<Lista<Casillero*>*>*>();
	otroTablero->iniciarTablero();
	for (unsigned int i=1; i<=otroTablero->getColumnas(); i++){
		Lista<Lista<Casillero*>*>* columna=new Lista<Lista<Casillero*>*>();
		for (unsigned int j=1; j<=otroTablero->getFilas(); j++){
			Lista<Casillero*>* fila=new Lista<Casillero*>();
			for (unsigned int k=1; k<=otroTablero->getPlanos(); k++){
				fila->add(otroTablero->getCasillero(i,j,k));
			}
			columna->add(fila);
		}
		this->tablero->add(columna);
	}
	this->cargarVecinos();
}

void Tablero::setCasillero(int x, int y, int z){
	this->tablero->get(x)->get(y)->get(z)->getCelula()->setCelulaViva();
}

void Tablero::setCasillero(int x, int y, int z, Estado estado){
	this->tablero->get(x)->get(y)->get(z)->getCelula()->setEstado(estado);
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
/*
void Tablero::avanzarCasillero(){
	this->tablero->getCursor()->getCursor()->avanzarCursor();
	int posicionY=this->tablero->getCursor()->getCursor()->getCursor()->getPosicionY();
	int posicionZ=this->tablero->getCursor()->getCursor()->getCursor()->getPosicionZ();
	if(posicionZ+1>this->tablero->getCursor()->getCursor()->contarElementos()){
		this->tablero->getCursor()->avanzarCursor();
		if(posicionY+1>this->tablero->getCursor()->contarElementos()){
			this->tablero->avanzarCursor();
		}
	}
}*/

Casillero * Tablero::getCasillero(){
	return this->tablero->getCursor()->getCursor()->getCursor();
}

Casillero * Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z){
	return this->tablero->get(x)->get(y)->get(z);
}

unsigned int Tablero::getColumnas(){
	return this->tablero->contarElementos();
}

unsigned int Tablero::getFilas(){
	this->iniciarTablero();
	return this->tablero->getCursor()->contarElementos();
}

unsigned int Tablero::getPlanos(){
	this->iniciarTablero();
	return this->tablero->getCursor()->getCursor()->contarElementos();
}

void Tablero::crearBitMapTablero(int tamanioPixel){
    int X=this->getColumnas();
    int Y=this->getFilas();
    int Z=this->getPlanos();
    int chop=1;
    int acumulado=0;
    createBMP(((Z*X)+(Z-1)*chop),Y, tamanioPixel);
    for(int z=0;z<Z;z++){
        this->imprimirPlano(tamanioPixel, z, acumulado);
        acumulado+=X+chop;
    }
}
void Tablero::imprimirPlano(int tamanioPixel,int z,int chop){

    int X=this->getColumnas();
    int Y=this->getFilas();

    for(int x=0;x<X;x++){
        for(int y=0;y<Y;y++){
            setBigPixel( x+chop,  y,  tamanioPixel , this->getCasillero(x+1, y+1, z+1)->getCelula()->getGenes().genAlfa, this->getCasillero(x+1, y+1, z+1)->getCelula()->getGenes().genBeta, this->getCasillero(x+1, y+1, z+1)->getCelula()->getGenes().genGamma);
        }
    }
    cout<<"imprimi plano"<<z+1<<endl;
}

void Tablero::mostrarTableroPorTerminal(){
	this->iniciarTablero();
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
		this->avanzarPlano();
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

void Tablero::cargarVecinos(){
	this->iniciarTablero();
	for(unsigned int k=1; k<=this->tablero->getCursor()->getCursor()->contarElementos(); k++){
		for(unsigned int i=1; i<=this->tablero->contarElementos(); i++){
			for(unsigned int j=1; j<=this->tablero->getCursor()->contarElementos(); j++){
				Celula* aux=this->tablero->getCursor()->getCursor()->getCursor()->getCelula();
				this->analizarColumnas(aux, i, j, k);
			}
			this->tablero->avanzarCursor();
		}
		this->avanzarPlano();
	}
}

void Tablero::cargarDatosVector(vector<string> &datos){
	for(int i=0; i<datos.size(); i+=6){
		//this->setCasillero(stoi(datos[i]), stoi(datos[i+1]), stoi(datos[i+2]), vivo);
		this->getCasillero(stoi(datos[i]), stoi(datos[i+1]), stoi(datos[i+2]))->getCelula()->setCelulaViva();
	}
}

Tablero::~Tablero() {
	this->iniciarTablero();
	for(unsigned int i=1; i<=this->tablero->contarElementos(); i++){
		for(unsigned int j=1; j<=this->tablero->getCursor()->contarElementos(); j++){
			for(unsigned int k=1; k<=this->tablero->getCursor()->getCursor()->contarElementos(); k++){
				this->tablero->getCursor()->getCursor()->getCursor()->~Casillero();
			}
			this->tablero->getCursor()->getCursor()->~Lista();
		}
		this->tablero->getCursor()->~Lista();
	}
	this->tablero->~Lista();
	delete this->tablero;
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

void Tablero::analizarPlanos(Celula* aux, int &i, unsigned int x, unsigned int y, unsigned int z){
	for(int j=0; j<3; j++){
		if (j==0){
			this->tablero->getCursor()->getCursor()->retrocederCursor();
		}else{
			this->tablero->getCursor()->getCursor()->avanzarCursor();
		}
		if (!this->compararPosiciones(x, y, z)){
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
		this->analizarFilas(aux, k, x, y, z);
	}
	this->tablero->retrocederCursor();
}

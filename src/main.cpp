/*
 * main.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */
#include <iostream>
#include "Tablero.h"
int main(){
	Tablero * tablero=new Tablero(10, 10, 3);
	tablero->setCasillero(5, 4, 2);
	tablero->setCasillero(2, 1, 1);
	tablero->setCasillero(2, 2, 1);
	tablero->setCasillero(2, 1, 2);
	tablero->setCasillero(3, 2, 2);
	//tablero->setCasillero(2, 3, 2);
	//tablero->setCasillero(5, 1);
	//tablero->setCasillero(5, 10);
	tablero->mostrarTablero();
	tablero->cargarVecinos();
	int j=2;
	Celula* aux=tablero->getCasillero(j, j, j)->getCelula();
	std::cout<<"Celulas vecinas vivas en la posicion ("<<j<<","<<j<<","<<j<<")."<<std::endl;
	for (int i=0; i<26; i++){
		if (aux->mostrarCelulasVecinas(i)==vivo){
			std::cout<<"vivo-";
		}else{
			std::cout<<"muerto-";
		}
	}
	std::cout<<std::endl;
	tablero->setCasillero(3, 1, 2);
	tablero->setCasillero(3, 3, 3);
	tablero->mostrarTablero();
	std::cout<<"Celulas vecinas vivas en la posicion ("<< j <<","<< j <<")."<<std::endl;
	for (int i=0; i<26; i++){
		if (aux->mostrarCelulasVecinas(i)==vivo){
			std::cout<<"vivo-";
		}else{
			std::cout<<"muerto-";
		}
	}
	//tablero->actualizarTablero(1);
	//tablero->mostrarTablero();
	return 0;
}



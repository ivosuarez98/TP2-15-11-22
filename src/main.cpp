/*
 * main.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */
#include <iostream>
#include "Tablero.h"
#include "Juego.h"
#include "ReadData.h"

int main(){
	//Juego* juego=new Juego();
	std::string Datos1= "src/DataMap.txt";

		 // prints !!!Hello World!!!
		vector<string> datos;
		vector<string> config;
		tomarDatosDeArchivoTXT(Datos1,datos, config);
		Juego* juego=new Juego(stoi(config[0]),stoi(config[1]), stoi(config[2]));
		/*
		for(int i=0;i<=config.size();i++){
			std::cout<<config[i]<<std::endl;
		}*/
		juego->cargarDatosDeEntrada(datos);
		juego->ImprimirDatosDeEntrada();
		std::cout<<"test"<<std::endl;

		/*for(int i=0;i<=datos.size();i++){
			std::cout<<datos[i]<<std::endl;
		}*/
		juego->iniciarjuego();
		juego->jugarJuego();

/*
	Tablero * tablero=new Tablero(stoi(config[0]), stoi(config[1]), stoi(config[2]));
	tablero->cargarVecinos();
	tablero->cargarDatosVector(datos);
	tablero->mostrarTablero();
	tablero->crearBitMapTablero(5);
	cout<<"paso";*/

	/*int j=2;
	Celula* aux=tablero->getCasillero(j, j, j)->getCelula();
	std::cout<<"Celulas vecinas vivas en la posicion ("<<j<<","<<j<<","<<j<<")."<<std::endl;
	for (int i=0; i<26; i++){
		if (aux->mostrarCelulasVecinas(i)==vivo){
			std::cout<<"vivo-";
		}else{
			std::cout<<"muerto-";
		}
	}
	std::cout<<std::endl;*/
	return 0;
}


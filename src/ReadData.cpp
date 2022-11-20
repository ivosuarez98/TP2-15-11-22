//============================================================================
// Name        : ReadData.cpp
// Author      : ivo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ReadData.h"
#include	<fstream>
#include	<iostream>
#include	<cstdlib>
using namespace std;


void tomarDatosDeArchivoTXT(std::string rutaDatos,vector<string> &datos, vector<string> &config){


	size_t pos=0;
	std::string separador=";";
	std::ifstream entrada;
	entrada.open(rutaDatos.c_str());
	std::string line;
	std::string dato;


	std::getline(entrada,line);

	//DEFINICONES
	while((pos=line.find(separador)) != std::string::npos){
		dato =line.substr(0,pos);
		config.push_back(dato);
		line.erase(0,pos+1);
	}

	//DATOS
	while(!entrada.eof()){
		std::getline(entrada,line);
		while((pos=line.find(separador)) != std::string::npos){
			dato =line.substr(0,pos);
			datos.push_back(dato);
			line.erase(0,pos+1);
		}
	}

	entrada.close();
}





/*
int main() {
	std::string Datos1= "src/DataMap.txt";

	 // prints !!!Hello World!!!
	vector<string> datos;
	vector<string> config;
	tomarDatosDeArchivoTXT(Datos1,datos,config);

	for(int i=0;i<=config.size();i++){
		std::cout<<config[i]<<std::endl;
	}

	std::cout<<"test"<<std::endl;

	for(int i=0;i<=datos.size();i++){
		std::cout<<datos[i]<<std::endl;
	}

	return 0;
}*/


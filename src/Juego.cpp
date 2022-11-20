/*
 * Juego.cpp
 *
 *  Created on: 19 nov. 2022
 *      Author: luis
 */

#include "Juego.h"
#include <iostream>
using namespace std;

Juego::Juego(int x, int y, int z){
        // CONFIGURACON PREDETERMINADA - INICIO RÁPIDO,         etc. etc.
	this->tablero = new Tablero(x, y, z);
	this->resetearEstadisticasDelJuego();
}

Juego::Juego(){

}

Juego::Juego(int turnos, char* configuracion){
        // FUNCIÓN QUE LEE ARCHIVO .TXT         etc. etc.
}


void Juego::mostrarTablero(){

    this->tablero->crearBitMapTablero(this->TAMANIODELPIXEL);
	// USANDO EL BITMAP,            etc. etc.
}

void Juego::incrementarTurno(){
	this->estadisticas.turno++;
}

unsigned int Juego::getTurno(){
	return this->estadisticas.turno;
}


unsigned int Juego::getNacimientosPromedio(){
	int nacimientosPromedio;
	nacimientosPromedio=this->estadisticas.nacimientosTotales/this->estadisticas.turno;
	return nacimientosPromedio;
}


unsigned int Juego::getMuertesPromedio(){
	int muertesPromedio;
	muertesPromedio=this->estadisticas.muertesTotales/this->estadisticas.turno;
	return muertesPromedio;
}


unsigned int Juego::getNacidasEnTurno(){
	return this->estadisticas.nacidasEnTurno;
}


unsigned int Juego::getMuertasEnTurno(){
	return this->estadisticas.muertasEnTurno;
}

Tablero* Juego::getTablero(){
	return this->tablero;
}


void Juego::jugarJuego(){
	char key;
	key=pedirAccion();
	while (key!=TERMINAR){
		ejecutar(key);
		key=pedirAccion();
	}
	terminarJuego();

}

char Juego::pedirAccion(){
	char accion;
	cin>>accion;
	return accion;
}

void Juego::ejecutar(char key){
	//validar key
	if(key==SIGUIENTE){
		this->ejecutarTurno();
	}
	if(key==REINICIAR){
		this->jugarJuego();
	}

}

void Juego::ejecutarTurno(){
	this->implementarReglasSobreTablero();
	this->mostrarTablero();
	this->mostrarEstadisticas();
	this->avanzarTurno();
}

void Juego::implementarReglasSobreTablero(){
	Tablero* tableroCopia=new Tablero(this->tablero);
	this->tablero->iniciarTablero();
	tableroCopia->iniciarTablero();
	for(unsigned int i=1; i<=this->tablero->getColumnas(); i++){
		for(unsigned int j=1; j<=this->tablero->getFilas(); j++){
			for(unsigned int k=1; k<=this->tablero->getPlanos(); k++){
				this->implementarReglasSobreCasillero(tableroCopia->getCasillero(i, j, k));//repensar getCasillero
			}

		}
	}

	delete tableroCopia;
}

void Juego::implementarReglasSobreCasillero(Casillero* casillero){
	int vecinosVivos=0;
	for(unsigned int i=0; i<casillero->getCelula()->cantidadDeVecinos; i++){
		if(casillero->getCelula()->getVecina(i)->getEstado()==vivo){
			vecinosVivos++;
		}
	}
	if(casillero->getCelula()->getEstado()==vivo){
		if(vecinosVivos<this->estadisticas.valorDeReproduccion*2 || vecinosVivos>this->estadisticas.valorDeReproduccion*3){
			this->tablero->getCasillero(casillero->getPosicionX(),
										casillero->getPosicionY(),
										casillero->getPosicionZ())->getCelula()->setEstado(muerto);//chequear que funque
			this->estadisticas.muertasEnTurno++;
		}
	}else{
		if(vecinosVivos>=this->estadisticas.valorDeReproduccion*2 && vecinosVivos<=this->estadisticas.valorDeReproduccion*3){
			this->tablero->getCasillero(casillero->getPosicionX(),
										casillero->getPosicionY(),
										casillero->getPosicionZ())->getCelula()->setEstado(vivo);
			this->estadisticas.nacidasEnTurno++;
			//cargarGenes
		}
	}
	//comprobarPropiedadCasillero
}

void Juego::avanzarTurno(){
	this->estadisticas.turno++;
}

void Juego::terminarJuego(){
	mostrarFinDeljuego();
	mostrarEstadisticas();

}

void Juego::iniciarjuego(){
	this->resetearEstadisticasDelJuego();
	this->cargarDatosEntablero();
}

void Juego::resetearEstadisticasDelJuego(){
	this->estadisticas.estado=INICIADO;
	this->estadisticas.turno = 0;
	this->estadisticas.nacimientosTotales = 0;
	this->estadisticas.muertesTotales = 0;
	this->estadisticas.nacidasEnTurno = 0;
	this->estadisticas.muertasEnTurno = 0;
}
void Juego::cargarDatosEntablero(){
	for(int i=0; i<this->datosDeIngreso.size(); i+=6){
		this->tablero->getCasillero(stoi(this->datosDeIngreso[i]),
									stoi(this->datosDeIngreso[i+1]),
									stoi(this->datosDeIngreso[i+2]))->getCelula()->setCelulaViva();
	}
}


void Juego::mostrarFinDeljuego(){
	cout<<"Gracias por jugar."<<endl;
}

void Juego::mostrarEstadisticas(){
	cout<<"Estado: "<<this->estadisticas.estado<<endl;
}

void Juego::cargarDatosDeEntrada(vector<string> &datos){
	this->datosDeIngreso=datos;
}

void Juego::ImprimirDatosDeEntrada(){
		for(int i=0; i<this->datosDeIngreso.size(); i+=6){
		cout<<stoi(this->datosDeIngreso[i]) <<"\t";
		cout<<stoi(this->datosDeIngreso[i+1])<<"\t";
		cout<<stoi(this->datosDeIngreso[i+2])<<endl;
	}
}
/*
Juego::~Juego(){
}*/

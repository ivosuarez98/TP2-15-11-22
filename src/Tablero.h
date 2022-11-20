/*
 * Tablero.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"
#include "BitMap/bitmap.h"
#include <string>
#include <vector>
using namespace std;

class Tablero {
private:
	Lista<Lista<Lista<Casillero*>*>*>* tablero;
public:
	Tablero(unsigned int x, unsigned int y, unsigned int z);
	Tablero(Tablero *&otroTablero);
	void  setCasillero(int x, int y, int z);
	void  setCasillero(int x, int y, int z, Estado estado);
	void iniciarTablero();
	void avanzarCasillero();
	Casillero * getCasillero();
	Casillero * getCasillero(unsigned int x, unsigned int y, unsigned int z);
	unsigned int getColumnas();
	unsigned int getFilas();
	unsigned int getPlanos();
	void crearBitMapTablero(int tamanioPixel);
	void imprimirPlano(int tamanioPixel,int z,int chop);
	void mostrarTableroPorTerminal();
	bool compararPosiciones(unsigned int x, unsigned int y, unsigned int z);
	void cargarVecinos();
	void cargarDatosVector(vector<string> &datos);
	virtual ~Tablero();
private:
	void avanzarPlano();
	void analizarPlanos(Celula* aux, int &i, unsigned int x, unsigned int y, unsigned int z);
	void analizarFilas(Celula* aux, int &i, unsigned int x, unsigned int y, unsigned int z);
	void analizarColumnas(Celula* aux, unsigned int x, unsigned int y, unsigned int z);

};

#endif /* TABLERO_H_ */

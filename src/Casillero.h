/*
 * Casillero.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Celula.h"

struct Posicion{
	unsigned int x;
	unsigned int y;
	unsigned int z;
};

class Casillero {
private:
	Celula* celula;
	Posicion posicion;
public:
	Casillero(unsigned int i, unsigned int j, unsigned int k);
	unsigned int getPosicionX();
	unsigned int getPosicionY();
	unsigned int getPosicionZ();
	Celula* getCelula();
	void setComportamiento1(); //pendiente
	void setComportamiento2(); //pendiente
	void setComportamiento3(); //pendiente
	void setCasilleroPortal(); //pendiente
	void setCasilleroRadiactivo(); //pendiente
	virtual ~Casillero();
};

#endif /* CASILLERO_H_ */

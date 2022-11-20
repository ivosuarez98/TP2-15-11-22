/*
 * Celula.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef CELULA_H_
#define CELULA_H_

#include <random>

enum Estado{
	vivo,
	muerto
};

struct Gen{
	unsigned int genAlfa;
	unsigned int genBeta;
	unsigned int genGamma;
};

class Celula {
private:
	Gen gen;
	Estado estado;
	Celula* vecinos[26];
public:
	static const int cantidadDeVecinos=26;
	Celula();
	void setEstado(Estado estado);
	void setGen();
	void setCelulaViva();
	void setCelulaMuerta();
	void setCelulaVecina(Celula* vecina, int i);
	Celula* getVecina(int i);
	Estado getEstado();
	Gen getGenes();
	virtual ~Celula();
};

#endif /* CELULA_H_ */

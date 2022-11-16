/*
 * Nodo.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

template<class T> class Nodo{
private:
	Nodo<T>* anterior;
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo(T valor);
	bool hayAnterior();
	bool haySiguiente();
	Nodo<T>* getAnterior();
	Nodo<T>* getSiguiente();
	void setAnterior(Nodo<T>* nuevoAnt);
	void setSiguiente(Nodo<T>* nuevoSig);
	T getValor();
	void setValor(T nuevoValor);
	~Nodo();
};


template<class T> Nodo<T>::Nodo(T valor){
	this->anterior = NULL;
	this->dato = valor;
	this->siguiente = NULL;
}

template<class T> bool Nodo<T>::hayAnterior(){
	return (this->anterior != NULL);
}

template<class T> bool Nodo<T>::haySiguiente(){
	return (this->siguiente != NULL);
}

template<class T> Nodo<T>* Nodo<T>::getAnterior(){
	return (this->anterior);
}

template<class T> Nodo<T>* Nodo<T>::getSiguiente(){
	return (this->siguiente);
}

template<class T> void Nodo<T>::setAnterior(Nodo<T>* nuevoAnt){
	this->anterior = nuevoAnt;
}

template<class T> void Nodo<T>::setSiguiente(Nodo<T>* nuevoSig){
	this->siguiente = nuevoSig;
}

template<class T> T Nodo<T>::getValor(){
	return (this->dato);
}

template<class T> void Nodo<T>::setValor(T nuevoValor){
	this->dato = nuevoValor;
}

template<class T> Nodo<T>::~Nodo(){

}
#endif /* NODO_H_ */

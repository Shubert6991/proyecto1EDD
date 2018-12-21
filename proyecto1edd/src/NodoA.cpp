#include "NodoA.h"

NodoA::NodoA(Anio a){
  anio = a;
  siguiente = NULL;
  anterior = NULL;
  abajo = NULL;
}

NodoA::NodoA(Anio a,NodoA *sig,NodoA *ant,NodoA *abj){
  anio = a
  siguiente = sig;
  anterior = ant;
  abajo = abj;
}

Anio NodoA::getAnio(){
  return anio;
}

NodoA* NodoA::getSiguiente(){
  return siguiente;
}

NodoA* NodoA::getAnterior(){
  return anterior;
}

NodoMes* NodoA::getAbajo(){
  return abajo;
}

void NodoA::setSiguiente(NodoA *sig){
  siguiente = sig;
}

void NodoA::setAnterior(NodoA *ant){
  anterior = ant;
}

void NodoA::setAbajo(NodoMes *abj){
  abajo = abj;
}

int NodoA::getValor(){
  return anio.valor;
}

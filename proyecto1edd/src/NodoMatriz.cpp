#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(TratamientoMatriz t){
  trat = t;
  arriba = abajo = izquierda = derecha = NULL;
}

NodoMatriz::NodoMatriz(TratamientoMatriz t,NodoMatriz *arr,NodoMatriz *abj,NodoMatriz *izq,NodoMatriz *der){
  trat = t;
  arriba = arr;
  abajo = abj;
  izquierda = izq;
  derecha = der;
}

TratamientoMatriz NodoMatriz::getTratamiento(){
  return trat;
}

NodoMatriz* NodoMatriz::getArriba(){
  return arriba;
}

NodoMatriz* NodoMatriz::getAbajo(){
  return abajo;
}

NodoMatriz* NodoMatriz::getIzquierda(){
  return izquierda;
}

NodoMatriz* NodoMatriz::getDerecha(){
  return derecha;
}

void NodoMatriz::setArriba(NodoMatriz *arr){
  arriba = arr;
}

void NodoMatriz::setAbajo(NodoMatriz *abj){
  abajo = abj;
}

void NodoMatriz::setIzquierda(NodoMatriz *izq){
  izquierda = izq;
}

void NodoMatriz::setDerecha(NodoMatriz *der){
  derecha = der;
}

std::string NodoMatriz::getTransaccion(){
  return trat.transaccion;
}

std::string NodoMatriz::getCodTratamiento(){
  return trat.codTrat;
}

std::string NodoMatriz::getCodUsuario(){
  return trat.codUsuario;
}

bool NodoMatriz::getEstado(){
  return trat.estado;
}

int NodoMatriz::getIndexCol(){
  return trat.indexDia;
}

int NodoMatriz::getIndexFila(){
  return trat.indexHora;
}

void NodoMatriz::setIndexCol(int dia){
  trat.indexDia = dia;
}

void NodoMatriz::setIndexFila(int hora){
  trat.indexHora = hora;
}

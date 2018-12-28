#include "NodoHora.h"

NodoHora::NodoHora(Hora h){
  hora = h;
  abajo = arriba = NULL;
  derecha = NULL;
}

NodoHora::NodoHora(Hora h,NodoHora *abj,NodoHora *arr,NodoMatriz *der){
  hora = h;
  abajo = abj;
  arriba = arr;
  derecha = der;
}

Hora NodoHora::getHora(){
  return hora;
}

NodoHora* NodoHora::getAbajo(){
  return abajo;
}

NodoHora* NodoHora::getArriba(){
  return arriba;
}

NodoMatriz* NodoHora::getDerecha(){
  return derecha;
}

void NodoHora::setAbajo(NodoHora *abj){
  abajo = abj;
}

void NodoHora::setArriba(NodoHora *arr){
  arriba = arr;
}

void NodoHora::setDerecha(NodoMatriz *der){
  derecha = der;
}

float NodoHora::getInicio(){
  return hora.inicio;
}

float NodoHora::getFin(){
  return hora.fin;
}

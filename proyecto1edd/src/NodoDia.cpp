#include "NodoDia.h"

NodoDia::NodoDia(Dia d){
  dia = d;
  derecha = izquierda = NULL;
  abajo = NULL;
}

NodoDia::NodoDia(Dia d,NodoDia* der,NodoDia* izq,NodoMatriz* abj){
  dia = d;
  derecha = der;
  izquierda = izq;
  abajo = abj;
}

Dia NodoDia::getDia(){
  return dia;
}

NodoDia* NodoDia::getDerecha(){
  return derecha;
}

NodoDia* NodoDia::getIzquierda(){
  return izquierda;
}

NodoMatriz* NodoDia::getAbajo(){
  return abajo;
}

void NodoDia::setDerecha(NodoDia* der){
  derecha = der;
}

void NodoDia::setIzquierda(NodoDia* izq){
  izquierda = izq;
}

void NodoDia::setAbajo(NodoMatriz* abj){
  abajo = abj;
}

std::string NodoDia::getNombre(){
  return dia.nombre;
}

int NodoDia::getValor(){
  return dia.valor;
}

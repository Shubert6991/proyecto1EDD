#include "NodoSemana.h"

NodoSemana::NodoSemana(Semana s){
  semana = s;
  abajo = NULL;
  derecha = NULL;
}

NodoSemana::NodoSemana(Semana s, NodoSemana* abj, Matriz* der){
  semana = s;
  abajo = abj;
  derecha = der;
}

Semana NodoSemana::getSemana(){
  return semana;
}

NodoSemana* NodoSemana::getAbajo(){
  return abajo;
}

Matriz* NodoSemana::getMatriz(){
  return derecha;
}

void NodoSemana::setAbajo(NodoSemana* abj){
  abajo = abj;
}

void NodoSemana::setMatriz(Matriz* m){
  derecha = m;
}

int NodoSemana::getNumero(){
  return semana.numero;
}

int NodoSemana::getInicio(){
  return semana.inicio;
}

int NodoSemana::getFin(){
  return semana.fin;
}

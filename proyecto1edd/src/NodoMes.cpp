#include "NodoMes.h"

NodoMes::NodoMes(Mes m){
  mes = m;
  abajo = NULL;
}

NodoMes::NodoMes(Mes m,NodoMes* abj){
  mes = m;
  abajo = abj;
}

Mes NodoMes::getMes(){
  return mes;
}

NodoMes* NodoMes::getAbajo(){
  return abajo;
}

void NodoMes::setAbajo(NodoMes *abj){
  abajo = abj;
}

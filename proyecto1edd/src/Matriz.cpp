#include "Matriz.h"

Matriz::Matriz(ListaDias* col,ListaHoras* fil){
  columna = col;
  fila = fil;
}

NodoMatriz* Matriz::buscar(int dia,float hora){
//existeDia y existeHora
if(existeDia(dia) && existeHora(hora)){
  NodoDia* col = columna.buscar(dia);
  NodoHora* f = fila.buscar(hora);
  NodoMatriz* tmp = col -> getAbajo();
  int iCol = columna.getIndex(col);
  int iFil = fila.getIndex(f);
  while(tmp != NULL){
    if(tmp -> getIndexFila() == iFil){
      return tmp;
    }
  }
  return NULL;
} else {
  return NULL;
}
}

void insertar(TratamientoMatriz t,Dia d,Hora h){
  if(existeDia(d.valor)){
    if(existeHora(h.inicio)){
      //insertar
      //obtener indices
      int iCol = columna.getIndex(d.valor);
      int iFil = fila.getIndex(h.inicio);
      //crear nuevo nodo
      NodoMatriz nuevo = new NodoMatriz(t);
      nuevo.setIndexCol(iCol);
      nuevo.setIndexFila(iFil);
      //ordenar por indices
      
    }
    //crear hora
  }
  //crear dia
}

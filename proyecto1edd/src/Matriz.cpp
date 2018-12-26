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
  int i = fila.getIndex(f);
  for (int j = 0; j < i; j++) {
    tmp = tmp -> getAbajo();
  }
  return tmp;
} else return NULL;
}

void insertar(TratamientoMatriz t,Dia d,Hora h){
  if(existeDia(d.valor)){
    if(existeHora(h.inicio)){
      //insertar
      NodoDia* col = columna.buscar(d.valor);
      NodoHora* f = fila.buscar(d.valor);
      NodoMatriz* nuevo = new NodoMatriz(t);
      NodoMatriz* tmp = col -> getAbajo();
      if(tmp == NULL){
        col -> setAbajo(nuevo);
      } else {
        int i= fila.getIndex(f);
        for (int j = 0; j < i-1; j++) {
          tmp = tmp -> getAbajo();
        }
        //columna actual
        tmp2 = tmp -> getAbajo();
        tmp -> setAbajo(nuevo);
        nuevo -> setArriba(tmp);
        //si el de abajo no es vacio
        if(tmp2!=NULL){
          nuevo -> setAbajo(tmp2);
          tmp2 -> setArriba(nuevo);
        }
      }
      //columna anterior
      NodoDia* colAnt = col -> getIzquierda();
      //si existe
      if(colAnt != NULL){
        NodoMatriz* tmpAnt = colAnt -> getAbajo();
        for (int j = 0; j < i; j++) {
          tmpAnt = tmpAnt -> getAbajo();
        }
        tmp2 -> setDerecha(nuevo);
        nuevo -> setIzquierda(tmp2);
      } else {
        f -> setDerecha(nuevo);
      }
      //columna siguiente
      NodoDia* colSig = col -> getDerecha();
      //si existe
      if(colSig != NULL){
        NodoMatriz* tmpSig = colSig -> getAbajo();
        for (int j = 0; j < i; j++) {
          tmp3 = tmp3 -> getAbajo();
        }
      }
    }
    //crear hora
  }
  //crear dia
}

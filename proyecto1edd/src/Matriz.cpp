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

NodoMatriz* Matriz::buscarIndex(int c,int f){
  //buscar col
  NodoMatriz* tmp;
  if(!columna.estaVacia()){
    NodoDia* col = columna.inicio;
    while (col != NULL) {
      if(col -> getIndex() == c){
        tmp = col -> getAbajo();
        //buscar fila
        while(tmp != NULL){
          if(tmp -> getIndexFila() == f){
            return tmp;
          }
          tmp = tmp -> getAbajo();
        }
        return NULL;
      }
      col = col -> getDerecha();
    }
    return NULL;
  }
  return NULL;
}

void insertar(TratamientoMatriz t,Dia d,Hora h){
  if(existeDia(d.valor)){
    if(existeHora(h.inicio)){
      //insertar
      //obtener indices
      int iCol = columna.getIndex(d.valor);
      int iFil = fila.getIndex(h.inicio);
      //crear nuevo nodo
      NodoMatriz* nuevo = new NodoMatriz(t);
      nuevo.setIndexCol(iCol);
      nuevo.setIndexFila(iFil);
      //obtener Nodos
      NodoDia* col = columna.buscar(d.valor);
      NodoHora* fil = fila.buscar(h.inicio);
      NodoMatriz* tmp= col -> getAbajo();
      //obtener anteriores y siguientes
      NodoDia* colAnt = col -> getIzquierda();
      NodoMatriz* nodoAnt;
      NodoDia* colSig = col -> getDerecha();
      NodoMatriz* nodoSig;
      //ordenar por indices
      //si no hay ninguno
      if(tmp == NULL) {
        columna.setAbajo(nuevo);
        //si es la primera columna
        if(iCol == 0){
          fil -> setDerecha(nuevo);
          //si tiene nodos a su derecha
          while(colSig != NULL){
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(tmpSig != NULL){
              if(tmpSig -> getIndexFila() == iFil){
                nodoSig = tmpSig;
                break;
              }
              tmpSig = tmpSig -> getAbajo();
            }
            colSig = colSig ->getDerecha();
          }
          if(tmpSig != NULL){
            nuevo -> setDerecha(nodoSig);
            nodoSig -> setIzquierda(nuevo);
          }
        }
        else {
          //buscar si existe nodo matriz anterior
          while (colAnt != NULL) {
            NodoMatriz* tmpAnt = colAnt -> getAbajo();
            while (tmpAnt != NULL) {
              if(tmpAnt -> getIndexFila()==iFil){
                nodoAnt = tmpAnt;
                break;
              }
              tmpAnt = tmpAnt -> getAbajo();
            }
            colAnt = colAnt -> getIzquierda();
          }
          if(tmpAnt != NULL){
            nuevo -> setIzquierda(nodoAnt);
            nodoAnt -> setDerecha(nuevo);
          }
          while(colSig != NULL){
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(tmpSig != NULL){
              if(tmpSig -> getIndexFila() == iFil){
                nodoSig = tmpSig;
                break;
              }
              tmpSig = tmpSig -> getAbajo();
            }
            colSig = colSig ->getDerecha();
          }
          if(tmpSig != NULL){
            nuevo -> setDerecha(nodoSig);
            nodoSig -> setIzquierda(nuevo);
          }
        }
      } else {
        //si es menor al primero
        if(nuevo -> getIndexFila() < tmp -> getIndexFila()){
          //insetar al inicio
          columna -> setAbajo(nuevo);
          nuevo -> setAbajo(tmp);
          tmp -> setArriba(nuevo);
          //si es la primera columna
          if(iCol == 0){
            fil -> setDerecha(nuevo);
            //si tiene nodos a su derecha
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
          else {
            //buscar si existe nodo matriz anterior
            while (colAnt != NULL) {
              NodoMatriz* tmpAnt = colAnt -> getAbajo();
              while (tmpAnt != NULL) {
                if(tmpAnt -> getIndexFila()==iFil){
                  nodoAnt = tmpAnt;
                  break;
                }
                tmpAnt = tmpAnt -> getAbajo();
              }
              colAnt = colAnt -> getIzquierda();
            }
            if(tmpAnt != NULL){
              nuevo -> setIzquierda(nodoAnt);
              nodoAnt -> setDerecha(nuevo);
            }
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
        }
        else if(nuevo -> getIndexFila() > tmp -> getIndexFila()){
          //insertar al final
          tmp -> setAbajo(nuevo);
          nuevo -> setArriba(tmp);
          //si es la primera columna
          if(iCol == 0){
            fil -> setDerecha(nuevo);
            //si tiene nodos a su derecha
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
          else {
            //buscar si existe nodo matriz anterior
            while (colAnt != NULL) {
              NodoMatriz* tmpAnt = colAnt -> getAbajo();
              while (tmpAnt != NULL) {
                if(tmpAnt -> getIndexFila()==iFil){
                  nodoAnt = tmpAnt;
                  break;
                }
                tmpAnt = tmpAnt -> getAbajo();
              }
              colAnt = colAnt -> getIzquierda();
            }
            if(tmpAnt != NULL){
              nuevo -> setIzquierda(nodoAnt);
              nodoAnt -> setDerecha(nuevo);
            }
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
        } else {
          //insetar en medio
          while (tmp -> getIndexFila() < nuevo -> getIndexFila()) {
            tmp = tmp -> getAbajo();
          }
          NodoMatriz* tmpMat = tmpMat -> getArriba();
          tmpMat -> setAbajo(nuevo);
          nuevo -> setArriba(tmpMat);
          tmp -> setArriba(nuevo);
          nuevo -> setAbajo(tmp);
          if(iCol == 0){
            fil -> setDerecha(nuevo);
            //si tiene nodos a su derecha
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
          else {
            //buscar si existe nodo matriz anterior
            while (colAnt != NULL) {
              NodoMatriz* tmpAnt = colAnt -> getAbajo();
              while (tmpAnt != NULL) {
                if(tmpAnt -> getIndexFila()==iFil){
                  nodoAnt = tmpAnt;
                  break;
                }
                tmpAnt = tmpAnt -> getAbajo();
              }
              colAnt = colAnt -> getIzquierda();
            }
            if(tmpAnt != NULL){
              nuevo -> setIzquierda(nodoAnt);
              nodoAnt -> setDerecha(nuevo);
            }
            while(colSig != NULL){
              NodoMatriz* tmpSig = colSig -> getAbajo();
              while(tmpSig != NULL){
                if(tmpSig -> getIndexFila() == iFil){
                  nodoSig = tmpSig;
                  break;
                }
                tmpSig = tmpSig -> getAbajo();
              }
              colSig = colSig ->getDerecha();
            }
            if(tmpSig != NULL){
              nuevo -> setDerecha(nodoSig);
              nodoSig -> setIzquierda(nuevo);
            }
          }
        }
      }
    }
    //crear hora
  }
  //crear dia
}

TratamientoMatriz Matriz::getTratamiento(int dia,float hora){

}

bool Matriz::estaVacia(){
  NodoDia* tmpCol = columna -> inicio;
  NodoMatriz* tmpMat = tmpCol -> getAbajo();
  int cont = 0;
  while (tmpCol != NULL){
    while (tmpMat != NULL) {
      cont++;
      tmpMat = tmpMat -> getAbajo();
    }
    tmpCol = tmpCol -> getDerecha();
  }
  if (cont != 0) {
    return false;
  } else {
    return true;
  }
}

bool Matriz::existeDia(int dia){

}

bool Matriz::existeHora(float hora){

}

std::list<NodoMatriz> getList(){

}

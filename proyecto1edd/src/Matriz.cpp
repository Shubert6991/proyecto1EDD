#include "Matriz.h"

Matriz::Matriz(ListaDias* col,ListaHoras* fil){
  columna = col;
  fila = fil;
}

bool Matriz::estaVacia(){
  NodoDia* tmpCol = columna -> inicio;
  NodoMatriz* tmpMat = tmpCol -> getAbajo();
  int cont = 0;
  while (tmpCol != NULL){
    tmpMat = tmpCol ->getAbajo();
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
  NodoDia* nodo = columna -> buscar(dia);
  if(nodo != NULL) return true;
  else return false;
}

bool Matriz::existeHora(float hora){
  NodoHora* nodo = fila -> buscar(hora);
  if(nodo != NULL) return true;
  else return false;
}

NodoMatriz* Matriz::buscar(int dia,float hora){
//existeDia y existeHora
if(existeDia(dia) && existeHora(hora)){
  NodoDia* col = columna -> buscar(dia);
  NodoHora* f = fila -> buscar(hora);
  NodoMatriz* tmp = col -> getAbajo();
  int iCol = columna -> getIndex(col);
  int iFil = fila -> getIndex(f);
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
  if(!columna -> estaVacia()){
    NodoDia* col = columna -> inicio;
    while (col != NULL) {
      if(columna -> getIndex(col) == c){
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

void Matriz::insertar(TratamientoMatriz t,Dia d,Hora h){
  if(existeDia(d.valor)){
    if(existeHora(h.inicio)){
      //insertar
      //obtener Nodos
      NodoDia* col = columna -> buscar(d.valor);
      NodoHora* fil = fila -> buscar(h.inicio);
      NodoMatriz* tmp= col -> getAbajo();
      //obtener indices
      int iCol = columna -> getIndex(col);
      int iFil = fila -> getIndex(fil);
      //crear nuevo nodo
      NodoMatriz* nuevo = new NodoMatriz(t);
      nuevo -> setIndexCol(iCol);
      nuevo -> setIndexFila(iFil);
      //obtener anteriores y siguientes
      NodoDia* colAnt = col -> getIzquierda();
      NodoMatriz* nodoAnt;
      NodoDia* colSig = col -> getDerecha();
      NodoMatriz* nodoSig;
      //ordenar por indices
      //si no hay ninguno
      if(tmp == NULL) {
        col-> setAbajo(nuevo);
        //si es la primera columna
        if(iCol == 0){
          fil -> setDerecha(nuevo);
          //si tiene nodos a su derecha
          NodoMatriz* tmpSig = colSig -> getAbajo();
          while(colSig != NULL){
            tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpAnt = colAnt -> getAbajo();
          while (colAnt != NULL) {
            tmpAnt = colAnt -> getAbajo();
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
          NodoMatriz* tmpSig = colSig -> getAbajo();
          while(colSig != NULL){
            tmpSig = colSig -> getAbajo();
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
          col -> setAbajo(nuevo);
          nuevo -> setAbajo(tmp);
          tmp -> setArriba(nuevo);
          //si es la primera columna
          if(iCol == 0){
            fil -> setDerecha(nuevo);
            //si tiene nodos a su derecha
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpAnt = colAnt -> getAbajo();
            while (colAnt != NULL) {
              tmpAnt = colAnt -> getAbajo();
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
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpAnt = colAnt -> getAbajo();
            while (colAnt != NULL) {
              tmpAnt = colAnt -> getAbajo();
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
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
            NodoMatriz* tmpAnt = colAnt -> getAbajo();
            while (colAnt != NULL) {
              tmpAnt = colAnt -> getAbajo();
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
            NodoMatriz* tmpSig = colSig -> getAbajo();
            while(colSig != NULL){
              tmpSig = colSig -> getAbajo();
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
  TratamientoMatriz result = {"",""};
    NodoMatriz * search = buscar(dia,hora);
    if(search!=NULL){
        return search->getTratamiento();
    }
 return result;

}

std::list<NodoMatriz> Matriz::getList(){
  std::list<NodoMatriz> lista;
  NodoDia* tmpCol = columna -> inicio;
  NodoMatriz* tmp = tmpCol -> getAbajo();
  if(!estaVacia()){
    while (tmpCol != NULL) {
      tmp = tmpCol -> getAbajo();
      while (tmp != NULL) {
        lista.push_back(tmp -> getTratamiento());
        tmp = tmp ->getAbajo();
      }
      tmpCol=tmpCol->getDerecha();
    }
  }
  return lista;
}

void Matriz::eliminarNodo(NodoMatriz* e){
  NodoMatriz* arr = e -> getArriba();
  NodoMatriz* abj = e -> getAbajo();
  NodoMatriz* izq = e -> getIzquierda();
  NodoMatriz* der = e -> getDerecha();
  e -> setArriba(NULL);
  e -> setAbajo(NULL);
  e -> setIzquierda(NULL);
  e -> setDerecha(NULL);
  //nodos en la misma columna
  if(arr != NULL && abj != NULL){
    arr -> setAbajo(abj);
    abj -> setArriba(arr);
  } else if(arr!=NULL){
    arr -> setAbajo(NULL);
  } else {
    //columna apunta a nodo abajo
    NodoDia* col = columna -> inicio;
    NodoMatriz* tmp = col -> getAbajo();
    while (tmp != e && col != NULL){
      col = col -> getDerecha();
      tmp = col -> getAbajo();
    }
    col -> setAbajo(abj);
  }
  //nodos misma fila
  if(izq != NULL && der !=NULL){
    izq ->  setDerecha(der);
    der -> setIzquierda(izq);
  } else if(izq != NULL){
    izq -> setDerecha(NULL);
  } else {
    NodoHora* fil = fila -> inicio;
    NodoMatriz* tmp = fil -> getDerecha();
    while(tmp != e && fil != NULL){
      fil = fil -> getAbajo();
      tmp = fil -> getDerecha();
    }
    fil -> setDerecha(der);
  }
}

#include "ListaMeses.h"

ListaMeses::ListaMeses(){
  inicio = fin = NULL;
}

NodoMes* ListaMeses::buscar(int s){
  NodoMes* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getValor()==s){
          return tmp;
      }
      tmp = tmp->getAbajo();
  }
  return NULL;
}

void ListaMeses::insertarAlInicio(Mes m){
  NodoMes* nuevo = new NodoMes(m);
   if(estaVacia()){
     inicio = fin = nuevo;

   }else {
      nuevo -> setAbajo(inicio);
      inicio = nuevo;
    }
}

void ListaMeses::insertarAlFinal(Mes m){
  NodoMes* nuevo = new NodoMes(m);
    if(estaVacia()){
      inicio = fin = nuevo;

    }else {
       fin -> setAbajo(nuevo);
       fin = nuevo;
     }
}

void ListaMeses::insertarOrdenado(Mes m){
  NodoMes* nuevo = new NodoMes(m);
    if(estaVacia()){
      inicio = fin = nuevo;
    } else{
      //si es menor que el primero
      if(m.valor < inicio -> getValor()){
        insertarAlInicio(m);
      }
      //si es mayor que el ultimo
      else if(m.valor > fin -> getValor()){
        insertarAlFinal(m);
      }
      //si va en medio
      else {
        NodoMes* tmp = inicio -> getAbajo();
        //nodo anterior
        NodoMes* tmp2 = inicio;
        while(tmp -> getValor() < m.valor){
          tmp = tmp -> getAbajo();
          tmp2 = tmp2 ->getAbajo();
        }
        //insertar el nuevo nodo antes de tmp
        tmp2 -> setAbajo(nuevo);
        nuevo -> setAbajo(tmp);
    }
  }
}

Mes ListaMeses::getMes(int m){
  Mes result = {"",0};
  NodoMes* search = buscar(m);
  if(search!=NULL){
    return search -> getMes();
  }
  return result;
}

bool ListaMeses::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Mes> ListaMeses::getList(){
  std::list<Mes> lista;
    NodoMes* tmp = inicio;
    while (tmp != NULL) {
      lista.push_back(tmp -> getMes());
      tmp = tmp -> getAbajo();
    }

    return lista;
}

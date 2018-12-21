#include "ListaTratamientos.h"

ListaTratamientos::ListaTratamientos(){
  inicio = fin = NULL;
}

NodoTratamiento* ListaTratamientos::buscar(std::string s){
  NodoTratamiento* tmp = inicio;
  if(!estaVacia()){
    do {
      if(tmp->getIdentificador()==s){
          return tmp;
      }
      tmp = tmp->getSiguiente();
    } while(tmp != inicio);
  return NULL;
  }
}

void ListaTratamientos::insertarAlInicio(Tratamiento t){
  NodoTratamiento* nuevo = new NodoTratamiento(t);
  if(estaVacia()){
    inicio = fin = nuevo;
    fin -> setSiguiente(inicio);
    inicio -> setAnterior(fin);
  } else {
    nuevo -> setSiguiente(inicio);
    inicio -> setAnterior(nuevo);
    inicio = nuevo;
    fin -> setSiguiente(inicio);
    inicio -> setAnterior(fin);
  }
}

void  ListaTratamientos::insertarAlFinal(Tratamiento t) {
  NodoTratamiento* nuevo = new NodoTratamiento(t);
  if(estaVacia()){
    inicio=fin=nuevo;
    fin -> setSiguiente(inicio);
    inicio -> setAnterior(fin);
  } else {
    nuevo -> setAnterior(fin);
    fin -> setSiguiente(nuevo);
    fin = nuevo;
    fin -> setSiguiente(inicio);
    inicio -> setAnterior(fin);
  }
}

Tratamiento ListaTratamientos::getTratamiento(std::string id){
  Tratamiento result = {"",""};
  NodoTratamiento* search = buscar(id);
  if(search!=NULL){
    return search -> getTratamiento();
  }
  return result;
}

bool ListaTratamientos::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Tratamiento> ListaTratamientos::getList(){
  std::list<Tratamiento> lista;
  NodoTratamiento* tmp = inicio;
  if(!estaVacia()){
    do {
      lista.push_back(tmp -> getTratamiento());
      tmp = tmp -> getSiguiente();
    } while(tmp != inicio);
  }
}

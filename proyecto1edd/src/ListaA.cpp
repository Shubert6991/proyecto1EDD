include "ListaA.h"

ListaA::ListaA(){
  inicio = fin = NULL;
}

NodoA* ListaA::buscar(std::string s){
  NodoA* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getValor()==s){
          return tmp;
      }
      tmp = tmp->getSiguiente();
  }
  return NULL;
}

void ListaA::insertarAlInicio(Anio a){
  NodoA* nuevo = new NodoA(a);
   if(estaVacia()){
     inicio = fin = nuevo;

   }else {
      nuevo -> setSiguiente(inicio);
      inicio -> setAnterior(nuevo);
      inicio = nuevo;
    }
}

void ListaA::insertarAlFinal(Anio a){
  NodoA* nuevo = new NodoA(a);
    if(estaVacia()){
      inicio = fin = nuevo;

    }else {
       nuevo -> setAnterior(fin);
       fin -> setSiguiente(nuevo);
       fin = nuevo;
     }
}

void ListaA::insertarOrdenado(Anio a){
  NodoA* nuevo = new NodoA(a);
    if(estaVacia()){
      inicio = fin = nuevo;
    } else{
      //si es menor que el primero
      if(a.valor < inicio -> getValor()){
        insertarAlInicio(a);
      }
      //si es mayor que el ultimo
      else if(a.valor > fin -> getValor()){
        insertarAlFinal(a);
      }
      //si va en medio
      else {
        NodoA *tmp = inicio -> getSiguiente();
        while(tmp ->getValor() < a.valor){
          tmp = tmp -> getSiguiente();
        }
        //insertar el nuevo nodo antes de temp
        NodoA* antmp = tmp -> getAnterior();
        antmp -> setSiguiente(nuevo);
        nuevo -> setAnterior(antmp);
        tmp -> setAnterior(nuevo);
        nuevo -> setSiguiente(tmp);
      }
    }
}

Anio ListaA::getYear(str::string y){
  Anio result = {"",""};
  NodoA* search = buscar(y);
  if(search!=NULL){
    return search -> getAnio();
  }
  return result;
}

bool ListaA::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Anio> ListaA::getList(){
  std::list<Anio> lista;
    NodoA* tmp = inicio;

    while (tmp != NULL) {
      lista.push_back(tmp -> getAnio());
      tmp = tmp -> getSiguiente();
    }

    return lista;
}

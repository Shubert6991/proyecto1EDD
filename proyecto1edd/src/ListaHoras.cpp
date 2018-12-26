include "ListaHoras.h"

ListaHoras::ListaHoras(){
  inicio = fin = NULL;
}

NodoHora* ListaHoras::buscar(float ini){
  NodoHora* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getInicio()==ini){
          return tmp;
      }
      tmp = tmp->getAbajo();
  }
  return NULL;
}

void ListaHoras::insertarAlInicio(Hora h){
  NodoHora* nuevo = new NodoHora(h);
   if(estaVacia()){
     inicio = fin = nuevo;

   }else {
      nuevo -> setAbajo(inicio);
      inicio -> setArriba(nuevo);
      inicio = nuevo;
    }
}

void ListaHoras::insertarAlFinal(Hora h){
  NodoHora* nuevo = new NodoHora(h);
    if(estaVacia()){
      inicio = fin = nuevo;

    }else {
       nuevo -> setAbajo(fin);
       fin -> setArriba(nuevo);
       fin = nuevo;
     }
}

void ListaHoras::insertarOrdenado(Hora h){
  NodoHora* nuevo = new NodoHora(h);
    if(estaVacia()){
      inicio = fin = nuevo;
    } else{
      //si es menor que el primero
      if(h.inicio < inicio -> getInicio()){
        insertarAlInicio(h);
      }
      //si es mayor que el ultimo
      else if(h.valor > fin -> getInicio()){
        insertarAlFinal(h);
      }
      //si va en medio
      else {
        NodoHora *tmp = inicio -> getAbajo();
        while(tmp ->getInicio() < h.inicio){
          tmp = tmp -> getAbajo();
        }
        //insertar el nuevo nodo antes de temp
        NodoHora* antmp = tmp -> getArriba();
        antmp -> setAbajo(nuevo);
        nuevo -> setArriba(antmp);
        tmp -> setArriba(nuevo);
        nuevo -> setAbajo(tmp);
      }
    }
}

Hora ListaHoras::getHora(float ini){
  Hora result = {"",""};
  NodoHora* search = buscar(ini);
  if(search!=NULL){
    return search -> getHora();
  }
  return result;
}

bool ListaHoras::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Hora> ListaHoras::getList(){
  std::list<Hora> lista;
    NodoHora* tmp = inicio;
    while (tmp != NULL) {
      lista.push_back(tmp -> getHora());
      tmp = tmp -> getAbajo();
    }

    return lista;
}

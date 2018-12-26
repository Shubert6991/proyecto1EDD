include "ListaDias.h"

ListaDias::ListaDias(){
  inicio = fin = NULL;
}

NodoDia* ListaDias::buscar(int s){
  NodoDia* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getValor()==s){
          return tmp;
      }
      tmp = tmp->getDerecha();
  }
  return NULL;
}

void ListaDias::insertarAlInicio(Dia d){
  NodoDia* nuevo = new NodoDia(d);
   if(estaVacia()){
     inicio = fin = nuevo;

   }else {
      nuevo -> setDerecha(inicio);
      inicio -> setIzquierda(nuevo);
      inicio = nuevo;
    }
}

void ListaDias::insertarAlFinal(Dia d){
  NodoDia* nuevo = new NodoDia(d);
    if(estaVacia()){
      inicio = fin = nuevo;

    }else {
       nuevo -> setDerecha(fin);
       fin -> setIzquierda(nuevo);
       fin = nuevo;
     }
}

void ListaDias::insertarOrdenado(Dia d){
  NodoDia* nuevo = new NodoDia(d);
    if(estaVacia()){
      inicio = fin = nuevo;
    } else{
      //si es menor que el primero
      if(d.valor < inicio -> getValor()){
        insertarAlInicio(d);
      }
      //si es mayor que el ultimo
      else if(d.valor > fin -> getValor()){
        insertarAlFinal(d);
      }
      //si va en medio
      else {
        NodoDia *tmp = inicio -> getDerecha();
        while(tmp ->getValor() < d.valor){
          tmp = tmp -> getDerecha();
        }
        //insertar el nuevo nodo antes de temp
        NodoDia* antmp = tmp -> getIzquierda();
        antmp -> setDerecha(nuevo);
        nuevo -> setIzquierda(antmp);
        tmp -> setIzquierda(nuevo);
        nuevo -> setDerecha(tmp);
      }
    }
}

Dia ListaDias::getDia(int d){
  Dia result = {"",""};
  NodoDia* search = buscar(d);
  if(search!=NULL){
    return search -> getDia();
  }
  return result;
}

bool ListaA::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Dia> ListaDias::getList(){
  std::list<Dia> lista;
    NodoDia* tmp = inicio;
    while (tmp != NULL) {
      lista.push_back(tmp -> getAnio());
      tmp = tmp -> getDerecha();
    }

    return lista;
}

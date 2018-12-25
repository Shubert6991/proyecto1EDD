include "ListaSemanas.h"

ListaSemanas::ListaSemanas(){
  inicio = fin = NULL;
}

NodoSemana* ListaSemanas::buscar(std::string s){
  NodoSemana* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getNumero()==s){
          return tmp;
      }
      tmp = tmp->getAbajo();
  }
  return NULL;
}

void ListaSemanas::insertarAlInicio(Semana s){
  NodoSemana* nuevo = new NodoSemana(s);
   if(estaVacia()){
     inicio = fin = nuevo;

   }else {
      nuevo -> setAbajo(inicio);
      inicio = nuevo;
    }
}

void ListaSemanas::insertarAlFinal(Semana s){
  NodoSemana* nuevo = new NodoSemana(s);
    if(estaVacia()){
      inicio = fin = nuevo;

    }else {
       fin -> setAbajo(nuevo);
       fin = nuevo;
     }
}

void ListaSemanas::insertarOrdenado(Semana s){
  NodoSemana* nuevo = new NodoSemana(s);
    if(estaVacia()){
      inicio = fin = nuevo;
    } else{
      //si es menor que el primero
      if(s.numero < inicio -> getNumero()){
        insertarAlInicio(s);
      }
      //si es mayor que el ultimo
      else if(s.numero > fin -> getNumero()){
        insertarAlFinal(s);
      }
      //si va en medio
      else {
        NodoSemana* tmp = inicio -> getAbajo();
        //nodo anterior
        NodoSemana* tmp2 = inicio;
        while(tmp -> getNumero() < s.numero){
          tmp = tmp -> getAbajo();
          tmp2 = tmp2 ->getAbajo();
        }
        //insertar el nuevo nodo antes de tmp
        tmp2 -> setAbajo(nuevo);
        nuevo -> setSiguiente(tmp);
    }
}

Semana ListaSemanas::getSemana(str::string s){
  Semana result = {"",""};
  NodoSemana* search = buscar(s);
  if(search!=NULL){
    return search -> getSemana();
  }
  return result;
}

bool ListaSemanas::estaVacia(){
  if (inicio == NULL) {
    return true;
  }
  return false;
}

std::list<Semana> ListaSemanas::getList(){
  std::list<Semana> lista;
    NodoSemana* tmp = inicio;
    while (tmp != NULL) {
      lista.push_back(tmp -> getSemana());
      tmp = tmp -> getAbajo();
    }

    return lista;
}

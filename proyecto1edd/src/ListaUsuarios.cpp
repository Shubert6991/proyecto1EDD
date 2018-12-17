#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios(){
  inicio = fin = NULL;
}

NodoUsuario* ListaUsuarios::buscar(std::string s){
  NodoUsuario* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getIdentificador()==s){
          return tmp;
      }
      tmp = tmp->getSiguiente();
  }
  return NULL;
}

void ListaUsuarios::insertarAlInicio(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;
    fin -> setSiguiente(inicio);

  }else {
     nuevo -> setSiguiente(inicio);
     inicio = nuevo;
     fin -> setSiguiente(inicio);
   }
}

void ListaUsuarios::insertarAlFinal(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;
    fin ->setSiguiente(nuevo);
  }else {
     fin -> setSiguiente(nuevo);
     fin = nuevo;
     fin -> setSiguiente(inicio);
   }
}

void ListaUsuarios::insertarOrdenado(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;
    fin -> setSiguiente(nuevo);
  } else{
    //si va antes que el primero
    if(u.nombre < inicio -> getNombre()){
      insertarAlInicio(u);
    }
    //si va despues que el ultimo
    else if(u.nombre > fin -> getNombre()){
      insertarAlFinal(u);
    }
    //si va en el medio
    else {
      NodoUsuario* tmp = inicio -> getSiguiente();
      //nodo anterior
      NodoUsuario* tmp2 = inicio;
      while(tmp -> getNombre() < u.nombre){
        tmp = tmp -> getSiguiente();
        tmp2 = tmp2 ->getSiguiente();
      }
      //insertar el nuevo nodo antes de tmp
      tmp2 -> setSiguiente(nuevo);
      nuevo -> setSiguiente(tmp);
    }
  }

}

bool ListaUsuarios::estaVacia() {
  if(inicio == NULL){
    return true;
  }
  return false;
}

Usuario ListaUsuarios::getUsuario(std::string id){
  Usuario result = {"",""};
    NodoUsuario * search = buscar(id);
    if(search!=NULL){
        return search->getUser();
    }
 return result;
}

std::list<Usuario> ListaUsuarios::getList(){
  std::list<Usuario> lista;
  NodoUsuario* tmp = inicio;
  if(!estaVacia()){
    while (tmp->getSiguiente() != inicio) {
      lista.push_back(tmp -> getUser());
      tmp = tmp -> getSiguiente();
    }
  }
  return lista;
}

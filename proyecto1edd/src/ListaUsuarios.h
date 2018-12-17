#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
#include "NodoUsuario.h"
#include <list>

class ListaUsuarios{
private:
  NodoUsuario* buscar(std::string s);
public:
  //atributos
  NodoUsuario *inicio,*fin;
  //constructor
  ListaUsuarios();
  //metodos
  void insertarAlInicio(Usuario u);
  void insertarAlFinal(Usuario u);
  void insertarOrdenado(Usuario u);
  Usuario getUsuario(std::string id);
  bool estaVacia();
  std::list<Usuario> getList();
}

#endif //LISTAUSUARIOS_H

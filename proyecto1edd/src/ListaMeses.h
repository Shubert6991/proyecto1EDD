#ifndef LISTAMESES_H
#define LISTAMESES_H
#include <string>
#include <list>
#include "NodoMes.h"

class ListaMeses{
private:
  NodoMes* buscar(std::string s);
public:
  NodoMes *inicio,*fin;
  ListaA();
  void insertarAlInicio(Mes m);
  void insertarAlFinal(Mes m);
  void insertarOrdenado(Mes m);
  Mes getMes(str::string m);
  bool estaVacia();
  std::list<Mes> getList();
};
#endif

#ifndef LISTAMESES_H
#define LISTAMESES_H
#include <string>
#include <list>
#include "NodoMes.h"

class ListaMeses{
private:
  NodoMes* buscar(int s);
public:
  NodoMes *inicio,*fin;
  ListaMeses();
  void insertarAlInicio(Mes m);
  void insertarAlFinal(Mes m);
  void insertarOrdenado(Mes m);
  Mes getMes(int m);
  bool estaVacia();
  std::list<Mes> getList();
};
#endif

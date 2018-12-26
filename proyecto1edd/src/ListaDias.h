#ifndef LISTADIAS_H
#define LISTADIAS_H
#include <string>
#include <list>
#include "NodoDia.h"

class ListaDias{
public:
  NodoDia* buscar(int s);
  NodoDia *inicio,*fin;
  ListaDias();
  void insertarAlInicio(Dia d);
  void insertarAlFinal(Dia d);
  void insertarOrdenado(Dia d);
  Dia getDia(int d);
  bool estaVacia();
  std::list<Dia> getList();
  int getIndex(NodoDia* nd);
};
#endif

#ifndef LISTAHORAS_H
#define LISTAHORAS_H
#include <string>
#include <list>
#include "NodoHora.h"

class ListaHoras{
public:
  NodoHora* buscar(float ini);
  NodoHora *inicio,*fin;
  ListaHoras();
  void insertarAlInicio(Hora h);
  void insertarAlFinal(Hora h);
  void insertarOrdenado(Hora h);
  Hora getHora(float ini);
  bool estaVacia();
  std::list<Hora> getList();
  int getIndex(NodoHora* nh);
};
#endif

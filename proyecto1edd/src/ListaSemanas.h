#ifndef LISTASEMANAS_H
#define LISTASEMANAS_H
#include <string>
#include <list>
#include "NodoSemana.h"

class ListaSemanas{
private:
  NodoSemana* buscar(int s);
public:
  NodoSemana *inicio, *fin;
  ListaSemanas();
  void insertarAlInicio(Semana s);
  void insertarAlFinal(Semana s);
  void insertarOrdenado(Semana s);
  Semana getSemana(int s);
  bool estaVacia();
  std::list<Semana> getList();
};

#endif

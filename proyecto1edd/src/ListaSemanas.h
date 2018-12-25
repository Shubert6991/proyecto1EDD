#ifndef LISTASEMANAS_H
#define LISTASEMANAS_H
#include <string>
#include <list>
#include "NodoSemana.h"

class ListaSemanas{
private:
  NodoSemana* buscar(std::string s);
public:
  NodoSemana *inicio, *fin;
  ListaSemanas();
  void insertarAlInicio(Semana s);
  void insertarAlFinal(Semana s);
  void insertarOrdenado(Semana s);
  Semana getSemana(std::string s);
  bool estaVacia();
  std::list<Semana> getList();
}

#endif

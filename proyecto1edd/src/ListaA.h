#ifndef LISTAA_H
#define LISTAA_H
#include <string>
#include <list>
#include "NodoA.h"

class ListaA{
private:
  NodoA* buscar(std::string s);
public:
  NodoA *inicio,*fin;
  ListaA();
  void insertarAlInicio(Anio a);
  void insertarAlFinal(Anio a);
  void insertarOrdenado(Anio a);
  Anio getYear();
  bool estaVacia();
  std::list<Anio> getList();
  
};
#endif

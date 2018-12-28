#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <list>
#include "NodoMatriz.h"
#include "ListaDias.h"
#include "ListaHoras.h"

class Matriz{
private:
  NodoMatriz* buscar(int dia,float hora);
  NodoMatriz* buscarIndex(int c,int f);
public:
  ListaDias* columna;
  ListaHoras* fila;
  Matriz(ListaDias* col,ListaHoras* fil);
  TratamientoMatriz getTratamiento(int dia,float hora);
  bool estaVacia();
  bool existeDia(int dia);
  bool existeHora(float hora);
  void insertar(TratamientoMatriz t,Dia d,Hora h);
  std::list<NodoMatriz> getList();
  void eliminarNodo(NodoMatriz* e);
};
#endif

#ifndef NODOSEMANA_H
#define NODOSEMANA_H
#include <string>
#include "Matriz.h"

struct Semana{
  int numero;
  int inicio;
  int fin;
};

class NodoSemana{
protected:
  Semana semana;
  NodoSemana *abajo;
  Matriz *derecha;
public:
  //constructor
  NodoSemana(Semana s);
  NodoSemana(Semana s,NodoSemana *abj,Matriz *der);
  //metodos
  Semana getSemana();
  NodoSemana* getAbajo();
  Matriz* getMatriz();
  void setAbajo(NodoSemana* abj);
  void setMatriz(Matriz* m);
  int getNumero();
  int getInicio();
  int getFin();
};
#endif

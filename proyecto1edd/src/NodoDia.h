#ifndef NODODIA_H
#define NODODIA_H
#include <string>
#include "NodoMatriz.h"

struct Dia{
  std::string nombre;
  int valor;
};

class NodoDia{
protected:
  Dia dia;
  NodoDia *derecha, *izquierda;
  NodoMatriz *abajo;
public:
  //constructor
  NodoDia(Dia d);
  NodoDia(Dia d,NodoDia *der,NodoDia *izq,NodoMatriz* abj);
  //metodos
  Dia getDia();
  NodoDia* getDerecha();
  NodoDia* getIzquierda();
  NodoMatriz* getAbajo();
  void setDerecha(NodoDia* der);
  void setIzquierda(NodoDia* izq);
  void setAbajo(NodoMatriz* abj);
  std::string getNombre();
  int getValor();
};
#endif

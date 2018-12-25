#ifndef NODOMES_H
#define NODOMES_H
#include <string>

struct Mes{
  std::string nombre;
  int valor;
};

class NodoMes{
protected:
  Mes mes;
  NodoMes* abajo;
  NodoSemana* derecha;
public:
  //constructor
  NodoMes(Mes m);
  NodoMes(Mes m,NodoMes* abj,NodoSemana *der);
  //metodos
  Mes getMes();
  NodoMes* getAbajo();
  NodoSemana* getDerecha();
  void setAbajo(NodoMes *abj);
  void setDerecha(NodoSemana *der);
  std::string getNombre();
  int getValor();
};
#endif //NODOMES_H

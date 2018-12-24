#ifndef NODOMES_H
#define NODOMES_H
#include <string>

struct Mes{
  std::string nombre;
  int valor;
}

class NodoMes{
protected:
  Mes mes;
  NodoMes* abajo;
public:
  //constructor
  NodoMes(Mes m);
  NodoMes(Mes m,NodoMes* abj);
  //metodos
  Mes getMes();
  NodoMes* getAbajo();
  void setAbajo(NodoMes *abj);
  std::string getNombre();
  int getValor();
}
#endif //NODOMES_H

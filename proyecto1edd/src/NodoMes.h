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
}
#endif //NODOMES_H

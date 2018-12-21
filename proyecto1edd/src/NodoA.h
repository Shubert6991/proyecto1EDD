#ifndef NODOA_H
#define NODOA_H
#include <string>

struct Anio {
  int valor;
};

class NodoA {
protected:
 Anio anio;
 NodoA *siguiente, *anterior;
 NodoMes* abajo;
public:
  //constructor
  NodoA(Anio a);
  NodoA(Anio a,NodoA *sig,NodoA *ant,NodoA *abj);
  //metodos
  Anio getAnio();
  NodoA* getSiguiente();
  NodoA* getAnterior();
  NodoMes* getAbajo();
  void setSiguiente(NodoA *sig);
  void setAnterior(NodoA *ant);
  void setAbajo(NodoMes *abj);
  int getValor();
}
#endif //NODOA_H

#ifndef NODOHORA_H
#define NODOHORA_H
#include <string>

struct Hora{
  float inicio;
  float fin;
};

class NodoHora{
protected:
  Hora hora;
  NodoHora *abajo,*arriba;
  NodoMatriz* derecha;
public:
  //constructor
  NodoHora(Hora h);
  NodoHora(Hora h,NodoHora *abj,NodoHora *arr,NodoMatriz *der);
  //metodos
  Hora getHora();
  NodoHora* getAbajo();
  NodoHora* getArriba();
  NodoMatriz* getDerecha();
  void setAbajo(NodoHora *abj);
  void setArriba(NodoHora *arr);
  void setDerecha(NodoMatriz *der);
  float getInicio();
  float getFin();
};

#endif

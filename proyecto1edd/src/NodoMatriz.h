#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>

struct Tratamiento{
  std::string transaccion;
  std::string codTrat;
  std::string codUsuario;
  bool estado;
};

class NodoMatriz {
protected:
  Tratamiento trat;
  NodoMatriz *arriba,*abajo,*izquierda,*derecha;
public:
  //constructor
  NodoMatriz(Tratamiento t);
  NodoMatriz(Tratamiento t,NodoMatriz *arr,NodoMatriz *abj,NodoMatriz *izq, NodoMatriz *der);
  //metodos
  Tratamiento getTratamiento();
  NodoMatriz* getArriba();
  NodoMatriz* getAbajo();
  NodoMatriz* getIzquierda();
  NodoMatriz* getDerecha();
  void setArriba(NodoMatriz *arr);
  void setAbajo(NodoMatriz *abj);
  void setIzquierda(NodoMatriz *izq);
  void setDerecha(NodoMatriz *der);
  std::string getTransaccion();
  std::string getCodTratamiento();
  std::string getCodUsuario();
  bool getEstado();
}
#endif

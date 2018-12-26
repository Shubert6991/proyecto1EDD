#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>

struct TratamientoMatriz{
  std::string transaccion;
  std::string codTrat;
  std::string codUsuario;
  bool estado;
  int indexDia;
  int indexHora;
};

class NodoMatriz {
protected:
  TratamientoMatriz trat;
  NodoMatriz *arriba,*abajo,*izquierda,*derecha;
public:
  //constructor
  NodoMatriz(TratamientoMatriz t);
  NodoMatriz(TratamientoMatriz t,NodoMatriz *arr,NodoMatriz *abj,NodoMatriz *izq, NodoMatriz *der);
  //metodos
  TratamientoMatriz getTratamiento();
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

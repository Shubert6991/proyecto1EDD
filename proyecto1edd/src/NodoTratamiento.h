#ifndef NODOTRATAMIENTO_H
#define NODOTRATAMIENTO_H
#include <string>

struct Tratamiento {
  std::string identificador;
  std::string nombre;
  unsigned float costo;
};

class NodoTratamiento {
protected:
  Tratamiento trat;
  NodoTratamiento *siguiente,*anterior;
  std::string autogenerar();
public:
  //constructor
  NodoTratamiento(Tratamiento t);
  NodoTratamiento(Tratamiento t,NodoTratamiento *s,NodoTratamiento *a);
  //metodos
  Tratamiento getTratamiento();
  NodoUsuario* getSiguiente();
  NodoUsuario* getAnterior();
  void setSiguiente(NodoTratamiento *s);
  void setAnterior(NodoTratamiento *a);
  std::string getIdentificador();
  std::string getNombre();
  unsigned float getCosto();
}
#endif//NODOTRATAMIENTO_H

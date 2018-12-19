#ifndef LISTATRATAMIENTOS_H
#define LISTATRATAMIENTOS_H
#include <string>
#include <list>
#include "NodoTratamiento.h"

class ListaTratamientos{
private:
  NodoTratamiento* buscar(std::string s);
public:
  NodoTratamiento *inicio,*fin;
  ListaTratamientos();
  void insertarAlInicio(Tratamiento t);
  void insertarAlFinal(Tratamiento t);
  Tratamiento getTratamiento(std::string id);
  bool estaVacia();
  std::list<Tratamiento> getList();
};
#endif //LISTATRATAMIENTOS_H

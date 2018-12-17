#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <string>

struct Usuario {
  std::string identificador;
  std::string nombre;
  std::string direccion;
  int telefono;
};

class NodoUsuario {
protected:
  Usuario user;
  NodoUsuario *siguiente;
  std::string autogenerar();
public:
  //constructor
  NodoUsuario(Usuario u);
  NodoUsuario(Usuario u,NodoUsuario *sig);
  //metodos
  Usuario getUser();
  NodoUsuario* getSiguiente();
  void setSiguiente(NodoUsuario *sig);
  std::string getIdentificador();
  std::string getNombre();
  std::string getDireccion();
  int getTelefono();

}

#endif  //NODOUSUARIO_H

#include <NodoUsuario.h>
std::string NodoUsuario::autogenerar()
{
  static const std::string charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  srand(time(0));
  std::string alphanumeric = "";
  for(int i = 0; i < 8; i++) {
    alphanumeric += charList [rand() % charList.size()];
  }
return alphanumeric;
}

NodoUsuario::NodoUsuario(Usuario u){
  u.identificador = autogenerar();
  user = u;
  siguiente = NULL;
}

NodoUsuario::NodoUsuario(Usuario u,NodoUsuario *sig){
  u.identificador = autogenerar();
  user = u;
  siguiente = sig;
}

Usuario NodoUsuario::getUser(){
  return user;
}

NodoUsuario* NodoUsuario::getSiguiente(){
  return siguiente;
}

void NodoUsuario::setSiguiente(NodoUsuario *sig){
  siguiente = sig;
}

std::string NodoUsuario::getIdentificador(){
  return user.identificador;
}

std::string NodoUsuario::getNombre(){
  return user.nombre;
}

std::string NodoUsuario::getDireccion(){
  return user.direccion;
}

int NodoUsuario::getTelefono(){
  return user.telefono;
}

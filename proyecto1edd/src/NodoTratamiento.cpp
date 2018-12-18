#include "NodoTratamiento.h"

std::string NodoTratamiento::autogenerar(){
  static const std::string charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  srand(time(0));
  std::string alphanumeric = "";
  for(int i = 0; i < 8; i++) {
    alphanumeric += charList [rand() % charList.size()];
  }
return alphanumeric;
}

NodoTratamiento::NodoTratamiento(Tratamiento t){
  trat = t;
  siguiente = NULL;
  anterior = NULL;
}

NodoTratamiento::NodoTratamiento(Tratamiento t,NodoTratamiento *s,NodoTratamiento *a){
  trat = t;
  siguiente = s;
  anterior = a;
}

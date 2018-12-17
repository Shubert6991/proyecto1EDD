// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef PROYECTO1EDD_H
#define PROYECTO1EDD_H
#include <string>

#include "ListaUsuarios.h"

#include <ngrest/common/Service.h>
// '*location' comment sets resource path for this service
// *location: proyecto1edd
class proyecto1EDD: public ngrest::Service
{
public:
    // '*method' metacomment sets HTTP method for the operation. GET is default method.
    // *method: GET
    //
    std::string echo(const std::string& text);

    //*method: POST
    //*location: /newuser
    std::string newuser(Usuario& user);

    //*method: GET
    //*location: /getusuarios
    std::list<Usuario> getusuarios();
};


#endif // PROYECTO1EDD_H

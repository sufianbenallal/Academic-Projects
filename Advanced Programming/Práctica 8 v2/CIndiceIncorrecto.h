#if !defined _CINDICEINCORRECTO_H_
#define _CINDICEINCORRECTO_H_

#include <string>

class CIndiceIncorrecto
{
private:
    std::string error;
    int indice;
public:
    CIndiceIncorrecto(std::string msg = "Indice Incorrecto : ")
    {
        error = msg;
    };

    std::string what() { return error; }; // devuelve un mensaje "error" 
    int ind() { return indice; };
};

#endif 
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class Administrador : public Usuario
{
public:
    Administrador(int id, const QString &nombre, const QString &contrasenya);
};

#endif // ADMINISTRADOR_H

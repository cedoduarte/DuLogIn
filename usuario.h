#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
public:
    Usuario(int id = -1, const QString &nombre = "",
            const QString &contrasenya = "");
    int id() const { return mId; }
    QString nombre() const { return mNombre; }
    QString contrasenya() const { return mContrasenya; }
    void setId(int id) { mId = id; }
    void setNombre(const QString &nombre) { mNombre = nombre; }

    void setContrasenya(const QString &contrasenya)
    {
        mContrasenya = contrasenya;
    }
private:
    int mId;
    QString mNombre;
    QString mContrasenya;
};

#endif // USUARIO_H

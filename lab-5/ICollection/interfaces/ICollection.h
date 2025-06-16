#include "IIterator.h"
#ifndef _ICOLLECTION_H
#define _ICOLLECTION_H

/**
 * Interfaz de colecciones
 */
class ICollection
{
public:
    /**
     * Agrega un elemento a la coleccion. Si ya existia no hace nada
     */
    virtual void add(ICollectible *) = 0;

    /**
     * Borra el elemento de la coleccion. Si no existe no hace nada
     */
    virtual void remove(ICollectible *) = 0;

    /**
     * Setea a null el elemento de la colección. Si no existe no hace nada
     */
    virtual void setNull(ICollectible *) = 0;

    /*
     * Devuelve true si hay un elemento en la coleccion cuya direccion de memoria
     * coincide con el argumente
     */
    virtual bool member(ICollectible *) const = 0;

    /*
     * Devuelve true si size() es 0
     */
    virtual bool isEmpty() const = 0;

    /**
     * Devuelve el tamano de la coleccion
     */
    virtual int getSize() const = 0;

    /*
     * Devuelve una instancia de IIterator creada con el operador new
     */
    virtual IIterator *getIterator() = 0;

    /**
     * Limpia la colección, seteando a null todos los elementos de la lista.
     * No destruye los elementos, solo los elimina de la lista.
     */
    virtual void clearCollection() = 0;

    virtual ~ICollection();
};

#endif /* _ICOLLECTION_H */

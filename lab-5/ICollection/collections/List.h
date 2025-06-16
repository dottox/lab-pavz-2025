#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

/**
 *  Una lista comun
 */
class List : public ICollection
{
private:
    ListNode *head;
    int size;

public:
    List();

    /**
     * Agrega un elemento a la coleccion al final de la lista.
     * Si ya existia no hace nada
     */
    void add(ICollectible *);

    /**
     * Borra el elementvoid remove(ICollectible *);o de la coleccion.
     * Si no existe no hace nada
     */
    void remove(ICollectible *);

    /**
     * Setea a null el element void setNull(ICollectible *);o de la colección.
     * Si no existe no hace nada
     */
    void setNull(ICollectible *);

    /*
     * Devuelve true si hay un elemento en la coleccion cuya direccion de memoria
     * coincide con el argumente
     */
    bool member(ICollectible *) const;

    /*
     * Devuelve true si size() es 0
     */
    bool isEmpty() const;

    /**
     * Devuelve el tamano de la coleccion
     */
    int getSize() const;

    /*
     * Devuelve una instancia de IIterator creada con el operador new,
     * El orden de la iteracion respeta el orden de insercion de los elementos
     */
    IIterator *getIterator();

    /**
     * Limpia la colección, seteando a null todos los elementos de la lista.
     * No destruye los elementos, solo los elimina de la lista.
     */
    void clearCollection();

    /**
     * Destruye la lista (pero no sus elementos)
     */
    virtual ~List();
};

#endif /* LIST_H */

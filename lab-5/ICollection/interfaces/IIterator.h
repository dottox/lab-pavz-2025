#include "ICollectible.h"


#ifndef _IITERATOR_H
#define	_IITERATOR_H

/** 
 * Interfaz de iteradores
 */ 
class IIterator{
public:
    /**
     *  Devuelve el actual elemento de la coleccion en la iteracion.
     *  Tira una excepcion out_of_range si no hay tal elemento
     */
    virtual ICollectible *getCurrent() = 0;

    /*
     *  Devuelve true si hay un elemento en la coleccion. 
     */
    virtual bool hasCurrent() = 0;
    
    /*
     *  Hace un paso en la iteracion. Si hasCurrent() es false
     *  tira excepcion out_of_range
     */
    virtual void next() = 0;
        
    virtual ~IIterator();
};

#endif	/* _IITERATOR_H */


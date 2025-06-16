#ifndef _ICOLLECTIBLE_H
#define	_ICOLLECTIBLE_H

/**
 *  Elemento de la coleccion
 */
class ICollectible
{
protected:
    /*
     * No se permite instanciar ICollectible directamente
     */
    ICollectible();
public:
    virtual ~ICollectible();
};

#endif	/* _ICOLLECTIBLE_H */


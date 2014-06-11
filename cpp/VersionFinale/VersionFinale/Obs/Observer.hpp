/*!
  * \class Observer
  * \brief Implémentation pattern Observer : côté observeur
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see Observable
  */


#ifndef OBSERVER
#define OBSERVER

class Observer
{
public:
    /**
      * \fn void virtual update()
      * \brief Met à jour la vue des informations sur l'IHM. Devra être réimplémentée dans les classes filles.
    */
    void virtual update();

    /**
          * \fn virtual void setSommet(void* s)
          * \brief Remet à jour le sommet dans la classe. Sert uniquement dans la classe fille, où la méthode est réimplémentée.
          * \see ArbreItemSommet
          * \see XMLElementSommet
        */
    virtual void setSommet(void*);
    /**
          * \fn virtual void setArete(void* a)
          * \brief Remet à jour l'arête dans la classe. Sert uniquement dans la classe fille, où la méthode est réimplémentée.
          * \see ArbreItemArete
          * \see XMLElementArete
        */
    virtual void setArete(void*);
};

#endif

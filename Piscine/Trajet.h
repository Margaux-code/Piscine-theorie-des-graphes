#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include <iostream>
#include "Points.h"
#include <string>

class Trajet
{
private :
    Point m_depart;
    Point m_arrivee;
    int m_durée;
    std::string typeTransport;

public:
    Trajet();
   ~Trajet();

   Point getDepart() const;

   Point getArrivee()const;

    int getDuree() const;
    int setDuree(int duree);

    std::string getTransport() const;
};


#endif // TRAJET_H_INCLUDED

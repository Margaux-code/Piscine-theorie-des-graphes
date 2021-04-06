#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include <iostream>
#include <string>
#include "Points.h"

class Trajet
{
private :
    Point m_depart;
    Point m_arrivee;
    double m_durée;
    std::string typeTransport;

public:
    Trajet();
   ~Trajet();

   Point getDepart() const;

   Point getArrivee()const;

    double getDuree() const;
    double setDuree(double duree);

    std::string getTransport() const;
};


#endif // TRAJET_H_INCLUDED

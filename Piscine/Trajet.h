#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include <iostream>
#include <string>
#include "Points.h"

class Trajet
{
private :
    std::string m_nomTrajet;
    int m_valArrivee;
    int m_valDepart;
    double m_duree;
    Point m_depart;
    Point m_arrivee;
    std::string m_typeTransport;
public:
    Trajet();
   ~Trajet();

   Trajet(std::string nomTrajet, int valArrivee, int valDepart, std::string typeTransport);
   void setPoints(std::vector<Point> liste_Points);
    int getDepart();
    int getArrivee();
    std::string getNomTrajet();

    double getDuree() const;
    void setDuree();
    Point getPointDepart();
    Point getPointArrivee();
    std::string getTransport() const;
};


#endif // TRAJET_H_INCLUDED

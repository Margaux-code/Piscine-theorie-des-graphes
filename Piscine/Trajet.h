#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED


#include "Points.h"

class Trajet
{
private :

    std::string m_nomTrajet;
    int m_valArrivee;
    int m_valDepart;
    int m_numTrajet;
    double m_duree;
    Point m_depart;
    Point m_arrivee;
    std::string m_typeTransport;

public:

    Trajet();
   ~Trajet();

   Trajet(int numTrajet,std::string nomTrajet, int valArrivee, int valDepart, std::string typeTransport);
   void setPoints(std::vector<Point> liste_Points);
    int getDepart();
    int getArrivee();
    std::string getNomTrajet();

    double getDuree() const;
    void setDuree();
    void setDureeSki(double duree);
    Point getPointDepart();
    Point getPointArrivee();
    std::string getTransport() const;
    int getNumTrajet();
};


#endif // TRAJET_H_INCLUDED

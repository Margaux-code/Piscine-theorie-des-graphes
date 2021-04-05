#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED

#include <iostream>

class Point
{
private:
    std::string m_nom;
    std::vector<Trajet> m_arrivees;
    std::vector<Trajet> m_departs;

public :

    ~Point();

    Point();

    std::string getNom() const;
    std::string setNom(std::string nom);

    std::vector<Trajet> getArrivees() const;

    std::vector<Trajet> getDeparts() const;


};

#endif // POINTS_H_INCLUDED

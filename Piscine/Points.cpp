#include "Points.h"

Point::Point() {}

Point::~Point() {}

std::string Point::getNom()
{
    return m_nom;
}
std::string Point::setNom(std::string nom)
{
    m_nom = nom;
}

std::vector<Trajet> Point::getArrivees() const
{
    return m_arrivees;
}

std::vector<Trajet> Point::getDeparts() const
{
    return m_departs;
}

double Point::getAltitude() const
{
    return m_altitude;
}

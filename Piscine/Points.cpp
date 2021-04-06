#include "Points.h"

Point::Point() {}

Point::~Point() {}

Point::Point(int numPoint, std::string nom, double altitude)
{
    m_numPoint = numPoint;
    m_nom = nom;
    m_altitude = altitude;
}


std::string Point::getNom() const
{
    return m_nom;
}
void Point::setNom(std::string nom)
{
    m_nom = nom;
}

double Point::getAltitude() const
{
    return m_altitude;
}

void Point::setAltitude(double altitude)
{
    m_altitude = altitude;
}

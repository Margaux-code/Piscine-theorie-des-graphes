#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>

class Point
{
private:
    std::string m_nom;
    double m_altitude;
    int m_numPoint;

public :

    ~Point();
    Point();

    Point(int numPoint, std::string nom, double altitude);
    std::string getNom() const;
    void setNom(std::string nom);
    double getAltitude() const;
    void setAltitude(double altitude);
    int getNumPoint();
};

#endif // POINTS_H_INCLUDED

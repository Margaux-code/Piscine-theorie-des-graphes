#include "Points.h"

Point::Point() {}

Point::~Point() {}

Point::Point(int numPoint, std::string nom, double altitude)
{
    m_numPoint = numPoint;
    m_nom = nom;
    m_altitude = altitude;
}

  void Point::setBool(bool marque)
  {
      m_marque = marque;
  }

   void Point::setChemin(double chemin)
   {
       m_chemin=chemin;
   }

    double Point::getChemin()
    {
        return m_chemin;
    }

      bool Point::getBool()
      {
          return m_marque;
      }
void Point::setPredecesseur(double pred)
{
    m_num_Predecesseur= pred;
}
    double Point::getPredecesseur()
    {
        return m_num_Predecesseur;
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

 int Point::getNumPoint()
 {
     return m_numPoint;
 }

 void Point::setNumPoint(int nvNumPoint)
 {
     m_numPoint = nvNumPoint;
 }

 ///Méthodes pour le BFS
 void Point::setCouleur(bool noir)
 {
     m_color = noir;
 }
 bool Point::getCouleur()const
 {
     return m_color;
 }

std::vector<Point> Point::getAdj()
{
    return m_adjacents;
}

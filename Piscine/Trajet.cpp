#include "Trajet.h"

Trajet::Trajet() {}
Trajet::~Trajet() {}

int Trajet::getDepart()
{
    return m_valDepart;
}

int Trajet::getArrivee()
{
    return m_valArrivee;
}

Trajet::Trajet(std::string nomTrajet, int valDepart, int valArrivee, std::string typeTransport)
{
    m_nomTrajet = nomTrajet;
    m_valArrivee = valArrivee;
    m_valDepart = valDepart;
    m_typeTransport = typeTransport;
}
 void Trajet::setPoints(std::vector<Point> liste_Points)
 {
     for(int i =0; i<liste_Points.size();i++)
     {
         if (liste_Points[i].getNumPoint() == m_valDepart)
         {
             m_depart=liste_Points[i];
         }
          if (liste_Points[i].getNumPoint() == m_valArrivee)
         {
             m_arrivee=liste_Points[i];
         }
     }

 }



double Trajet::getDuree() const
{
    return m_duree;
}
void Trajet::setDuree()
{
   int Altitude1 = m_depart.getAltitude();
   int Altitude2 = m_arrivee.getAltitude();
   int denivele = abs(Altitude1-Altitude2);
   denivele = denivele/100;
    if(m_typeTransport.compare("V") == 0)
        m_duree = denivele*5;
    if(m_typeTransport.compare("B") == 0)
          m_duree = denivele*4;
    if(m_typeTransport.compare("R") == 0)
            m_duree = denivele*3;
   if(m_typeTransport.compare("N") == 0)
         m_duree = denivele*2;
    if(m_typeTransport.compare("KL") == 0)
        m_duree = denivele *(1/6);
    if(m_typeTransport.compare("SURF") == 0)
         m_duree = denivele*10;
    if(m_typeTransport.compare("TPH") == 0)
         m_duree = denivele*2+4;
    if(m_typeTransport.compare("TC") == 0)
         m_duree = denivele*3+2;
    if(m_typeTransport.compare("TSD") == 0)
         m_duree = denivele*3+1;
    if(m_typeTransport.compare("TS") == 0)
        m_duree = denivele*4+1;
    if(m_typeTransport.compare("TK") == 0)
        m_duree = denivele*4+1;
    if(m_typeTransport.compare("BUS") == 0)
        m_duree = 30;
}

std::string Trajet::getTransport() const
{
    return m_typeTransport;
}

std::string Trajet::getNomTrajet()
{
    return m_typeTransport;
}

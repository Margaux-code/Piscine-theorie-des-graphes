#include "Trajet.h"

Trajet::Trajet() {}
Trajet::~Trajet() {}

Trajet::Trajet(std::string nomTrajet, int valDepart, int valArrivee, std::string typeTransport)
{
    m_nomTrajet = nomTrajet;
    m_valArrivee = valArrivee;
    m_valDepart = valDepart;
    m_typeTransport = typeTransport;
}

double Trajet::getDuree() const
{
    return m_duree;
}
void Trajet::setDuree(double duree)
{
    m_duree = duree;
}

std::string Trajet::getTransport() const
{
    return m_typeTransport;
}

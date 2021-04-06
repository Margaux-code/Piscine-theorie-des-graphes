#include "Graphe.h"


///Faire la récup des infos du fichier !







///Faire l'éventuel affichage (fonctionnalité) des éléments du Graphe
Graphe::~Graphe() {}

void Graphe::affichage()
{

}

std::vector<Point> Graphe::rendre_listeP()
{
    return m_points;
}

std::vector<Trajet> Graphe::rendre_listeT()
{
    return m_trajets;
}

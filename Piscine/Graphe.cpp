#include "Graphe.h"


///Faire la r�cup des infos du fichier !







///Faire l'�ventuel affichage (fonctionnalit�) des �l�ments du Graphe
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

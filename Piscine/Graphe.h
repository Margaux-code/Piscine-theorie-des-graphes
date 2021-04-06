#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include "Points.h"
#include "Trajet.h"

class Graphe
{
private :
    std::vector<Point> m_points;
    std::vector<Trajet> m_trajets;
public :
    Graphe(std::string nomfichier);

    ~Graphe();

    //void affichage();

    std::vector<Point> rendre_listeP();
    std::vector<Trajet> rendre_listeT();


};

#endif // GRAPHE_H_INCLUDED

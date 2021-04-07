#include "Graphe.h"


///Faire la récup des infos du fichier !
Graphe::Graphe(std::string nomfichier)
{
    std::ifstream ifs{nomfichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomfichier );
    int ordre;
    ifs >> ordre;      //récupération de l'ordre du graphe
    for(int i = 0 ; i < ordre ; i++)
    {
        std::string nom;
        double altitude;
        int val;
        ifs >> val >> nom >> altitude;
        Point n(val, nom, altitude);
        m_points.push_back(n);
    }
    int taille;
    ifs >> taille;
    for(int i = 0; i < taille ; i++)
    {
        std::string nomTrajet;
        std::string typeTransport;
        int valDepart, valArrivee, val;
        ifs >> val >> nomTrajet >> typeTransport >> valDepart >> valArrivee;
        Trajet n(nomTrajet,valArrivee, valDepart, typeTransport);
        m_trajets.push_back(n);

    }
}

///Faire l'éventuel affichage (fonctionnalité) des éléments du Graphe
Graphe::~Graphe() {}

/*void Graphe::affichage()
{

}*/

std::vector<Point> Graphe::rendre_listeP()
{
    return m_points;
}

std::vector<Trajet> Graphe::rendre_listeT()
{
    return m_trajets;
}

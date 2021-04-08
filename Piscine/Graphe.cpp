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
        Trajet n(nomTrajet,valDepart, valArrivee, typeTransport);
        n.setPoints(m_points);
        n.setDuree();
        m_trajets.push_back(n);
    }
    for(auto p : m_points)
    {
        std::cout << "num point : " << p.getNumPoint() << std::endl;
        std::cout << "Nom du point : " << p.getNom() << std::endl;
        std::cout << "Altitude du point : " << p.getAltitude() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    for(auto t : m_trajets)
    {
        std::cout << "num du point depart : " << t.getDepart() << std::endl;
        std::cout << "Num du point d'arrivee: " << t.getArrivee() << std::endl;
        std::cout << "Nom du trajet : " << t.getNomTrajet() << std::endl;
        std::cout << "Nom du type de transport : " << t.getTransport() << std::endl;
        std::cout << std::endl;
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

std::vector<Point> Graphe::BFS()
{
    int valSommetDepart;
    std::queue<Point> file;
    Point point;
    std::vector<Point> vectPredecesseurs;

    std::cout << "entrez le sommet de depart d'etude entre 1 et 37) de la station afin" << std::endl << "de trouver les chemins les plus courts pour atteindre l'ensemble des points :" << std::endl;
    do
    {
        std::cin >>valSommetDepart;
    }
    while(valSommetDepart < 1 || valSommetDepart > 37);

    for(auto elem : m_points)
        elem.setCouleur(false);
    for(int i = 0 ; i < 37 ; i++)
    {
        vectPredecesseurs.push_back(point);
    }

    Point pointOrigine = m_points[valSommetDepart - 1];

    file.push(pointOrigine);
    m_points[valSommetDepart - 1].setCouleur(true);
    while(!file.empty())
    {
        Point debut = file.front();
        file.pop();
        debut = m_points[debut.getNumPoint() - 1];
        for(auto elem : debut.getAdj())
        {
            if(m_points[elem.getNumPoint() - 1].getCouleur() == false)
            {
                file.push(elem);
                m_points[elem.getNumPoint() - 1].setCouleur(true);
                vectPredecesseurs[elem.getNumPoint() - 1].setNumPoint(debut.getNumPoint());
            }
        }
    }
    return vectPredecesseurs;
}

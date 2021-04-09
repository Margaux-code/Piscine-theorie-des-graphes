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
        Trajet n(val, nomTrajet, valDepart, valArrivee, typeTransport);
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
        std::cout << "num du Trajet : " << t.getNumTrajet() << std::endl;
        std::cout << "num du point depart : " << t.getDepart() << std::endl;
        std::cout << "Num du point d'arrivee: " << t.getArrivee() << std::endl;
        std::cout << "Nom du trajet : " << t.getNomTrajet() << std::endl;
        std::cout << "Nom du type de transport : " << t.getTransport() << std::endl;
        std::cout << std::endl;
    }
}

Graphe::~Graphe() {}

std::vector<Point> Graphe::rendre_listeP()
{
    return m_points;
}

std::vector<Trajet> Graphe::rendre_listeT()
{
    return m_trajets;
}

void Graphe::BFS(int choixAffichage)
{
    int valSommetDepart;
    std::queue<Point> file;
    Point point;
    std::cout << "entrez le sommet de depart d'etude entre 1 et 37 de la station afin" << std::endl << "de trouver les chemins les plus courts pour atteindre l'ensemble des points :" << std::endl;
    do
    {
        std::cin >>valSommetDepart;
    }
    while(valSommetDepart < 1 || valSommetDepart > 37);

    for(auto& elem : m_points)
    {
        elem.setCouleur(0);
        elem.setBFS(-1);
    }
    file.push(m_points[valSommetDepart - 1]); //On push le Point de départ
    m_points[valSommetDepart - 1].setCouleur(1); //On considère le point de départ comme traité
    while(!file.empty()) //Tant que la file n'est pas vide...
    {
        Point debut = file.front(); //On récupère le premier élément de la file
        //debut = m_points[debut.getNumPoint() - 1];
        for(auto elem : m_trajets)
        {
            if(elem.getPointDepart().getNumPoint() == debut.getNumPoint())
            {
                if(m_points[elem.getPointArrivee().getNumPoint() - 1].getCouleur() == 0)
                {
                    file.push(elem.getPointArrivee());
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setCouleur(1);
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setBFS(debut.getNumPoint());
                }
            }
        }
        file.pop(); //On retire le premier élément de la file
        m_points[debut.getNumPoint() - 1].setCouleur(2);
    }
    //Affichage du BFS
    if(choixAffichage == 1)
    {
        system("cls");
        std::cout << "Trajets suivant le moins de pistes et remontes a partir du point " << valSommetDepart << std::endl << "pour atteindre tous les autres points de la station des Arcs" << std::endl;
        for(int i=1; i < m_points.size() + 1; i++)
        {
            int anteBfs = m_points[i - 1].getBFS();//on recupere le predecesseur de chaque sommet
            if(anteBfs!=(-1))//si le sommet a des prédecesseur
            {
                std::cout<<m_points[i - 1].getNumPoint(); // on écrit le sommet
                while(true)
                {
                    if(anteBfs!=(-1))   // si le bfs n'est pas égal a -1
                    {
                        std::cout<<" <-- "<< anteBfs;   // on écrit le result
                        anteBfs= m_points[anteBfs - 1].getBFS();//on recupere le predecesseur de chaque sommet
                    }
                    else break;
                }
                std::cout<<std::endl;
            }
        }
        std::cout<<"----------------------------"<<std::endl;
    }
    if(choixAffichage == 2)
    {
        int pointFinal;
        std::cout << "entrez le sommet d'arrive entre 1 et 37 de la station" << std::endl;
        do
        {
            std::cin >>pointFinal;
        }
        while(pointFinal < 1 || pointFinal > 37);
        system("cls");
        std::cout << "Trajet suivant le moins de pistes et remontes" << std::endl;
        int anteBfs = m_points[pointFinal - 1].getBFS();//on recupere le predecesseur de chaque sommet
        if(anteBfs!=(-1))//si le sommet a des prédecesseur
        {
            std::cout<<m_points[pointFinal - 1].getNumPoint(); // on écrit le sommet
            while(true)
            {
                if(anteBfs!=(-1))   // si le bfs n'est pas égal a -1
                {
                    std::cout<<" <-- "<< anteBfs;   // on écrit le result
                    anteBfs= m_points[anteBfs - 1].getBFS();//on recupere le predecesseur de chaque sommet
                }
                else break;
            }
            std::cout<<std::endl;
        }
    std::cout<<"----------------------------"<<std::endl;
    }
}

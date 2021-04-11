#include "Graphe.h"
#include "Menu.h"

///Méthode de chargement du fichier et de remplissage de l'objet g de type Graphe à partir des informations récupérées
Graphe::Graphe(std::string nomfichier)
{
    std::ifstream ifs{nomfichier}; //Ouverture du fichier
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomfichier );
    int ordre;
    ifs >> ordre;      //récupération de l'ordre du graphe
    for(int i = 0 ; i < ordre ; i++)
    {
        std::string nom;
        double altitude;
        int val;
        ifs >> val >> nom >> altitude; //Récupération des caractéristiques des points du graphe
        Point n(val, nom, altitude);
        m_points.push_back(n); //Remplissage au fur et à mesure du vecteur de Points de la classe Graphe
    }
    int taille;
    ifs >> taille; //Récupération de la taille du graphe
    for(int i = 0; i < taille ; i++)
    {
        std::string nomTrajet;
        std::string typeTransport;
        int valDepart, valArrivee, val;
        ifs >> val >> nomTrajet >> typeTransport >> valDepart >> valArrivee; //Récupération des caractéristiques des trajets du fichier
        Trajet n(val, nomTrajet, valDepart, valArrivee, typeTransport);
        n.setPoints(m_points);
        n.setDuree();
        m_trajets.push_back(n); //Remplissage du vecteur de Trajets de la class Graphe
    }
    /// éléments permettants l'affichage du fichier si besoin est
    /*for(auto p : m_points)
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
    }*/
}

//Destructeur
Graphe::~Graphe() {}

///getters des vecteurs
std::vector<Point> Graphe::rendre_listeP()
{
    return m_points;
}

std::vector<Trajet> Graphe::rendre_listeT()
{
    return m_trajets;
}

///Méthode Faisant tourner et afficher l'algorithme de Breadth First Search
///Aidé par Nicolas Dreyfus et Aurélien Bon du TD1 et Gioia Mariasole Galiazzo du TD6

void Graphe::BFS(int choixAffichage)
{
    int valSommetDepart;
    //Création de la file du BFS
    std::queue<Point> file;
    Point point;
    gotoligcol(1,0);
    PutCouleur(4,0);
    std::cout << "Entrez le sommet de depart d'etude entre 1 et 37 de la station afin de trouver les chemins les plus courts pour atteindre l'ensemble des points :" << std::endl<< std::endl;
    PutCouleur(15,0);
    do //Boucle de blindage
    {
        std::cin >>valSommetDepart; //Récupération du sommet de départ
    }
    while(valSommetDepart < 1 || valSommetDepart > 37); //Conditions de la boucle de blindage

    for(auto& elem : m_points) //Boucle utilisant les setter pour initialiser le bfs
    {
        elem.setCouleur(0);
        elem.setBFS(-1);
    }
    file.push(m_points[valSommetDepart - 1]); //On push le Point de départ
    m_points[valSommetDepart - 1].setCouleur(1); //On considère le point de départ comme en cours d'étude
    while(!file.empty()) //Tant que la file n'est pas vide...
    {
        Point debut = file.front(); //On récupère le premier élément de la file
        //debut = m_points[debut.getNumPoint() - 1];
        for(auto elem : m_trajets) //Boucle faisant tourner le vecteur de trajets
        {
            if(elem.getPointDepart().getNumPoint() == debut.getNumPoint()) //Test pour déterminer si le point du vecteur est le même que celui présent en haut de la file
            {
                if(m_points[elem.getPointArrivee().getNumPoint() - 1].getCouleur() == 0) //Test pour déterminer si le point n'a pas encore été étudié
                {
                    file.push(elem.getPointArrivee()); //Push le point d'arrivée du trajet étudié dans la file
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setCouleur(1); //On considère le point comme en cours d'étude
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setBFS(debut.getNumPoint());
                }
            }
        }
        file.pop(); //On retire le premier élément de la file
        m_points[debut.getNumPoint() - 1].setCouleur(2); //On tag le point comme étant étudié
    }
    //Affichage du BFS
    if(choixAffichage == 1) //Si à partir du menu il est demandé d'afficher l'ensemble des trajets pour l'ensemble des points à partir d'un point de départ
    {
        system("cls");
        gotoligcol(1,0);
        PutCouleur(3,0);
        std::cout << "Trajets suivant le moins de pistes et remontes a partir du point " << valSommetDepart << std::endl << "pour atteindre tous les autres points de la station des Arcs" << std::endl;
        for(unsigned int i=1; i < m_points.size() + 1; i++)
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
    if(choixAffichage == 2) //Si à partir du menu il est demandé d'afficher le trajet pour un point de départ précis, et un point d'arrivé précis
    {
        int pointFinal;
        PutCouleur(4,0);
        std::cout << std::endl << "Entrez le sommet d'arrive entre 1 et 37 de la station." << std::endl<< std::endl;
        PutCouleur(15,0);
        do //boucle de blindage
        {
            std::cin >>pointFinal; //récupération du numéro du point d'arrivée
        }
        while(pointFinal < 1 || pointFinal > 37); //conditions de la boucle de blindage
        system("cls");
        gotoligcol(1,0);
        PutCouleur(3,0);
        std::cout << "Trajet suivant le moins de pistes et remontees." << std::endl;
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
    std::cout<<std::endl;
    }
}

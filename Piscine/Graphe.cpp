#include "Graphe.h"

///M�thode de chargement du fichier et de remplissage de l'objet g de type Graphe � partir des informations r�cup�r�es
Graphe::Graphe(std::string nomfichier)
{
    std::ifstream ifs{nomfichier}; //Ouverture du fichier
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomfichier );
    int ordre;
    ifs >> ordre;      //r�cup�ration de l'ordre du graphe
    for(int i = 0 ; i < ordre ; i++)
    {
        std::string nom;
        double altitude;
        int val;
        ifs >> val >> nom >> altitude; //R�cup�ration des caract�ristiques des points du graphe
        Point n(val, nom, altitude);
        m_points.push_back(n); //Remplissage au fur et � mesure du vecteur de Points de la classe Graphe
    }
    int taille;
    ifs >> taille; //R�cup�ration de la taille du graphe
    for(int i = 0; i < taille ; i++)
    {
        std::string nomTrajet;
        std::string typeTransport;
        int valDepart, valArrivee, val;
        ifs >> val >> nomTrajet >> typeTransport >> valDepart >> valArrivee; //R�cup�ration des caract�ristiques des trajets du fichier
        Trajet n(val, nomTrajet, valDepart, valArrivee, typeTransport);
        n.setPoints(m_points);
        n.setDuree();
        m_trajets.push_back(n); //Remplissage du vecteur de Trajets de la class Graphe
    }
    /// �l�ments permettants l'affichage du fichier si besoin est
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

///M�thode Faisant tourner et afficher l'algorithme de Breadth First Search
///Aid� par Nicolas Dreyfus et Aur�lien Bon du TD1 et Gioia Mariasole Galiazzo du TD6

void Graphe::BFS(int choixAffichage)
{
    int valSommetDepart;
    //Cr�ation de la file du BFS
    std::queue<Point> file;
    Point point;
    std::cout << "entrez le sommet de depart d'etude entre 1 et 37 de la station afin" << std::endl << "de trouver les chemins les plus courts pour atteindre l'ensemble des points :" << std::endl;
    do //Boucle de blindage
    {
        std::cin >>valSommetDepart; //R�cup�ration du sommet de d�part
    }
    while(valSommetDepart < 1 || valSommetDepart > 37); //Conditions de la boucle de blindage

    for(auto& elem : m_points) //Boucle utilisant les setter pour initialiser le bfs
    {
        elem.setCouleur(0);
        elem.setBFS(-1);
    }
    file.push(m_points[valSommetDepart - 1]); //On push le Point de d�part
    m_points[valSommetDepart - 1].setCouleur(1); //On consid�re le point de d�part comme en cours d'�tude
    while(!file.empty()) //Tant que la file n'est pas vide...
    {
        Point debut = file.front(); //On r�cup�re le premier �l�ment de la file
        //debut = m_points[debut.getNumPoint() - 1];
        for(auto elem : m_trajets) //Boucle faisant tourner le vecteur de trajets
        {
            if(elem.getPointDepart().getNumPoint() == debut.getNumPoint()) //Test pour d�terminer si le point du vecteur est le m�me que celui pr�sent en haut de la file
            {
                if(m_points[elem.getPointArrivee().getNumPoint() - 1].getCouleur() == 0) //Test pour d�terminer si le point n'a pas encore �t� �tudi�
                {
                    file.push(elem.getPointArrivee()); //Push le point d'arriv�e du trajet �tudi� dans la file
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setCouleur(1); //On consid�re le point comme en cours d'�tude
                    m_points[elem.getPointArrivee().getNumPoint() - 1].setBFS(debut.getNumPoint());
                }
            }
        }
        file.pop(); //On retire le premier �l�ment de la file
        m_points[debut.getNumPoint() - 1].setCouleur(2); //On tag le point comme �tant �tudi�
    }
    //Affichage du BFS
    if(choixAffichage == 1) //Si � partir du menu il est demand� d'afficher l'ensemble des trajets pour l'ensemble des points � partir d'un point de d�part
    {
        system("cls");
        std::cout << "Trajets suivant le moins de pistes et remontes a partir du point " << valSommetDepart << std::endl << "pour atteindre tous les autres points de la station des Arcs" << std::endl;
        for(unsigned int i=1; i < m_points.size() + 1; i++)
        {
            int anteBfs = m_points[i - 1].getBFS();//on recupere le predecesseur de chaque sommet
            if(anteBfs!=(-1))//si le sommet a des pr�decesseur
            {
                std::cout<<m_points[i - 1].getNumPoint(); // on �crit le sommet
                while(true)
                {
                    if(anteBfs!=(-1))   // si le bfs n'est pas �gal a -1
                    {
                        std::cout<<" <-- "<< anteBfs;   // on �crit le result
                        anteBfs= m_points[anteBfs - 1].getBFS();//on recupere le predecesseur de chaque sommet
                    }
                    else break;
                }
                std::cout<<std::endl;
            }
        }
        std::cout<<"----------------------------"<<std::endl;
    }
    if(choixAffichage == 2) //Si � partir du menu il est demand� d'afficher le trajet pour un point de d�part pr�cis, et un point d'arriv� pr�cis
    {
        int pointFinal;
        std::cout << "entrez le sommet d'arrive entre 1 et 37 de la station" << std::endl;
        do //boucle de blindage
        {
            std::cin >>pointFinal; //r�cup�ration du num�ro du point d'arriv�e
        }
        while(pointFinal < 1 || pointFinal > 37); //conditions de la boucle de blindage
        system("cls");
        std::cout << "Trajet suivant le moins de pistes et remontes" << std::endl;
        int anteBfs = m_points[pointFinal - 1].getBFS();//on recupere le predecesseur de chaque sommet
        if(anteBfs!=(-1))//si le sommet a des pr�decesseur
        {
            std::cout<<m_points[pointFinal - 1].getNumPoint(); // on �crit le sommet
            while(true)
            {
                if(anteBfs!=(-1))   // si le bfs n'est pas �gal a -1
                {
                    std::cout<<" <-- "<< anteBfs;   // on �crit le result
                    anteBfs= m_points[anteBfs - 1].getBFS();//on recupere le predecesseur de chaque sommet
                }
                else break;
            }
            std::cout<<std::endl;
        }
    std::cout<<"----------------------------"<<std::endl;
    }
}

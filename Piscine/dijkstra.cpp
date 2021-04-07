#include "Graphe.h"
#include "header.h"
std::vector<Point> Trouver_chemin(int debut, int arrivee,std::vector<Point> TousPoints)
{

    std::vector<Point> Chemin;
    Point actuel;
    for (int i=0; i<TousPoints.size(); i++)
    {
        if (TousPoints[i].getNumPoint()==arrivee)
        {
            actuel = TousPoints[i];
            Chemin.push_back(actuel);
        }
    }

    while (actuel.getNumPoint()!= debut)
    {
        int predecesseur = actuel.getPredecesseur();
        for (int i=0; i<TousPoints.size(); i++)
        {
            if (TousPoints[i].getNumPoint()==predecesseur)
            {
                actuel = TousPoints[i];
                Chemin.push_back(actuel);
            }
        }

    }


return Chemin;

}

void afficher_chemin(std::vector<Point> Chemin_final)
{
     int fin;
    std::cout<< "Le chemin a prendre est :" << std::endl;
    for (int i=0; i<Chemin_final.size();i++)
    {
        std::cout << Chemin_final[i].getNom() << "->";
      fin =i;
    }
    std::cout<<std::endl;
    std::cout <<"Le temps que cela va prendre est " << Chemin_final[fin].getChemin() <<"minutes" <<std::endl;
}


std::vector <Point> dijkstra(int debut, int arrivee,std::vector<Point> TousPoint, std::vector<Trajet> TousTrajets)
{
    //initialiser une file d'attente
    std::vector<std::pair< Point, double>> file_attente;
std::vector<Point> TousPoints = TousPoint;
    for(int i=0; i<TousPoints.size(); i++)
    {
        TousPoints[i].setBool(false);
        TousPoints[i].setChemin(100000);
        if (TousPoints[i].getNumPoint()==debut)
        {
            TousPoints[i].setChemin(0);
            std::pair<Point,double> tampon(TousPoints[i], 0);
            file_attente.push_back(tampon);
        }
    }
///Boucle principale de l'algorithme
    while(!file_attente.empty())
    {

        //Recuperer la distance la plus interessante de la file d'attente
        // La plus interressante est la plus courte
        int interressante =100000; // Valeur arbitrairement grande pour que n'importe quelle valeur soit plus petite
        int actuelle;
        int numero_sommet;
        for (int i=0; i< file_attente.size(); i++ ) //Demander à ben comment marche cette fonction
        {
            actuelle = file_attente[i].second;
            if (actuelle < interressante)
            {
                interressante =actuelle;
                numero_sommet = i;

            }
        }
        //Marquer le sommet récuperer comme true car on est en train de l'explorer
        for (int i =0;i<TousPoints.size();i++)
        {
            if (file_attente[numero_sommet].first.getNumPoint()==TousPoints[i].getNumPoint())
            {

                TousPoints[i].setBool(true);

            }
        }

    int place;
//Recuperer tous les antecedents grâce aux trajets puis les rajouter dans la file d'attente si leur booléen est faux
        for(int i=0; i< TousTrajets.size(); i++)
        {
            if (TousTrajets[i].getDepart() == file_attente[numero_sommet].first.getNumPoint())
            {
                Point successeur = TousTrajets[i].getPointArrivee();
                for (int j=0; j< TousPoints.size();j++)
                {
                    if (TousPoints[j].getNumPoint()==successeur.getNumPoint())
                    {
                        place=j;
                    }

                }
                Point toto = TousPoints[place];
                bool bouboul = TousPoints[place].getBool();
                if (bouboul == false)
                {
                    //Calcul de la durée
                        int chemin = TousTrajets[i].getDuree() + file_attente[numero_sommet].first.getChemin();
                        if (chemin < TousPoints[place].getChemin())
                        {
                            TousPoints[place].setChemin(chemin);
                                       //Marque qui est le predecesseur
                        int predecesseur =file_attente[numero_sommet].first.getNumPoint();
                        TousPoints[place].setPredecesseur(predecesseur);
                        }
                        //Mettre dans la file d'attente
                        std::pair<Point,double> buffer(TousPoints[place], chemin);
                        file_attente.push_back(buffer);

                }
            }
        }


        file_attente.erase(file_attente.begin()+ numero_sommet);

    }
    std::vector<Point> Chemin_final = Trouver_chemin(debut, arrivee,TousPoints);
    afficher_chemin(Chemin_final);
    return Chemin_final;
}

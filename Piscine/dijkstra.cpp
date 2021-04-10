#include "Graphe.h"
#include "header.h"
#include "Menu.h"
#include "Points.h"
#include <iostream>
#include <windows.h>

void debut_dikjstra( std::vector<Point> points, std::vector<Trajet> trajets)
{
    std::cout <<" Choisissez votre point de depart "<<std::endl;
    int depart;
    std::cin >> depart;
    std::cout << "Choisissez votre point arrivee" <<std::endl;
    int arrivee;
    std::cin >> arrivee;
    std::vector <Point> chemin = dijkstra( depart,arrivee,points,trajets);
    afficher_chemin(chemin);
}


std::vector<Point> Trouver_chemin(int debut, int arrivee,std::vector<Point> TousPoints)
{

    std::vector<Point> Chemin;
    Point actuel;
    for (unsigned int i=0; i<TousPoints.size(); i++)
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
        for (unsigned int i=0; i<TousPoints.size(); i++)
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

    if (Chemin_final[0].getChemin()==100000)
    {
        PutCouleur(15,0);
        std::cout <<"Malheureusement relier ces deux points avec vos préférences n'est pas possible :( " <<std::endl;
    }
    else
    {
    PutCouleur(9,0);
        std::cout<< "Pour ce chemin il va valloir passer par ces points :" << std::endl;

        for (int i = (Chemin_final.size()-1); i>=0; i--)
        {

            std::cout <<" -> "<< Chemin_final[i].getNom() ;

        }

        std::cout << std::endl;
        std::cout<< "Pour cela il faut prendre les trajets suivants :"<<std::endl;
        for (int i = (Chemin_final.size()-1); i>=0; i--)
        {


            std::cout <<"   "<< Chemin_final[i].getNomTrajet() ;

        }
        std::cout<<std::endl;
        std::cout <<"Le temps que cela va prendre est " << Chemin_final[0].getChemin() <<" minutes" <<std::endl;

    }


}


std::vector <Point> dijkstra(int debut, int arrivee,std::vector<Point> TousPoint, std::vector<Trajet> TousTrajets)
{
    //initialiser une file d'attente
    std::vector<std::pair< Point, double>> file_attente;
    std::vector<Point> TousPoints = TousPoint;
    //Initialiser
    for(unsigned int i=0; i<TousPoints.size(); i++)
    {
        TousPoints[i].setBool(false); //Mettre tous les points comme non visiter
        TousPoints[i].setChemin(100000); // Et  mettre la distance à infini (une valeur tres grande)
        if (TousPoints[i].getNumPoint()==debut) //INitialiser le premier sommet à une distance de 0
        {
            TousPoints[i].setChemin(0);
            std::pair<Point,double> tampon(TousPoints[i], 0);
            file_attente.push_back(tampon); //Et le mettre dnas la file d'attente
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
        for (unsigned int i=0; i< file_attente.size(); i++ )
        {
            actuelle = file_attente[i].second;
            if (actuelle < interressante)
            {
                interressante =actuelle;
                numero_sommet = i;

            }
        }
        //Marquer le sommet récuperer comme true car on est en train de l'explorer
        for (unsigned int i =0; i<TousPoints.size(); i++)
        {
            if (file_attente[numero_sommet].first.getNumPoint()==TousPoints[i].getNumPoint())
            {

                TousPoints[i].setBool(true);

            }
        }

        int place;
//Recuperer tous les antecedents grâce aux trajets puis les rajouter dans la file d'attente si leur booléen est faux
        for(unsigned int i=0; i< TousTrajets.size(); i++)
        {
            if (TousTrajets[i].getDepart() == file_attente[numero_sommet].first.getNumPoint())
            {
                Point successeur = TousTrajets[i].getPointArrivee();
                for (unsigned int j=0; j< TousPoints.size(); j++)
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
                        TousPoints[place].setNomTrajet(TousTrajets[i].getNomTrajet());
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
    return Chemin_final;
}

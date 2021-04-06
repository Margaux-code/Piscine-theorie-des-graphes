#include "Graphe.h"


std::vector <Point> dijkstra(int debut, int arrivee)
{
    //Initialiser tous les sommets avec un bool�en mis a faux au d�part
    std::vector<std::pair<Point,bool>> TousSommets;
    //initialiser une file d'attente
    std::vector<std::pair< Point, double>> file_attente;
    // Initialiser une pair : avec le sommet et le chemin le plus petit pour l'atteindre
    std::vector<std::pair< Point, double>> Chemin_court;
    std::vector<std::pair < Point, Point>> Predecesseur_Antecedent;
    for(int i=0; i<TousSommets.size(); i++)
    {
        ///Remplir TousSommets quand le fichier sera l�

        TousSommets[i].second = false;
        std::pair <Point, double> tampon (TousSommets[i],100000);
        Chemin_court.push_back(tampon);
        if () ///Faire le if en fonction des num�ros du sommets quand ils seront l�
        {
            Chemin_court[i].second =0;
            file_attente.push_back(Chemin_court[i]);
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
        for (int i=0; i< file_attente.size(); i++ ) //Demander � ben comment marche cette fonction
        {
            actuelle = file_attente[i].second;
            if (actuelle < interressante)
            {
                interressante =actuelle;
                numero_sommet = i;
            }
        }


//Marquer le sommet r�cuperer comme true car on est en train de l'explor�
        for (int i =0; i<TousSommets.size(); i++) ///Attendre le numero des fichiers
        {
            if (file_attente[numero_sommet].first.)
            {

            }
        }




    }





}

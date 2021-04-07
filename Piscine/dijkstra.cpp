#include "Graphe.h"


std::vector <Point> dijkstra(int debut, int arrivee,std::vector<Point*> TousPoints, std::vector<Trajet> TousTrajets)
{
    //initialiser une file d'attente
    std::vector<std::pair< Point*, double>> file_attente;

    for(int i=0; i<TousPoints.size(); i++)
    {
      TousPoints[i]->setBool(false);
      TousPoints[i]->setChemin(100000);
        if (TousPoints[i]->getNumPoint()==debut)
        {
            TousPoints[i]->setChemin(0);
            std::pair<Point*,double> tampon(TousPoints[i], 0);
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
        double duree;
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
        file_attente[numero_sommet].first->setBool(true);




//Recuperer tous les antecedents grâce aux trajets puis les rajouter dans la file d'attente si leur booléen est faux
        for(int i=0; i< TousTrajets.size(); i++)
        {
            if (TousTrajets[i].getDepart() == file_attente[numero_sommet].first->getNumPoint())
            {
                Point successeur = TousTrajets[i].getPointArrivee();
               if (successeur.getBool() == false)
               {
                   //Calcul de la durée
                   int chemin = TousTrajets[i].getDuree() + file_attente[numero_sommet].first->getChemin();
                   if (chemin < successeur.getChemin())
                   {
                        successeur.setChemin(chemin);
                   //Marque qui est le predecesseur
                   int predecesseur =file_attente[numero_sommet].first->getNumPoint();
                   successeur.setPredecesseur(predecesseur);
                   //Mettre dans la file d'attente
                   std::pair<Point*,double> buffer(&successeur, chemin);
                   file_attente.push_back(buffer);

                   }


               }
            }
        }

    }
    
    ///Maintenant il faut récupérer le chemin grâce aux antécedents
    

}

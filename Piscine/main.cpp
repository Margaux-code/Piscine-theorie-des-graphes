#include "Graphe.h"
#include "header.h"
/*void test_dikjstra( std::vector<Point> points, std::vector<Trajet> trajets)
{
    std::cout <<"Point de depart "<<std::endl;
    int depart;
    std::cin >> depart;
    std::cout << "Point arrivee" <<std::endl;
    int arrivee;
    std::cin >> arrivee;
    std::vector<Point*> points_adresse;

    for (int i =0 ; i<points.size();i++)
    {
        Point* p = &points[i];
        points_adresse.push_back(p);
    }


    std::vector <Point> chemin = dijkstra( depart,  arrivee,points_adresse,trajets);

}
*/






int main()
{
    Graphe g{"data_arcs.txt"};
    //menu();
    std::vector<Point> points = g.rendre_listeP();
    std::vector<Trajet> trajets=g.rendre_listeT();
    //test_dikjstra(points, trajets);
    std::cout << "Bonjour  c'est Margaux" << std::endl;
    std::vector<Point> fileBFS;
    g.BFS();
    return 0;
}

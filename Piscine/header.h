#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

std::vector<Point> Trouver_chemin(int debut, int arrivee,std::vector<Point> TousPoints);
void afficher_chemin(std::vector<Point> Chemin_final);
std::vector <Point> dijkstra(int debut, int arrivee,std::vector<Point> TousPoints, std::vector<Trajet> TousTrajets);

#endif // HEADER_H_INCLUDED

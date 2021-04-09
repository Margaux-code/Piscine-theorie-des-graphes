#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "Points.h"
#include "Trajet.h"

void selection_piste(std::vector <Trajet> TousTrajets, std::vector <Point> TousPoints);

void debut_dikjstra( std::vector<Point> points, std::vector<Trajet> trajets);
std::vector<Point> Trouver_chemin(int debut, int arrivee,std::vector<Point> TousPoints);
void afficher_chemin(std::vector<Point> Chemin_final);
std::vector <Point> dijkstra(int debut, int arrivee,std::vector<Point> TousPoints, std::vector<Trajet> TousTrajets);
void afficher_noeuds(int sommet, std::vector<Point> TousPoints, std::vector <Trajet> TousTrajets);
#endif // HEADER_H_INCLUDED

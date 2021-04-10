#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <vector>
#include "Graphe.h"

void PutCouleur(int couleurTexte, int couleurFond);
void case3(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void menu();
void case1();
void case2();
void case4(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void case5(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);


#endif // MENU_H_INCLUDED

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Graphe.h"

void PutCouleur(int couleurTexte, int couleurFond);
void gotoligcol(int ligne, int colonne);
void menu();
void case1(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void case2(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void case3(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void case4(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);
void case5(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g);


#endif // MENU_H_INCLUDED

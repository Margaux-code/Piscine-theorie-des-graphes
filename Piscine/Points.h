#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>

class Point
{
private:
    std::string m_nom;
    double m_altitude;
    int m_numPoint;
    //Attributs utiles au Dijkstra
    bool m_marque;
    double m_chemin;
    int m_num_Predecesseur;
    std::string m_nom_trajet;
    //Attributs pour le BFS
    int m_color;
    std::vector<Point> m_adjacents;
    int m_bfs;
public :

    ~Point();
    Point();

    Point(int numPoint, std::string nom, double altitude);
    std::string getNom() const;
    void setNom(std::string nom);
    double getAltitude() const;
    void setAltitude(double altitude);
    int getNumPoint();
    void setNumPoint(int nvNumPoint);
    void setBool(bool marque);
    bool getBool();
    void setChemin(double chemin);
    double getChemin();
    void setPredecesseur(double pred);
    double getPredecesseur();
    void setNomTrajet(std::string tratra);
    std::string getNomTrajet();
    //Méthodes pour le BFS
    void setCouleur(int color);
    int getCouleur()const;

    void setBFS(int bfs);
    int getBFS();
};

#endif // POINTS_H_INCLUDED

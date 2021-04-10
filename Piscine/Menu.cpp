#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "header.h"
#include "Graphe.h"


COORD convertToCoord(int ligne, int colonne)
{
    COORD mycoord;

    mycoord.X = colonne;
    mycoord.Y = ligne;

    return mycoord;
}

void gotoligcol(int ligne, int colonne)
{
    COORD mycoord = convertToCoord(ligne,colonne);
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), mycoord);
}

void PutCouleur(int couleurTexte, int couleurFond)
{
    HANDLE couleur;
    couleur = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(couleur, couleurFond*16+couleurTexte);
}

void menu()
{

    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "BIENVENUE AUX ARCS";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Veuillez selectionner une des 5 fonctionnalites ci-dessous en inserant le numero associe puis en appuyant sur Entre.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "1/ Choisir un trajet";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "2/ Choisir un point";
    PutCouleur(3,0);
    gotoligcol(16,0);
    std::cout << "3/Afficher l itineraire de plus rapide" ;
    PutCouleur(3,0);
    gotoligcol(19,0);
    std::cout << "4/Afficher tous les plus courts chemins d un point" ;
    PutCouleur(3,0);
    gotoligcol(22,0);
    std::cout << "5/ Calculer le chemin le plus interessant entre deux points";
    PutCouleur(15,0);
    gotoligcol(25,0);

    int choix = 0;
    Graphe g{"data_arcs.txt"};
    std::vector<Point> points = g.rendre_listeP();
    std::vector<Trajet> trajets=g.rendre_listeT();
    do
    {
        std::cin >> choix;
    }
    while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
    switch(choix)
    {
    case 1:
        system("cls");
        case1();
        break;
    case 2:
        system("cls");
        case2();
        break;
    case 3:
        system("cls");
        case3(trajets, points, g);
        break;
    case 4:
        system("cls");
        case4(trajets, points, g);
        break;
    case 5:
        system("cls");
        case5(trajets, points, g);
        break;
    }
}

void case1()
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "Choisir un trajet";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Sur ce menu, en choisissant un trajet (piste ou remontee ou entre 2 arrets de bus), vous pouvez savoir d'ou il part et ou il arrive.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "Si vous souhaitez retourner au menu principal, entrez 1.";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "Si vous souhaitez poursuivre sur ce menu, entrez 2.";
    PutCouleur(3,0);
    gotoligcol(16,0);
    int choix_case1 = 0;
    do
    {
        std::cin >> choix_case1;
    }
    while(choix_case1!=1 && choix_case1!=2);
    switch(choix_case1)
        {
        case 1:
            menu();
            break;
        case 2:
            /*for(auto t : m_trajets)
            {
                std::cout << "num du Trajet : " << t.getNumTrajet() << std::endl;
                std::cout << "Nom du trajet : " << t.getNomTrajet() << std::endl;
                std::cout << std::endl;
                int choixTrajet = 0;
                std::cout << "Veuillez entrer le numero du trajet dont vous souhaitez connaitre l'origine et l'arrivee.";
                std::cin >> choixTrajet;
            }*/
            break;
}

void case2()
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "Choisir un trajet";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Sur ce menu, en choisissant un point, vous pouvez connaitre les trajets qui en partent et qui permettent d y arriver.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "Si vous souhaitez retourner au menu principal, entrez 1.";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "Si vous souhaitez poursuivre sur ce menu, entrez 2.";
    PutCouleur(3,0);
    gotoligcol(16,0);
    int choix_case2 = 0;
    do
    {
        std::cin >> choix_case2;
    }
    while(choix_case2!=1 && choix_case2!=2);
    switch(choix_case2)
        {
        case 1:
            menu();
            break;
        case 2:

            break;
        }
}

void case3(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "Choisir un trajet";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Sur ce menu, a partir d un point de depart, vous pouvez connaitre tous les plus courts chemins issus de ce point ainsi que leur temps.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "Si vous souhaitez retourner au menu principal, entrez 1.";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "Si vous souhaitez poursuivre sur ce menu, entrez 2.";
    PutCouleur(3,0);
    gotoligcol(16,0);
    int choix_case3 = 0;
    do
    {
        std::cin >> choix_case3;
    }
    while(choix_case3!=1 && choix_case3!=2);
    switch(choix_case3)
        {
        case 1:
            menu();
            break;
        case 2:
            std::cout << "Desormais, souhaitez-vous savoir le chemin le plus rapide en terme :" << std::endl << "2. de trajets (pistes, remontees mecaniques, bus) ?" << std::endl << "1. de temps ?" << std::endl;
            int choixAlgo = 0;
            do
            {
                std::cin >> choixAlgo;
                switch(choixAlgo)
                {
                case 1:
                {
                    int choix4 = 1;
                    g.BFS(choix4);
                    break;
                }
                case 2:
                {

                    break;
                }
                }
            }
            while(choixAlgo != 1 && choixAlgo != 2);
            break;
        }
}

void case4(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "Choisir un trajet";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Sur ce menu, vous pouvez afficher l itineraire le plus rapide entre deux points.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "Si vous souhaitez retourner au menu principal, entrez 1.";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "Si vous souhaitez poursuivre sur ce menu, entrez 2.";
    PutCouleur(3,0);
    gotoligcol(16,0);
    int choix_case4 = 0;
    do
    {
        std::cin >> choix_case4;
    }
    while(choix_case4!=1 && choix_case4!=2);
    switch(choix_case4)
    {
    case 1:
        menu();
        break;
    case 2:
        std::cout << "Desormais, souhaitez-vous savoir le chemin le plus rapide en terme :" << std::endl << "1. de trajets (pistes, remontees mecaniques, bus) ?" << std::endl << "2. de temps ?" << std::endl;
        int choixAlgo = 0;
        do
        {
            std::cin >> choixAlgo;
        }
        while(choixAlgo != 1 && choixAlgo != 2);
        switch(choixAlgo)
        {
        case 1:
        {
            int choix4 = 2;
            g.BFS(choix4);
            break;
        }
        case 2:
        {
            PutCouleur(15,0);
            std::cout <<" Choisissez votre point de depart "<<std::endl;
            int depart;
            do
            {
                std::cin >> depart;
            }
            while (depart<0 && depart >37);

            std::cout << "Choisissez votre point arrivee" <<std::endl;
            int arrivee;
            do
            {
                std::cin >> arrivee;
            }
            while (arrivee<0 && arrivee >37);
            std::vector <Point> chemin = dijkstra( depart,arrivee,points,trajets);
            afficher_chemin(chemin);
            break;
        }
        }
        PutCouleur(1,0);
        std::cout<<"Pour retourner au menu appuyer sur 1 pour quitter appuyer sur n'importe quelle touche"<< std::endl;
        int bulle;
        std::cin>> bulle;
        if (bulle==1)
        {
            system("cls");
            menu();

        }

        break;
    }


}

void case5(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    std::cout << "Choisir un trajet";
    PutCouleur(4,0);
    gotoligcol(7,0);
    std::cout << "Sur ce menu, vous pouvez calculer le chemin le plus interessant entre deux points de la station selon vos criteres.";
    PutCouleur(3,0);
    gotoligcol(10,0);
    std::cout << "Si vous souhaitez retourner au menu principal, entrez 1.";
    PutCouleur(3,0);
    gotoligcol(13,0);
    std::cout << "Si vous souhaitez poursuivre sur ce menu, entrez 2.";
    PutCouleur(3,0);
    gotoligcol(16,0);
    int choix_case5 = 0;
    do
    {
        std::cin >> choix_case5;
    }
    while(choix_case5!=1 && choix_case5!=2);
    switch(choix_case5)
        {
        case 1:
            menu();
            break;
        case 2:
            //selection_piste(trajets,points);

            break;
        }
}

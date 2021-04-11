#include <windows.h>
#include <algorithm>
#include "Menu.h"
#include "header.h"
#include "Graphe.h"

//fonction nécessaire à la création de coordonnées dans la console
COORD convertToCoord(int ligne, int colonne)
{
    COORD mycoord;

    mycoord.X = colonne;
    mycoord.Y = ligne;

    return mycoord;
}

//Fonction de déplacement au sein de la console
void gotoligcol(int ligne, int colonne)
{
    COORD mycoord = convertToCoord(ligne,colonne);
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), mycoord);
}

//fonction permettant de colorer le texte
void PutCouleur(int couleurTexte, int couleurFond)
{
    HANDLE couleur;
    couleur = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(couleur, couleurFond*16+couleurTexte);
}


//Fonction du menu
void menu()
{
    ///Affichage du menu en utilisant les fonctions ci-dessus
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
    std::cout << "3/ Afficher tous les plus courts chemins d'un point" ;
    PutCouleur(3,0);
    gotoligcol(19,0);
    std::cout << "4/ Afficher l'itineraire de plus rapide" ;
    PutCouleur(3,0);
    gotoligcol(22,0);
    std::cout << "5/ Calculer le chemin le plus interessant entre deux points";
    gotoligcol(25,0);
    std::cout <<"6/ Quitter";
    PutCouleur(15,0);
    gotoligcol(27,0);

    ///appel de la méthode de Graphe de chargement du fichier
    Graphe g("data_arcs.txt");
    //Récupération des vecteurs de Points et Trajets
    std::vector<Point> points = g.rendre_listeP();
    std::vector<Trajet> trajets=g.rendre_listeT();

    int choix = 0;
    do  //Boucle de choix permettant le blindage du menu
    {
        std::cin >> choix;
        if(std::cin.fail())
        {
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            std::cout << "3/ Afficher tous les plus courts chemins d un point" ;
            PutCouleur(3,0);
            gotoligcol(19,0);
            std::cout << "4/ Afficher l'itineraire de plus rapide" ;
            PutCouleur(3,0);
            gotoligcol(22,0);
            std::cout << "5/ Calculer le chemin le plus interessant entre deux points";
            PutCouleur(15,0);
            gotoligcol(25,0);
            std::cout <<"6/ Quitter";
            gotoligcol(27,0);
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dans un état invalide donc on le remet en état valide
            }
        }
        else
        {
            //Si le choix est valide, appel de la fonction équivalente
            switch(choix)
            {
            case 1:
                system("cls");
                case1(trajets, points, g);
                break;
            case 2:
                system("cls");
                case2(trajets, points, g);
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
            case 6 :
                break;
            }
        }
    }
    while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix !=6); //conditions de la boucle de blindage
}

///Fonction n°1 permettant l'affichage des caractéristiques d'un trajet
void case1(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
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
    PutCouleur(15,0);
    gotoligcol(16,0);
    int choix_case1 = 0;
    do //Boucle de blindage
    {
        std::cin >> choix_case1;
        if(std::cin.fail())
        {
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            PutCouleur(15,0);
            gotoligcol(16,0);
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dans un état invalide donc on le remet en état valide
            }
        }
        else
        {
            switch(choix_case1)
            {
            case 1:
                system("cls");
                menu();
                break;
            case 2:
                system("cls");
                int choixTrajet;
                PutCouleur(4,0);
                gotoligcol(1,0);
                std::cout << "Veuillez entrer le numero du trajet dont vous souhaitez connaitre l'origine et l'arrivee." << std::endl;
                PutCouleur(15,0);
                gotoligcol(3,0);
                do //Seconde boucle de blindage pour la saisie du trajet à étudier
                {
                    std::cin >> choixTrajet;
                }
                while(choixTrajet < 1 || choixTrajet > 95); //Conditions de la boucle de blindage
                for(auto elem : trajets)
                {
                    if(choixTrajet == elem.getNumTrajet())
                    {
                        gotoligcol(6,0);
                        PutCouleur(3,0);
                        //Affichage des caractéristiques du trajet demandé
                        std::cout << "Point(s) de depart (" << elem.getDepart() << ") , Point(s) d'arrivee (" << elem.getArrivee() << ") du trajet " << elem.getNumTrajet() <<"."<< "le trajet est de type " << elem.getTransport() << " et dure environ " << elem.getDuree() << " minutes." << std::endl;
                    }
                }
                int retour;
                gotoligcol(9,0);
                PutCouleur(3,0);
                std::cout << "Si vous voulez retourner au menu principal, entrez 1, sinon rentrez 2." << std::endl;
                gotoligcol(12,0);
                PutCouleur(15,0);
                do  //Boucle de blindage
                {
                    std::cin >> retour;
                }
                while(retour!=1 && retour!=2); //Conditions de la boucle de blindage
                if(retour == 1) //Retour au menu
                {
                    system("cls");
                    menu();
                }
                else //Fin du programme
                    break;
            }
        }
    }
    while(choix_case1!=1 && choix_case1!=2); //Conditions de la boucle de blindage
}

///Fonction d'affichage des caratéristiques d'un point
void case2(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
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
    PutCouleur(15,0);
    gotoligcol(16,0);
    int choix_case2 = 0;
    do //Boucle de blindage
    {
        std::cin >> choix_case2;
        if(std::cin.fail())
        {
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            PutCouleur(15,0);
            gotoligcol(16,0);
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
            }
        }
        else
        {
            switch(choix_case2)
            {
            case 1:
                system("cls");
                menu();
                break;
            case 2:
                system("cls");
                int choixPoint;
                PutCouleur(4,0);
                gotoligcol(1,0);
                std::cout << "Veuillez entrer le numero du point dont vous souhaitez connaitre les trajets entrants et ceux sortants." << std::endl;
                PutCouleur(15,0);
                gotoligcol(3,0);
                do //Boucle de blindage
                {
                    std::cin >> choixPoint;
                }
                while(choixPoint < 1 || choixPoint > 37); //onditions de la boucle de blindage
                Point Point_a_afficher;
                for (auto sommets : points) //Boucle permettant de retrouver le point demandé dans le vecteur de Points
                {
                    if (sommets.getNumPoint() == choixPoint)
                    {
                        Point_a_afficher = sommets;
                    }
                }
                PutCouleur(3,0);
                ///Affichage de toutes les caractéristiques du noeud demandé
                std::cout<<std::endl<<"On part du noeud "<< Point_a_afficher.getNom() << "." <<std::endl;
                std::cout <<std::endl<< "Les arcs qui partent de ce noeud sont: " <<std ::endl;
                for (auto arcs : trajets)
                {
                    if (Point_a_afficher.getNumPoint()== arcs.getDepart())
                    {
                        std::cout << arcs.getNomTrajet()<<std::endl;
                    }

                }
                std::cout << "Les arcs qui arrivent de ce noeud sont " <<std ::endl;
                for (auto arcs : trajets)
                {
                    if (Point_a_afficher.getNumPoint()== arcs.getArrivee())
                    {
                        std::cout << arcs.getNomTrajet()<<std::endl;
                    }

                }
                std::cout<<std::endl<< "Les sommets adjacents sont " <<std ::endl;
                for (auto arcs : trajets)
                {
                    if (Point_a_afficher.getNumPoint()== arcs.getDepart())
                    {
                        Point po = arcs.getPointArrivee();
                        std::cout << "Pour les trajets entrants : "<<po.getNom()<<std::endl;
                    }
                    if (Point_a_afficher.getNumPoint()== arcs.getArrivee())
                    {
                        Point po = arcs.getPointDepart();
                        std::cout << "Pour les trajets sortants : "<< po.getNom()<<std::endl;
                    }
                }
                int retour;
                std::cout<<std::endl<< "Si vous voulez retourner au menu principal, entrez 1, sinon rentrez 2." <<std::endl<< std::endl;
                PutCouleur(15,0);
                do //Boucle de blindage
                {
                    std::cin >> retour;
                }
                while(retour!=1 && retour!=2); //conditions de la boucle de blindage
                if(retour == 1) //Retour au menu
                {
                    system("cls");
                    menu();
                }
                else //Fin du programme
                    break;
            }
        }
    }
    while(choix_case2!=1 && choix_case2!=2); //conditions de la boucle de blindage
}

///Fonction d'affichage des algo BFS et Dijkstra à partir d'un point vers l'ensemble des autres points
void case3(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
{
    std::vector<Point> h;
    std::vector<Point> p;
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
    PutCouleur(15,0);
    gotoligcol(16,0);
    int choix_case3 = 0;
    do //Boucle de blindage
    {
        std::cin >> choix_case3;
        if(std::cin.fail())
        {
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            PutCouleur(15,0);
            gotoligcol(16,0);
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
            }
        }
        else
        {
            switch(choix_case3)
            {
            case 1:
                system("cls");

                menu();
                break;
            case 2:
                system("cls");
                PutCouleur(4,0);
                gotoligcol(1,0);
                std::cout << "Desormais, souhaitez-vous connaitre le chemin le plus rapide en terme :" << std::endl << std::endl;
                PutCouleur(3,0);
                std::cout << "1/ de trajets (pistes, remontees mecaniques, bus) ?" << std::endl << std::endl<< "2/ de temps ?" << std::endl<< std::endl;
                PutCouleur(15,0);
                int choixAlgo = 0;
                do //boucle de blindage du choix d'algo fait par l'utilisateur
                {
                    std::cin >> choixAlgo;
                }
                while(choixAlgo != 1 && choixAlgo != 2); //conditions de la boucle de blindage
                    switch(choixAlgo)
                    {
                    case 1: //Si choix n°1, appel de la méthode BFS de la classe Graphe
                    {
                        system("cls");
                        int choix4 = 1;
                        g.BFS(choix4);
                        break;
                    }
                    case 2: //Si choix n°2, appel de la fonction Dijkstra
                    {
                        system("cls");
                        PutCouleur(4,0);
                        gotoligcol(1,0);
                        std::cout << "Avez vous une contrainte de temps particuliere pour arriver a l'heure a votre dejeuner ? 1/Oui 2/Non"<<std::endl;
                        int b;
                        do
                        {
                            std::cin >>b;
                        }while (b!=1 && b!=2);

                        std::cout << "Choisissez un sommet entre 1 et 37 "<<std::endl<<std::endl;
                        PutCouleur(15,0);
                        int a;
                        do //Boucle de blindage
                        {   std::cin>>a;
                        }while (a<0 || a>37); //conditions de la boucle de blindage
                        std::cout<<std::endl;

                        switch (b)
                        {
                        case 1 :
                            std::cout << "Dans combien de temps est votre dejeuner ? (a partir de 10 minutes sinon dejeunez la ou vous etes)" <<std::endl;
                            int temps;
                            do
                            {
                                std::cin>>temps;
                            }while (temps <10);
                            temps = -temps;
                            h = dijkstra(a, temps,points,trajets);// On met l'arrivee en negatif pour que dikstra montre les temps et pas seulement un itineraire
                            break;
                        case 2 :
                              p = dijkstra(a, -1,points,trajets);// On met l'arrivee en negatif pour que dikstra montre tout les temps et pas seulement un itineraire
                              break;

                        }




                        break;
                    }
                    }


                int retour;
                std::cout << std::endl<< "Voulez-vous retourner au menu ?     1/ Oui    2/ Non" << std::endl<< std::endl;
                PutCouleur(15,0);
                do //Boucle de blindage
                {
                    std::cin >> retour;
                }
                while(retour!=1 && retour!=2); //Conditions de la boucle de blindage
                if(retour == 1) //Retour au menu
                {
                    system("cls");
                    menu();
                }
                else //fin du progamme
                    break;
            }
        }
    }
    while(choix_case3!=1 && choix_case3!=2); //Conditions de la boucle de blindage
}

///Fonction d'affichage des algos BFS et Dijkstra à partir d'un point de départ, vers un point d'arrivée
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
    do //Boucle de blindage
    {
        PutCouleur(15,0);
        gotoligcol(16,0);
        std::cin >> choix_case4;
        if(std::cin.fail())
        {
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
            }
        }
        else
        {

            switch(choix_case4)
            {
            case 1: //Retour au menu
                system("cls");
                menu();
                break;
            case 2: //Suite de la fonction
                system("cls");
                PutCouleur(4,0);
                gotoligcol(1,0);
                std::cout << "Desormais, souhaitez-vous savoir le chemin le plus rapide en terme :" << std::endl<< std::endl;
                PutCouleur(3,0);
                std::cout << "1/ de trajets (pistes, remontees mecaniques, bus) ?" << std::endl << std::endl<< "2/ de temps ?" << std::endl<< std::endl;
                PutCouleur(15,0);
                int choixAlgo = 0;
                do //boucle de blindage
                {
                    std::cin >> choixAlgo;
                }
                while(choixAlgo != 1 && choixAlgo != 2); //conditions de la boucle de blindage
                switch(choixAlgo)
                {
                case 1: //Appel de la méthode BFS de la classe Graphe
                {
                    system("cls");
                    PutCouleur(3,0);
                    int choix4 = 2;
                    g.BFS(choix4);
                    int retour;
                    std::cout << "Si vous voulez retourner au menu principal, entrez 1, sinon rentrez 2."<< std::endl<< std::endl;
                    PutCouleur(15,0);
                    do //boucle de blindage
                    {
                        std::cin >> retour;
                    }
                    while(retour!=1 && retour!=2); //conditions de la boucle de blindage
                    if(retour == 1) //Retour au menu
                    {
                        system("cls");
                        menu();
                    }
                    else //Fin du programme
                        break;
                }
                case 2: //appel de la fonction dijkstra
                {
                    system("cls");
                    gotoligcol(1,0);
                    PutCouleur(4,0);
                    std::cout <<" Choisissez votre point de depart entre 1 et 37 "<<std::endl<<std::endl;
                    int depart;
                    PutCouleur(15,0);
                    do
                    {
                        std::cin >> depart;
                    }
                    while (depart<0 || depart >37);
                    PutCouleur(4,0);
                    std::cout <<std::endl<< "Choisissez votre point d'arrivee" <<std::endl<<std::endl;
                    int arrivee;
                    PutCouleur(15,0);
                    do
                    {
                        std::cin >> arrivee;
                    }
                    while (arrivee<0 || arrivee >37);
                    std::vector <Point> chemin = dijkstra( depart,arrivee,points,trajets);
                    afficher_chemin(chemin);
                    int retour;
                    std::cout << "Si vous voulez retourner au menu principal, entrez 1, sinon rentrez 2." << std::endl<< std::endl;
                    PutCouleur(15,0);
                    do //Boucle de blindage
                    {
                        std::cin >> retour;
                    }
                    while(retour!=1 && retour!=2); //Conditions de la boucle de blindage
                    if(retour == 1) //Retour au menu
                    {
                        system("cls");
                        menu();
                    }
                    else //Fin du programme
                        break;
                }
                }
            }
        }
    }
    while(choix_case4!=1 && choix_case4!=2); //conditions de la boucle de blindage
}


void case5(std::vector<Trajet> trajets, std::vector<Point> points, Graphe g)
{
    PutCouleur(15,0);
    gotoligcol(3,50);
    //Affichage
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
        PutCouleur(15,0);
        gotoligcol(16,0);
        std::cin >> choix_case5;
        if(std::cin.fail())
        {
            // Affichage
            system("cls");
            std::cerr << "Saisie incorrecte : veuillez recommencer." << std::endl;
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
            PutCouleur(15,0);
            gotoligcol(16,0);
            std::cin.clear();
            std::cin.seekg(0, std::ios::end);
            if(!std::cin.fail())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
            }
            else
            {
                std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
            }
        }
        else
        {
            switch(choix_case5)
            {
            case 1:
                system("cls");
                menu();
                break;
            case 2:
                system("cls");
                selection_piste(trajets,points); // Si case 2 on va choisir les settings qu'on prefere dans cette fonction
                int retour;
                std::cout << "Si vous voulez retourner au menu principal, entrez 1, sinon rentrez 2." << std::endl<< std::endl;
                PutCouleur(15,0);
                do
                {
                    std::cin >> retour;
                }
                while(retour!=1 && retour!=2);
                if(retour == 1)
                {
                    system("cls");
                    menu();
                }
                else
                    break;
            }
        }
    }
    while(choix_case5!=1 && choix_case5!=2);
}


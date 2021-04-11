#include "header.h"
#include "Points.h"
#include "Trajet.h"
#include "Menu.h"
#include <fstream>
#include <stdio.h>

void selection_piste(std::vector <Trajet> TousTrajets, std::vector <Point> TousPoints)
{
    // Initialisation du fichier pour la sauvegarde
    std::ifstream temp("temp.txt");
    if(temp)
    {
        temp.close();
        std::remove("temp.txt");
    }
    std::ofstream fichierT("temp.txt");
    int numTrajet;
    // Affichage menu 5
    PutCouleur(4,0);
    gotoligcol(1,0);
    std::cout << "Quel type de pistes voulez vous faire ? \n" <<std::endl;
    PutCouleur(3,0);
    std::cout << "1/ Niveau debutant priorisation des pistes vertes et bleues et pas de teleskis. \n "<<std::endl;
    std::cout << "2/ Niveau intermediaire  priorisation pistes rouges et toutes remontees mecaniques. \n"<<std::endl;
    std::cout << "3/ Niveau avance : ski-plaisir : plein de descentes moins de remontees. \n " <<std::endl;
    PutCouleur(15,0);
    // Initialisation vecteurs differents par niveau
    std::vector <Trajet> debutant = TousTrajets;
    std::vector <Trajet> intermediaire =TousTrajets;
    std::vector <Trajet> ski_plaisir  = TousTrajets;
    int a;
    do
    {
        std::cin>> a;

    }
    while (a!= 1 && a!=2 && a!=3);
    std::vector <Point> chemin;
    // On va arbitrairement rajouter du temps au piste que l'on ne veut pas prendre en priorit� pour que dikjstra ne les prenne pas en priorit�
    for (unsigned int i =0; i< debutant.size();i++ )
    {

        std::string type = debutant[i].getTransport();
        if (type == "R" || type =="N" || type == "KL" || type == "SURF" || type == "TK" ) // mettre un malus sur les pistes pas d�butant
        {
            double  temps = debutant[i].getDuree();
            temps += 50;
            debutant[i].setDureeSki(temps);

        }

        if (a == 1)
        {
            numTrajet = i + 1;
            double temps = debutant[i].getDuree(); //Sauvegarde du fichier
            fichierT << "Trajet n�" << numTrajet << " : " << temps << " minutes." << std::endl;
        }

    }
   for (unsigned int i =0; i< intermediaire.size();i++)
    {
        std::string type = intermediaire[i].getTransport();
        if (type == "V" || type == "B" || type =="N" || type == "KL" || type == "SURF") // Mettre un malus sur les pistes pas intermediaire
        {
            double  temps = intermediaire[i].getDuree();
            temps += 50;
            intermediaire[i].setDureeSki(temps);

        }
                if (a == 2)
        {
            numTrajet = i + 1;
            double temps = intermediaire[i].getDuree(); //Sauvegarde du fichier
            fichierT << "Trajet n�" << numTrajet << " : " << temps << " minutes." << std::endl;
        }



    }
    for (unsigned int i =0; i< ski_plaisir.size();i++)
    {
        std::string type = ski_plaisir[i].getTransport();
        if (type == "TPH" || type == "TC" || type == "TSD" || type == " TS" || type == "TK") // Mettre un malus sur les pistes pas ski-plaisir
        {
            double  temps = ski_plaisir[i].getDuree();
            temps += 50;
            ski_plaisir[i].setDureeSki(temps);

        }
          if (a == 3)
        {
            numTrajet = i + 1;
            double temps = ski_plaisir[i].getDuree(); //Sauvegarde du fichier
            fichierT << "Trajet n�" << numTrajet << " : " << temps << " minutes." << std::endl;
        }

    }
    fichierT.close();
    system("cls");
    switch (a) // Lancement du dikjstra pour ces chemins particuliers
    {
    case 1 :
        PutCouleur(4,0);
        gotoligcol(1,0);
        std::cout <<"Choisissez votre point de depart "<<std::endl<<std::endl;
        int depart;
        PutCouleur(15,0);
        std::cin >> depart;
        std::cout << std::endl<< std::endl;
        PutCouleur(4,0);
        std::cout << "Choisissez votre point arrivee" <<std::endl<<std::endl;
        int arrivee;
        PutCouleur(15,0);
        std::cin >> arrivee;
        chemin = dijkstra( depart,arrivee,TousPoints,debutant);
        afficher_chemin(chemin);
        break;
    case 2 :
        debut_dikjstra( TousPoints, intermediaire); // On lance dikjstra avec le nouveau vecteur
        break;
    case 3 :
        debut_dikjstra( TousPoints, ski_plaisir);// On lance dikjstra avec le nouveau vecteur
        break;
    }





}

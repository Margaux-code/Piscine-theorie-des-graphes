#include "header.h"

void selection_piste(std::vector <Trajet> TousTrajets, std::vector <Point> TousPoints)
{
    std::cout << "Quel type de pistes voulez vous faire ?" <<std::endl;
    std::cout << "1.Niveau debutant priorisation des pistes vertes et bleues et pas de téleskis "<<std::endl;
    std::cout << "2.Niveau intermediaire  priorisation pistes rouges et toutes remontées mécaniques"<<std::endl;
    std::cout <<"3. Niveau avancé : ski-plaisir : plein de descentes moins de remontees " <<std::endl;
    std::vector <Trajet> debutant = TousTrajets;
    std::vector <Trajet> intermediaire =TousTrajets;
    std::vector <Trajet> ski_plaisir  = TousTrajets;
    Trajet tratra_debeug;
    for (auto elem : debutant)
    {
        std::string type = elem.getTransport();
          double  temps = elem.getDuree();
            temps += 50;
            elem.setDureeSki(temps);
        if (type == "R" || type =="N" || type == "KL" || type == "SURF" || type == "TK" )
        {
            double  temps = elem.getDuree();
            temps += 50;
            elem.setDureeSki(temps);
        }



    }
    for (auto elem : intermediaire)
    {
        std::string type = elem.getTransport();
        if (type == "V" || type == "B" || type =="N" || type == "KL" || type == "SURF")
        {
            double  temps = elem.getDuree();
            temps += 50;
            elem.setDureeSki(temps);

        }



    }
    for (auto elem : ski_plaisir)
    {
        std::string type = elem.getTransport();
        if (type == "TPH" || type == "TC" || type == "TSD" || type == " TS" || type == "TK")
        {
            double  temps = elem.getDuree();
            temps += 50;
            elem.setDureeSki(temps);

        }


    }

    int a;
    do
    {
        std::cin>> a;

    }
    while (a!= 1 && a!=2 && a!=3);
    switch (a)
    {
    case 1 :
        debut_dikjstra( TousPoints, debutant);
        break;
    case 2 :
        debut_dikjstra( TousPoints, intermediaire);
        break;
    case 3 :
        debut_dikjstra( TousPoints, ski_plaisir);
        break;
    }





}

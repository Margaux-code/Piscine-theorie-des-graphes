#include <iostream>
#include <windows.h>

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
    std::cout << "3/ Afficher tous les plus courts chemins d un point";
    PutCouleur(3,0);
    gotoligcol(19,0);
    std::cout << "4/ Afficher l itineraire de plus rapide";
    PutCouleur(3,0);
    gotoligcol(22,0);
    std::cout << "5/ Calculer le chemin le plus interessant entre deux points";
    PutCouleur(15,0);
    gotoligcol(25,0);

    int choix = 0;
    do
    {
        std::cin >> choix;
        switch(choix)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        }
    }
    while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
}

/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : 04-Fonctions
Auteur(s)      : Antonio Giordano - Aminata Kante
Date creation  : 15.11.2020
Description    : Programme permettant d'utiliser les différentes fonctions disponible
                 dans la librairie fonctions.h
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include "fonctions.h"

using namespace std;

int saisieInt(const int& MIN, const int& MAX, const string& QUESTION);

int main() {
    // Différentes fonctions proposées pour ce programme
    enum class Fonction {
        quitter,
        estPair,
        sommeChiffre,
        nombrePremier,
        nombreArmstrong,
        nombreAlea,
        buffer,
        trigo
    };

    // Bornes minimum et maximum pour les différentes fonctions
    const int MIN_MENU =    0,
              MAX_MENU =    7;
    const int MIN_VAL  =    0,
              MAX_VAL  = 1000;
    const int MIN_NBRE =    0,
              MAX_NBRE =  100;
    const int MIN_RAND = -100,
              MAX_RAND =  100;
    const int MIN_DGR  =    0,
              MAX_DGR  =  360;

    // Interval pour les fonctions
    const string INTERVAL_MENU
                = "[" + to_string(MIN_MENU) + " - " + to_string(MAX_MENU) + "]";
    const string INTERVAL_VAL
                = "[" + to_string(MIN_VAL) + " - " + to_string(MAX_VAL) + "]";
    const string INTERVAL_NBRE
                = "[" + to_string(MIN_NBRE) + " - " + to_string(MAX_NBRE) + "]";
    const string INTERVAL_RAND
                = "[" + to_string(MIN_RAND) + " - " + to_string(MAX_RAND) + "]";
    const string INTERVAL_DGR
                = "[" + to_string(MIN_DGR) + " - " + to_string(MAX_DGR) + "]";

    // Questions utilisateur
    const string QUESTION_MENU  = "votre choix " + INTERVAL_MENU + " :";
    const string QUESTION_VAL   = "Entrez une valeur : " + INTERVAL_VAL + " : ";
    const string QUESTION_DEBUT = "    - debut : " + INTERVAL_VAL + " : ";
    const string QUESTION_FIN   = "    - fin   : " + INTERVAL_VAL + " : ";
    const string QUESTION_MIN   = "    - min   : " + INTERVAL_RAND + " : ";
    const string QUESTION_NBRE  = "    - nbre  : " + INTERVAL_NBRE + " : ";
    const string QUESTION_DGR   = "Entrez un angle en degre : " + INTERVAL_DGR + " : ";

    const string QUESTION_QUITTER = "Voulez-vous quitter ? [o - n] : ";
    const char OUI = 'o',
               NON = 'n';

    // Variable pour quitter le programme
    bool recommencer = true;

    do{
        // Affichage des options
        cout << endl;
        cout << "options "                  << endl;
        cout << "    1 est pair"          << endl;
        cout << "    2 somme chiffre"       << endl;
        cout << "    3 nombre 1er"          << endl;
        cout << "    4 nombre de Armstrong" << endl;
        cout << "    5 nombre aleatoire"    << endl;
        cout << "    6 buffer"              << endl;
        cout << "    7 trigo"               << endl;
        cout << "    0 quitter"             << endl;

        // Variables pour les entrées utilisateurs
        int choixFonction, valeur1, valeur2, nombre;

        // Variable pour le fonctionnement du programme
        int somme;              // fonction sommeChiffre
        char min, max;          // fonction buffer
        double sin, cos, tan;   // fonction trigo
        string questionMax;     // fonction nombreAlea

        // Choix de la fonction
        choixFonction = saisieInt(MIN_MENU, MAX_MENU, QUESTION_MENU);

        switch ((Fonction)choixFonction) {
            case Fonction::quitter :
                recommencer = !repondOui(QUESTION_QUITTER, OUI, NON);

                break;

            case Fonction::estPair :
                valeur1 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_VAL);

                if(estPair(valeur1))
                    cout << valeur1 << " est une valeur pair"   << endl;
                else
                    cout << valeur1 << " est une valeur impair" << endl;

                break;

            case Fonction::sommeChiffre :
                valeur1 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_VAL);
                somme = sommeChiffres(valeur1);
                cout << "la somme des chiffre de " << valeur1 << " = " << somme;

                break;

            case Fonction::nombrePremier :
                cout << "Determiner les nombres premiers compris dans un intervalle"
                     << endl;
                valeur1 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_DEBUT);
                valeur2 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_FIN);
                for(int i = valeur1; i <= valeur2; i++){
                    if(nbre1er(i))
                        cout << "le nombre " << i << " est un nombre premier" << endl;
                }

                break;

            case Fonction::nombreArmstrong :
                cout << "Determiner les nombres de Armstrong compris dans un intervalle"
                     << endl;
                valeur1 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_DEBUT);
                valeur2 = saisieInt(MIN_VAL, MAX_VAL, QUESTION_FIN);
                for(int i = valeur1; i <= valeur2; i++){
                    if(nbreArmstrong(i))
                        cout << "le nombre " << i << " est un nombre de Armstrong"
                             << endl;
                }

                break;

            case Fonction::nombreAlea :
                valeur1 = saisieInt(MIN_RAND, MAX_RAND, QUESTION_MIN);

                questionMax = "    - max   : [" + to_string(valeur1) + " - "
                              + to_string(MAX_RAND) + "] : ";

                valeur2 = saisieInt(valeur1, MAX_RAND, questionMax);
                nombre = saisieInt(MIN_NBRE, MAX_NBRE, QUESTION_NBRE);

                cout << "voici des valeur aleatoire [" << valeur1 << " - " << valeur2
                     << "] :" << endl;

                for(int i = 1; i <= nombre; i++) {
                    cout << random(valeur1, valeur2);
                    if(i != nombre) cout << ", ";
                }

                break;

            case Fonction::buffer :
                cout << "entrez une phrase : ";
                somme = buffer(min, max);
                if(min != 0) cout << "la plus petite minuscule : " << min    << endl;
                if(max != 0) cout << "la plus grande majuscule : " << max    << endl;
                cout << "le nombre de caracteres  : " << somme  << endl;

                break;

            case Fonction::trigo :
                valeur1 = saisieInt(MIN_DGR, MAX_DGR, QUESTION_DGR);
                trigo(valeur1, sin, cos, tan);

                cout << "sin(" << valeur1 << ") = " << sin << endl;
                cout << "cos(" << valeur1 << ") = " << cos << endl;
                cout << "tan(" << valeur1 << ") = " << tan << endl;

                break;

            default:
                cout << "option inconnue, veuillez reesayer." << endl;
                break;
        }
    } while(recommencer);
    return EXIT_SUCCESS;
}

/// Fonction qui retourne un int saisi par l'utilisateur compris entre MIN et MAX
/// \param const int& MIN
/// \param const int& MAX
/// \param const string& QUESTION
/// \return
int saisieInt(const int& MIN, const int& MAX, const string& QUESTION){
    int entreeUtilisateur;
    bool entreeCorrecte;
    do {  // tant  que l'entrée utilisateur est incorrecte

        // demande à l'utilisateur d'indiquer une précision
        cout << QUESTION;
        cin  >> entreeUtilisateur;

        // Vérification de l'entrée et de l'état du buffer (si erreur)
        entreeCorrecte =   !(cin.fail())
                           && (entreeUtilisateur >= MIN)
                           && (entreeUtilisateur <= MAX) ;

        if (!entreeCorrecte) {
            // si le buffer est en erreur, on le nettoie/corrige.
            if(cin.fail()){
                CORRIGER_BUFFER;
            }
            VIDER_BUFFER;
            cout << "Erreur de saisie" << endl;
        }
    } while (!entreeCorrecte);
    return entreeUtilisateur;
}




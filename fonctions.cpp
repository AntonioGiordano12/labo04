/*
-----------------------------------------------------------------------------------
Nom du fichier : fonctions.cpp
Nom du labo    : 04-Fonctions
Auteur(s)      : Antonio Giordano
Date creation  : 15.11.2020
Description    : <à compléter>
Remarque(s)    : <à compléter>
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>
#include <cmath>
#include <ctime>

#include "fonctions.h"

using namespace std;

/// Fonction qui renvoie true si la valeur passée est un nombre pair
/// \param VALEUR
/// \return
bool estPair(const int& VALEUR) {
    if(VALEUR % 2 == 0){
        return true;
    } else {
        return false;
    }
}

/// Fonction qui retourne la somme des chiffre d'une valeur passée
/// \param VALEUR
/// \return
int sommeChiffres(const int& VALEUR) {
    int somme = 0,
        nombre = VALEUR;

    while (nombre != 0) {
        somme += nombre % 10;
        nombre = nombre / 10;
    }

    return somme;
}

/// Fonction qui retourne true si la valeur passée est un nombre premier
/// source : https://www.geeksforgeeks.org/c-program-to-check-prime-number/
/// \param VALEUR
/// \return bool
bool nbre1er(const int& VALEUR) {
    if (VALEUR <= 1)
        return false;
    if (VALEUR <= 3)
        return true;

    if (VALEUR % 2 == 0 || VALEUR % 3 == 0)
        return false;

    for (int i = 5; i * i <= VALEUR; i = i + 6)
        if (VALEUR % i == 0 || VALEUR % (i + 2) == 0)
            return false;

    return true;
}

/// Fonction qui true si la valeur passée est un nombre de Armstrong
/// \param const int& VALEUR
/// \return bool
bool nbreArmstrong(const int& VALEUR){
    int somme=0,
        temp = VALEUR,
        c;
    while(temp>0)
    {
        c = temp % 10;
        somme = somme + (c*c*c);
        temp = temp / 10;
    }
    if(VALEUR == somme)
        return true;
    return false;
}



/// Retourne une valeur aléatoire comprise entre MIN et MAX
/// \param const int& MIN
/// \param const int& MAX
/// \return int
int random(const int& MIN, const int& MAX)
{
    static bool first = true;
    if (first){
        srand( (unsigned int)time(nullptr) ); //seed 1ere fois seulement
        first = false;
    }
    return MIN + rand() % (( MAX + 1 ) - MIN);
}

/// Fonction qui traite le contenu du buffer, retourne le nombre de caractère ainsi
/// que la lettre majuscule la plus grand et la lettre minuscule la plus petite
/// \param char& min
/// \param char& max
/// \return int
int buffer(char& min, char& max){
    bool minuscule = false,
         majuscule = false;

    string buffer;
    VIDER_BUFFER;
    getline(cin, buffer);
    min = max = buffer[0];
    for(char c : buffer){
        if(isalpha(c)){
            if(islower(c)){
                minuscule = true;
                if(isupper(min)) min = c;
                if(c < min) min = c;
            }

            if(isupper(c)){
                majuscule = true;
                if(islower(max)) max = c;
                if(c > max) max = c;
            }
        }
    }
    if(!minuscule) min = 0;
    if(!majuscule) max = 0;
    return (int)buffer.length();
}

/// Fonction qui retourne en paramètre le sinus, cosinus et tangante d'un angle
/// \param const double& ANGLE
/// \param double& sinus
/// \param double& cosinus
/// \param double& tangante
void trigo(const double& ANGLE, double& sinus, double& cosinus, double& tangante){
    sinus = sin(ANGLE);
    cosinus = cos(ANGLE);
    tangante = tan(ANGLE);
}

/// Fonction qui retourne un booleen correspondant à la réponse
/// \param const string& QUESTION
/// \param const char& OUI
/// \param const char& NON
/// \return bool
bool repondOui(const string& QUESTION, const char& OUI, const char& NON){
    char entreeDecision;
    bool entreeCorrecte;

    do {
        cout << QUESTION;
        cin  >> entreeDecision;

        // On vérifie que c'est un char autorisé
        entreeCorrecte = tolower(entreeDecision) == OUI ||
                         tolower(entreeDecision) == NON;

        // On vide le buffer
        VIDER_BUFFER;

    } while (!entreeCorrecte);

    // Si l'entrée est celle correspondante a OUI, on retourne "true"
    return entreeDecision == OUI;
}
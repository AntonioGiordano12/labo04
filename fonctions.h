/**
* @file fonctions.h
* @labo 04-Fonctions
* @authors Antonio Giordano - Aminata Kante
* @date 15.11.2020
* @brief fichier header des fonctions
*/


#ifndef FONCTIONS_H
#define FONCTIONS_H

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CORRIGER_BUFFER cin.clear()

bool estPair(const int& VALEUR);

int sommeChiffres(const int& VALEUR);

bool nbre1er(const int& VALEUR);

bool nbreArmstrong(const int& VALEUR);

int random(const int& MIN, const int& MAX);

int buffer(char& min, char& max);

void trigo(const double& ANGLE, double& sinus, double& cosinus, double& tangante);

bool repondOui(const std::string& QUESTION, const char& OUI, const char& NON);

#endif // FONCTIONS_H



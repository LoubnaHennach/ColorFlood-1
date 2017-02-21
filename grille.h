/**
 * \file grille.h
 * \brief Fonctions sur les grilles et définition d'une structure
 * \author THOR
 * \date février 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "pile.h"

#ifndef GRILLE_H
#define GRILLE_H

/**
 * \struct element
 * \brief Structure d'une case du plateau
 *
 * Pour une case, on a son appartenance à la tâche ou non (int)
 * ainsi que sa couleur (char).
 */
struct element
{
	int appartenance;
	char color;
};

typedef struct element element;

typedef element ** grille;


/**
 * \fn grille initialize(int size)
 * \brief Fonction d'initialisation d'une grille.
 *
 * \param size Taille du jeu (grille à initialiser size*size), doit être compris entre 8 et 24.
 * \return Grille de taille size*size.
 */
grille initialize(int size);

/**
 * \fn void display(grille plateau, int size)
 * \brief Fonction d'affichage d'une grille.
 *
 * \param plateau Grille en cours.
 * \param size Taille du jeu (grille size*size).
 * \return Affichage du plateau.
 */
void display(grille plateau, int size);

/**
 * \fn grille random_grille(int size)
 * \brief Fonction d'initialisation d'une grille aléatoire.
 *
 * \param size Taille du jeu (grille à initialiser size*size), doit être compris entre 8 et 24.
 * \return Grille aléatoire de taille size*size.
 */
grille random_grille(int size);

/**
 * \fn void free_space(grille plateau, int size)
 * \brief Fonction de libération de la mémoire d'une grille.
 *
 * \param plateau Grille en cours.
 * \param size Taille du jeu (grille size*size).
 * \return Libération de la mémoire d'une grille.
 */
void free_space(grille plateau, int size);

/**
 * \fn grille change_color(int i, int j, char c, grille plateau)
 * \brief Fonction de changement de la couleur d'une case donnée.
 *
 * \param coordonnees de la position.
 * \param c Couleur choisie.
 * \param plateau Grille en cours.
 * \return Grille avec changement de couleur de la case donnée.
 */
grille change_color(coordonnees coord, char c, grille plateau);

/**
 * \fn bool if_flood(grille plateau, int size)
 * \brief Fonction de test de victoire.
 *
 * \param plateau Grille en cours.
 * \param size Taille du jeu (grille size*size).
 * \return 1 si le plateau est entièrement innondé d'une couleur (victoire), 0 sinon.
 */
bool if_flood(grille plateau, int size);

/**
 * \fn int test_neighbour(grille plateau, coordonnees coord, int size, char couleur_choisie)
 * \brief Fonction de test des cases voisines de même couleur.
 *
 * \param plateau Grille en cours.
 * \param coord Coordonnée de la case.
 * \param size Taille du jeu (grille size*size).
 * \param couleur_choisie Couleur choisie.
 * \return 0, 1, 2, 3 ou 4 si il n'y a pas de voisin ou si la case au-dessus, de droite, en-dessous ou à gauche a la même couleur que celle choisie.
 */
int test_neighbour(grille plateau, coordonnees coord, int size, char couleur_choisie);

/**
 * \fn void modif_color (char couleur_choisie, grille plateau, int size)
 * \brief Fonction modification de la couleur de l'ensemble du plateau.
 *
 * \param couleur_choisie Couleur choisie.
 * \param plateau Grille en cours.
 * \param size Taille du jeu (grille size*size).
 * \return Grille avec changement de couleur de l'ensemble des cases.
 */
void modif_color (char couleur_choisie, grille plateau, int size);

/**
 * \fn Pile Deep(char couleur_choisie, grille plateau, int size,coordonnees position_pere, Pile P)
 * \brief Fonction recursive qui cherche à aller ale plus loins possible avec une couleur.
 *
 * \param couleur_choisie Couleur choisie.
 * \param plateau Grille en cours.
 * \param size Taille du jeu (grille size*size).
 * \param coord Coordonnée de la case.
 * \param P Pile du parcours lors de la recherche en profondeur.
 * \return P, la pile avec un nouvel élément ou la pile sans modification.
 */
Pile Deep(char couleur_choisie, grille plateau, int size, coordonnees position_pere, Pile P);


#endif

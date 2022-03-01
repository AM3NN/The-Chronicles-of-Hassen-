#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct
{

    //image (spritesheet)
    SDL_Surface *image_perso;
    //position
    SDL_Rect position_perso;
    //tableau animation
    SDL_Rect animation_perso[60];
    //compteur du tableau animation
    int compteur;
    //direction
    int direction; //droite : 1 || gauche : 2
    int etat; // mvt : 1 || stable : 0
    int acceleration;
    int vie;
    int score;

    int gravity;

} personne;
void initPerso(personne* p);
void afficherPerso(personne p, SDL_Surface* screen);
void deplacerPerso(personne* p,int dt);
void animerPerso(personne* p);
void saut(personne* p);
#endif 

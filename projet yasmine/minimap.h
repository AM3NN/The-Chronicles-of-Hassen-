#ifndef Image_H
#define Image_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
	SDL_Surface *image_minimap;
	SDL_Rect position_minimap;
	SDL_Surface *image_bonhomme;
	SDL_Rect position_bonhomme;
}minimap;

typedef struct 
{
	SDL_Surface *image_timeUp;
	SDL_Rect position_timeUp;
}timeUp;


void initminimap( minimap * m);
void inittimeup( timeUp * t);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
void affichertimeup (timeUp t, SDL_Surface * screen);
void affichertemps(int temps ,SDL_Surface *screen);
void sauvegarder(int score, char nomjoueur[], char nomfichier[],SDL_Surface *screen);
int meilleur(char nomfichier[], int*score, char nomjoueur[]);
void liberer(minimap *m);
#endif

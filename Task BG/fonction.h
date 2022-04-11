#ifndef fonction_H_INCLUDED
#define fonction_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1920
#define SCREEN_H 1080

typedef struct 
{
SDL_Rect pos;
SDL_Rect pos_camera;
SDL_Surface * img;
SDL_Surface *masque;
SDL_Surface *tab[10];
int tab1;
}background;

typedef struct 
{
SDL_Rect pos;
SDL_Surface *ps;
int direction;
}Personne;

typedef struct 
{
SDL_Rect pos;
SDL_Surface *pic;
}image;

void initbackground (background *b);
void initmasque (background *b);
//void initchest (image *c);
//void initperso (image *p);
void afficherBack (background b, SDL_Surface * screen);
void afficherimage (image img, SDL_Surface * screen);
void animerBackground (background * e);
void afficheranim (background e, SDL_Surface * screen);
SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y);
int collisionPP (Personne p, SDL_Surface * masque);
void scrolling (background * b, int direction, int pasAvancement);
void liberer(background b);
//void libererimage (image m);

#endif

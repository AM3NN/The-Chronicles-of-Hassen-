#ifndef projet_H_INCLUDED
#define projet_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1920
#define SCREEN_H 1080

typedef struct  {
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface * img;
        }Image;
/*typedef struct
{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Color textColor;
    char texte[50];
} Text; */
void initbackg(Image* backg);
void initplay(Image* play);
void initoption(Image* option);
void initexit(Image* exit);
void initplay1(Image* play1);
void initoption1(Image* option1);
void initexit1(Image* exit1);
void liberer (Image A);
void afficher(Image p1, SDL_Surface *screen);
void initbackgs(Image* bgsettings);
void Settings(SDL_Surface *screen);
void playp(SDL_Surface *screen);
void initp(Image* bgplay);
void initRain(Image *rain);
void initcredits(Image* credits);


#endif 

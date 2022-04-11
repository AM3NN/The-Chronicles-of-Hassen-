#ifndef enemy_H
#define enemy_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 800
#define SCREEN_H 400
typedef struct  {
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface * img;
int direction; //0:droite , 1:gauche
} enemy;
void initenemy(enemy *e);
void afficher(enemy e, SDL_Surface * screen);
void animerenemy(enemy * e);
void deplacer(enemy * e);
//int collisionBB(personne p,Ennemi e);
void initbackg(enemy* A);
void afficherenemy(enemy e, SDL_Surface * screen);
void liberer(enemy e);
#endif // APP6_H_INCLUDED



#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <SDL/SDL_timer.h>


typedef struct  {
SDL_Rect pos1;// position perso

 SDL_Rect animation_perso[60];
//tableau d'animation
SDL_Surface*img; //spritesheet
int direction;// 1:droite || 2:gauche
int compteur;// compteur du tableau d'animation
int etat; // mvt:1 || stable:0 
int score;
int vie;
double vitesse;
double vx;
double vgrav ;
double vsaut ;
double vy ; 
int previousmvt; 
int acceleration;

} perso;

void init_animation_perso(SDL_Rect *animation);
void initPerso(perso* p);
void afficher_perso(perso p, SDL_Surface *screen);
void deplacerPerso(perso *p ,SDL_Surface *screen,int dt);
void animer_mvt_perso_droite(perso *p);
void animer_mvt_perso_gauche(perso *p);
void animer_perso_stable_droite(perso *p);
void animer_perso_stable_gauche(perso *p);
void vdown(perso *p);
void apply_acceleration(perso *p, Uint32 dy);
void teleport_front(perso *p);
void teleport_back(perso *p);
void vitesseUP(perso *p);
void vitesseDOWN(perso *p);
void liberer (perso A);
void saut(perso *p);
void sautgauche(perso *p);


#endif 

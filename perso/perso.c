#include "perso.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>


void init_animation_perso(SDL_Rect *animation){

//init width and height
for (int i=0;i<60;i++){
animation[i].w=100; //width
animation[i].h=100; //height
}

//init les x et les y
//ligne 1
for (int i=0; i<15;i++){
animation[i].x=i*100;
animation[i].y=0;
}

//ligne 2
for (int i=15; i<30;i++){
animation[i].x=(i-15)*100;
animation[i].y=100;
}

//ligne 3
for (int i=30; i<45;i++){
animation[i].x=(i-30)*100;
animation[i].y=200;
}

//ligne 4
for (int i=45; i<60;i++){
animation[i].x=(i-45)*100;
animation[i].y=300;
}

}


void initPerso(perso* p){
{
	p->img=IMG_Load("run.png");
	if(p->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	init_animation_perso(p->animation_perso);
	{
	p->pos1.x=0;
	p->pos1.y=700;
	p->score=0;
	p->vie=0;
	p->compteur=0;
	p-> etat=0;
	p->direction=0;
	p->vitesse=3;
	p->acceleration=0;
	p->vx = 4;    
	p->vsaut = -5.5;
        p->vgrav = 0.5;
       p->vy = p->vsaut;
       p->previousmvt=0;
	}
	}
        }

void animer_mvt_perso_droite(perso *p){

p->compteur++;
//si out of range retour a la 1ere case || range de la case 0 -> 14
if (p->compteur<0 || p->compteur>14) 
p->compteur=0;

}

void animer_mvt_perso_gauche(perso *p){

p->compteur++;
//si out of range retour a la 1ere case || range de la case 15 -> 29
if (p->compteur<15 || p->compteur>29)
 p->compteur=15;

}

void animer_perso_stable_droite(perso *p){

 p->compteur++;

//si il regarde vert droite
if(p->direction==1)
//si out of range retour a la 1ere case || range de la case 30 -> 44
if (p->compteur<30 || p->compteur>44) p->compteur=30;
}
void animer_perso_stable_gauche(perso *p){
p->compteur++;
//si regarde vers gauche
if(p->direction==2)
//si out of range retour a la 1ere case || range de la case 45 -> 59
if (p->compteur<45 || p->compteur>59) p->compteur=45;

}

void deplacerPerso(perso *p ,SDL_Surface *screen,int dt){ 


	if(dt!= p->previousmvt)
	{
		p->direction=0;
		p->previousmvt = p->direction;

	}
	if (dt==1){
		p->pos1.x+=p->vitesse; 
		p->direction=dt;
               animer_mvt_perso_droite(p);
	}
 	if (dt==2){
   		p->pos1.x-=p->vitesse;
   		p->direction=dt;
               animer_mvt_perso_gauche(p);
	
	}
	
	if (dt==3){
		 
		p->pos1.y-=2; 
	 
	}
	
}




void afficher_perso(perso p, SDL_Surface *screen){
SDL_BlitSurface(p.img,&p.animation_perso[p.compteur],screen,&p.pos1);
}

void saut(perso *p){
	
	if(p->pos1.y<700){
   	p->pos1.x += p->vx;
   	p->pos1.y+= p->vy;
   	p->vy += p->vgrav;
   }
  	if (p->pos1.y> 700)
    	p->vy = p->vsaut;
}
void sautgauche(perso *p){
	if(p->pos1.y<700){
   	p->pos1.x -= p->vx;
   	p->pos1.y+= p->vy;
   	p->vy += p->vgrav;
   }
  	if (p->pos1.y> 700)
    	p->vy = p->vsaut;


}
/*void apply_acceleration(perso *p, Uint32 dy){
int vitesse_max=15;
  if (p->acceleration%2==0) {
p->acceleration=0;
    p->vx=2;
  }
if(p->acceleration%2==1)
{
  if(p->vx<vitesse_max)
{
p->acceleration=100;
  p->vx+=0.5*p->acceleration*dy*dy/1000/1000+p->vx*dy/1000;
}
}
}*/
void vdown(perso *p){
 	p->vitesse=0; 

}
void teleport_front(perso *p){

  p->pos1.y-=p->vy;
  p->pos1.x+=200;
}
void teleport_back(perso *p){
  p->pos1.y-=p->vy;
  p->pos1.x-=200;
}
void vitesseUP(perso *p){
	 SDL_Delay(10);
        p->acceleration+=0.005;
         p->vitesse+=p->acceleration;
         p->pos1.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
		p->acceleration-=0.01;
         }
}
void vitesseDOWN(perso *p){

	

      
      p->vitesse=0;
 animer_perso_stable_droite(p);

}

void liberer (perso A)
	{
	SDL_FreeSurface(A.img);
	}


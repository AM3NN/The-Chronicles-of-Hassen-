#include "perso.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void initPerso(personne* p){
{
	p->img=IMG_Load("000.png");
	if(p->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	p->pos1.x=3;
	p->pos1.y=775;
	
	}
	}

}
void deplacer(int carte[][26], SDL_Rect* pos , int direction){
      	switch (direction){
      	case HAUT:
      	pos->y--;
      	break;
      	case BAS:
      	pos->y++;
      	break;
      	case GAUCHE:
      	pos->x--;
      	break;
      	case DROITE:
      	pos->x++;
      	break;
      	}
      	}

	void afficher(personne p1, SDL_Surface *screen)
	{
	    SDL_BlitSurface(p1.img, &p1.pos2, screen, &p1.pos1);
	    
	}

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#include "perso.h"
#include <math.h>
int main (int argc,char** argv)
	{
            SDL_Surface *p1 = NULL,*screen=NULL;
             perso p;
             Uint32 dy;
		int dt=0;
		int s=0;
	    SDL_Rect positionp,positionp1;
	    SDL_Event event;
	    int bl=0;
	    int continuer = 2;
	
	    p1= IMG_Load("bgplay.png");
	    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	    positionp.x = 0;
	    positionp.y = 0;
	    initPerso(&p);
	    SDL_EnableKeyRepeat(10, 0);
	    while (continuer)
	    {
		while(SDL_PollEvent(&event)){
		switch (event.type)
		{
		
		case SDL_KEYDOWN:
		    switch (event.key.keysym.sym)
		    {
		    
		case SDLK_ESCAPE:
		        continuer = 0;
		         break;
		         
		case SDLK_d: 
		{
               	if(dt=1){
               	deplacerPerso(&p ,screen,dt);
               	s=1;
               	}
               	
		break;
		
		  }
			
		case SDLK_q: 
		{
               	if(dt=2){
               	deplacerPerso(&p ,screen,dt);
               	s=2;
          }
		break;
		}
		case SDLK_SPACE:
		 {
			dt=3;
               	deplacerPerso(&p ,screen,dt);
		break;
		case SDLK_z:
		animer_perso_stable_gauche(&p);
		break;
		case SDLK_e:
                animer_perso_stable_droite(&p);
                 break;
		case SDLK_UP:
               vitesseUP(&p);
		break;
		case SDLK_DOWN:
		vitesseDOWN(&p);
		break;
		
		
		
		
		case SDLK_LSHIFT:
	
	        teleport_front(&p);
		break;
		case SDLK_RSHIFT:
		teleport_back(&p);
		break;
		




               
		}
		}
		}

		SDL_BlitSurface(p1, NULL, screen, &positionp);
               afficher_perso(p,screen);
               if(s==1){
               saut(&p);
               }
               if (s==2){
               sautgauche(&p);
               }
		SDL_Flip(screen);
		SDL_Flip(p1);
	    }
	    }
	    liberer(p);
	    SDL_FreeSurface(p1);
	    	SDL_Quit();
	    	
          return 0;
}  



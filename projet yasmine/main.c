#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "minimap.h"
#define SCREEN_W 1920
#define SCREEN_H 1080

int main(int argc,char **argv)
{ 	int temps=50;
        int accel=25;
	int continuer=1;
	minimap m;
	timeUp t;
	SDL_Event event;
	char nomjoueur[10],nomfichier[10];
	int score=0;
	

	//initialisation son
	Mix_Chunk* son;
	int volume=100;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	son= Mix_LoadWAV("timeUp.wav");
	

	//declaration de la fenetre  :
	SDL_Surface *screen=NULL;

	//initialisation
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	//screen set
	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	//test MAJminimap
	SDL_Surface *Joueur=NULL;
	Joueur=IMG_Load("Joueur.png");
	SDL_Rect posJoueur;
	posJoueur.x=20;
	posJoueur.y=700;

	SDL_Surface *background=NULL;
	background=IMG_Load("Tuto.png");
	SDL_Rect posbackg;
	posbackg.x=0;
	posbackg.y=0;
	

	int redimensionnement=20;

	SDL_Rect camera;
	camera.x=0;
	camera.y=0;

	//intialisation minimap et time up
	initminimap(&m);
	inittimeup(&t);
	


SDL_EnableKeyRepeat(1,1);

while(continuer==1)
{
SDL_BlitSurface(background,NULL,screen,&posbackg);
SDL_BlitSurface(Joueur,NULL,screen,&posJoueur);
afficher (m,screen);
affichertemps(temps,screen);
if(temps!=0)
	{       if(accel!=0)
		{
			accel--;
		}
		if(accel==0)
		{
			temps--;
			accel=50;
			
		}
		if((temps<=5)&&(temps!=0))
		{
		//Mix_PlayChannel( -1, son, 0);
		}
	}
if(temps==0)
{
affichertimeup (t,screen);	
}


while(SDL_PollEvent(&event))
{
	switch (event.type)
		   {
		case SDL_QUIT:
		continuer = 0;
		break;
		case SDL_KEYDOWN:


 	switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		        continuer = 0;
		         break;

			case  SDLK_d :            
			 posJoueur.x=posJoueur.x+20;
              break;             
			 case SDLK_q :
                          
                                        
			 posJoueur.x=posJoueur.x-20;
                            
	break;

		   

		    }
break;
		   }
	        }

MAJMinimap(posJoueur,&m,camera,redimensionnement);
//sauvegarder(score,nomjoueur,nomfichier,screen);
meilleur(nomfichier,&score,nomjoueur);

SDL_Flip (screen);


}



SDL_EnableKeyRepeat(0,0);
Mix_FreeChunk(son);
SDL_FreeSurface(screen);
liberer(&m);
SDL_Quit();
return 0;
}

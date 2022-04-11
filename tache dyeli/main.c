#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_mixer.h>
#include "enemy.h"
int main (int argc,char** argv)
{
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
SDL_Surface *screen;
enemy A,backg;
SDL_Event event;
int continuer=1;
int PosMax=500;
int PosMin=0;
screen = SDL_SetVideoMode (800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
initenemy(&A);
initbackg(&backg);
while (continuer)
{
afficher(backg,screen);
afficherenemy(A,screen);
deplacer(&A);
while(SDL_PollEvent(&event))
		{
		switch (event.type)
		{     	  
		case SDL_QUIT:
		continuer = 0;
		break;
		}
		}
SDL_Flip(screen);
}
liberer(A);
liberer(backg);
return 0;
}

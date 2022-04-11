#include"fonction.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"

int main (int argc,char** argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	printf ("ERROR 404 :( %s\n",SDL_GetError());
	exit(EXIT_FAILURE);
	}

	int collide;
	SDL_Surface *screen;
	int continuer = 1;
	int direction;
	background b,animer,masque;
	Mix_Music *wind;
	Personne p;
	SDL_Event event;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	screen = SDL_SetVideoMode (SCREEN_W,SCREEN_H,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	wind=Mix_LoadMUS("/home/mahdi/Desktop/Task BG/res/wind.mp3");
	Mix_PlayMusic(wind, -1);
	//collide = collisionPP (p,masque.masque);
	initbackground (&b);
	initmasque (&masque);
	//initchest(&c);
	//initperso(&p);
	animerBackground (&animer);
	SDL_EnableKeyRepeat (1,1);

	while (continuer)
	{

		afficherBack (b,screen);
		//afficherimage(c,screen);
		//afficherimage(p,screen);
		afficheranim (animer,screen);
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
		    case SDLK_d:
			{
		    	direction = 1;
			scrolling (&b,direction,20);
			}
			break;
		    case SDLK_q:
			{
			direction = 2;
			scrolling (&b,direction,20);
			}
			break;
		    case SDLK_z:
			{
			direction = 4;
			scrolling (&b,direction,20);
			}
			break;
		    case SDLK_s:
			{
			direction = 3;
			scrolling (&b,direction,20);
			}
			break;
		    }
		   }
	        }
	SDL_Flip(screen);
	}
liberer (b);
liberer (masque);
return 0;
}


	#include"menu.h"
	#include <stdio.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_ttf.h>
	#include <SDL/SDL_timer.h>
	#include <SDL/SDL_mixer.h>
	int main (int argc,char** argv)
	{
	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_Surface *screen,exittest;
	int continuer=1;
	Image backg,option,play,exit,play1,option1,exit1,bgsettings,bgplay,rain;
	Mix_Music *music;
	SDL_Event event;
	Mix_Chunk* son;
	int volume=100;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	son=Mix_LoadWAV("/home/amen/Desktop/projet/res/click.wav");
	screen = SDL_SetVideoMode (SCREEN_W,SCREEN_H,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	
	music=Mix_LoadMUS("/home/amen/Desktop/projet/res/menu.mp3");
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(volume);
	Mix_VolumeChunk(son,volume);
	initbackg(&backg);
	initplay(&play);
	initoption(&option);
	initexit(&exit);
	initplay1(&play1);
	initoption1(&option1);
	initexit1(&exit1);
	initbackgs(&bgsettings);
	initp(&bgplay);
	initRain(&rain);
		while (continuer)
		{
		
		afficher(backg,screen);
		afficher(play,screen);
		afficher(option,screen);
		afficher(exit,screen);
		afficher(rain,screen);
		if ( rain.pos1.y<0)
                   rain.pos1.y=rain.pos1.y+50;
                     else rain.pos1.y=-100;
                           SDL_Delay(60);
                         SDL_Flip(screen);
                         
		while(SDL_PollEvent(&event))
		{
		switch (event.type)
		{     	  
		case SDL_QUIT:
		continuer = 0;
		break;
		case SDL_KEYDOWN:
		
		switch(event.key.keysym.sym )
		{
		case SDLK_ESCAPE:
		continuer=0;
		break;
		case SDLK_EQUALS:
		
			if(volume >=0 && volume<=75){
				if (volume==0){Mix_ResumeMusic();}
				volume+=25;
				Mix_VolumeMusic(volume);
				Mix_VolumeChunk(son,volume);}
				break;
		
		case SDLK_RIGHTPAREN:
		if(volume>0&&volume<=100){
				volume-=25;
				Mix_VolumeMusic(volume);
				Mix_VolumeChunk(son,volume);
				if (volume==0){Mix_PauseMusic();}}
				
				break;
				case SDLK_m:
				Mix_PauseMusic();
				break;
			case SDLK_r:
			Mix_ResumeMusic();
			break;
			
		case SDLK_s:
		Settings(screen);
		break;
		case SDLK_p:
		playp(screen);
		break;
		}
		case SDL_MOUSEMOTION:
		{
		if(event.motion.x>play.pos1.x && event.motion.x<play.pos1.x+play.pos2.w && event.motion.y>play.pos1.y && event.motion.y<play.pos1.y+play.pos2.h)
		{
		afficher(play1,screen);
		}
		if(event.motion.x>option.pos1.x && event.motion.x<option.pos1.x+option.pos2.w && event.motion.y>option.pos1.y && event.motion.y<option.pos1.y+option.pos2.h)
		{
		afficher(option1,screen);
		}
		if( event.motion.x>exit.pos1.x && event.motion.x<exit.pos1.x+exit.pos2.w && event.motion.y>exit.pos1.y && event.motion.y<exit.pos1.y+exit.pos2.h)
		{
		afficher(exit1,screen);
		}
		break;
		}
		case SDL_MOUSEBUTTONUP:
		 
	        {if (event.button.button == SDL_BUTTON_LEFT){
		if(event.button.x>=play.pos1.x && event.button.x<=play.pos1.x+play.pos2.w && event.button.y>=play.pos1.y && event.button.y<=play.pos1.y+play.pos2.h){
		Mix_PlayChannel(-1,son,0);
		playp(screen);
		}
		if (event.button.button == SDL_BUTTON_LEFT){
		if(event.button.x>=option.pos1.x && event.button.x<=option.pos1.x+option.pos2.w && event.button.y>=option.pos1.y && event.button.y<=option.pos1.y+option.pos2.h){
		Mix_PlayChannel(-1,son,0);
		Settings(screen);
		}
		}
		if (event.button.button == SDL_BUTTON_LEFT){
		if( event.button.x>=exit.pos1.x && event.button.x<=exit.pos1.x+exit.pos2.w && event.button.y>=exit.pos1.y && event.button.y<=exit.pos1.y+exit.pos2.h){
		
		Mix_PlayChannel(-1,son,0);
		continuer =0;
		break;
		}
		}
		break;
		}
		}
		}
		}

		SDL_Flip(screen);
		}
	liberer(backg);
	liberer(play);
	liberer(option);
	liberer(exit);
	liberer(play1);
	liberer(option1);
	liberer(exit1);
	liberer(rain);
	liberer(bgsettings);
	Mix_FreeMusic(music);
	Mix_FreeChunk(son);
	return 0;
	}

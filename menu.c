	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_ttf.h>
	#include <SDL/SDL_mixer.h>
	#include "menu.h"
	void initRain(Image *rain)
	{
	rain->img=IMG_Load("/home/amen/Desktop/projet/res/rain.png");
      if (rain->img==NULL ){
      printf("Unable to load image: %s\n",SDL_GetError());
      }
      {
      rain->pos1.x=0;
      rain->pos1.y=-100;
      rain->pos2.x=0;
      rain->pos2.y=0;
      rain->pos2.w=rain->img->w;
      rain->pos2.h=rain->img->h; 
      
     	 }
	}
	void initbackg(Image* backg)
	{
	backg->img=IMG_Load("/home/amen/Desktop/projet/res/menu.png");
	if(backg->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	backg->pos1.x=0;
	backg->pos1.y=0;
	backg->pos2.w=1920;
	backg->pos2.h=1080;
	}
	}
	void initbackgs(Image* bgsettings)
	{
	bgsettings->img=IMG_Load("/home/amen/Desktop/projet/res/bgsettings.png");
	if(bgsettings->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	bgsettings->pos1.x=0;
	bgsettings->pos1.y=0;
	bgsettings->pos2.w=1920;
	bgsettings->pos2.h=1080;
	}
	}
	
	void initp(Image* bgplay)
	{
	bgplay->img=IMG_Load("/home/amen/Desktop/projet/res/bgplay.png");
	if(bgplay->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	bgplay->pos1.x=0;
	bgplay->pos1.y=0;
	bgplay->pos2.w=1920;
	bgplay->pos2.h=1080;
	}
	}
	void initplay(Image* play)
	{
	play->img=IMG_Load("/home/amen/Desktop/projet/res/play.png");
	if(play->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	play->pos1.x=415;
	play->pos1.y=272;
	play->pos2.w=play->img->w;
	play->pos2.h=play->img->h;
	}
	}
	void initoption(Image* option)
	{
	option->img=IMG_Load("/home/amen/Desktop/projet/res/option.png");
	if(option->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	option->pos1.x=415;
	option->pos1.y=390;
	option->pos2.w=281;
	option->pos2.h=83 ;
	}
	}
	void initexit(Image* exit)
	{
	exit->img=IMG_Load("/home/amen/Desktop/projet/res/exit.png");
	if(exit->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	{
	exit->pos1.x=415;
	exit->pos1.y=508;
	exit->pos2.w=281;
	exit->pos2.h=83 ;
	}
	}
	void initplay1(Image* play1)
	{
	play1->img=IMG_Load("/home/amen/Desktop/projet/res/play1.png");
	if(play1->img==NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}

	play1->pos1.x=415;
	play1->pos1.y=272;
	play1->pos2.w=281;
	play1->pos2.h=83;

	}
	void initcredits(Image* credits)
	{
	credits->img=IMG_Load("/home/amen/Desktop/projet/res/credits.png");
	if(credits->img==NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}

	credits->pos1.x=1203;
	credits->pos1.y=775;
	credits->pos2.w=281;
	credits->pos2.h=83;

	}
	/*void initText(Text *t)
{
    t->position.x = 350;
    t->position.y = 35;
    t->textColor.r = 200;
    t->textColor.g = 150;
    t->textColor.b = 40;
    t->font = TTF_OpenFont("pol.ttf", 50);
}
void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "WELCOME", t.textColor); //ta3tiha message o win theb thoto o el coleur 
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position); //affichage
}
void initText(Text *t)
{
    t->position.x = 350;
    t->position.y = 35;
    t->textColor.r = 200;
    t->textColor.g = 150;
    t->textColor.b = 40;
    t->font = TTF_OpenFont("pol.ttf", 50);
}
void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "WELCOME", t.textColor); //ta3tiha message o win theb thoto o el coleur 
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position); //affichage
    */
	void initoption1(Image* option1)
	{
	option1->img=IMG_Load("/home/amen/Desktop/projet/res/option1.png");
	if(option1->img==NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}

	option1->pos1.x=415;
	option1->pos1.y=390;
	option1->pos2.w=281;
	option1->pos2.h=83 ;


	}
	void initexit1(Image* exit1)
	{
	exit1->img=IMG_Load("/home/amen/Desktop/projet/res/exit1.png");
	if(exit1->img==NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}

	exit1->pos1.x=415;
	exit1->pos1.y=508;
	exit1->pos2.w=281;
	exit1->pos2.h=83;
	}
	void Settings(SDL_Surface *screen)
	{
	    SDL_Surface *Seting = NULL,*credits=NULL,*credits1=NULL,*fullscreen=NULL,*windowed=NULL,*controls=NULL,*volume=NULL;
	    SDL_Rect positionSeting,positioncredits,positioncredits1,positionfullscreen,positionwindowed,  positioncontrols,positionvolume;
	    SDL_Event event;
	    int continuer = 2;
	    credits=IMG_Load("/home/amen/Desktop/projet/res/credits.png");
	    positioncredits.x=1203;
	     positioncredits.y=775;
	     positioncredits.w=281;
	      positioncredits.h=83;
	      fullscreen=IMG_Load("/home/amen/Desktop/projet/res/Fullscreen.png");
	    positionfullscreen.x=756;
	     positionfullscreen.y=433;
	      windowed=IMG_Load("/home/amen/Desktop/projet/res/windowed.png");
	    positionwindowed.x=1203;
	     positionwindowed.y=433;
	     controls=IMG_Load("/home/amen/Desktop/projet/res/controls.png");
	    positioncontrols.x=756;
	     positioncontrols.y=775;
	   volume=IMG_Load("/home/amen/Desktop/projet/res/volume.png");
	    positionvolume.x=598;
	     positionvolume.y=604;
	      credits1=IMG_Load("/home/amen/Desktop/projet/res/credits1.png");
	    positioncredits1.x=1203;
	     positioncredits1.y=775;
	    Seting = IMG_Load("/home/amen/Desktop/projet/res/bgsettings.png");
	    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	    positionSeting.x = 0;
	    positionSeting.y = 0;
	    
	    while (continuer)
	    {
		while(SDL_PollEvent(&event)){
		switch (event.type)
		{
		case SDL_KEYDOWN:
		    switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		        continuer =0;
		        break;
		    }
		    }
		    break;
		}
		SDL_BlitSurface(Seting, NULL, screen, &positionSeting);
		SDL_BlitSurface(credits, NULL, screen, &positioncredits);
		SDL_BlitSurface(fullscreen, NULL, screen, &positionfullscreen);
		SDL_BlitSurface(windowed, NULL, screen, &positionwindowed);
		SDL_BlitSurface(controls, NULL, screen, &positioncontrols);
		SDL_BlitSurface(volume, NULL, screen, &positionvolume);
		SDL_Flip(screen);
	    }
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(fullscreen);
	      SDL_FreeSurface(windowed);
	       SDL_FreeSurface(controls);
	       SDL_FreeSurface(volume);
	}
           void playp(SDL_Surface *screen)
      	{
	    SDL_Surface *p = NULL;
	    SDL_Rect positionp,positiontexte;
	    SDL_Event event;
	    int continuer = 2;
	     p= IMG_Load("/home/amen/Desktop/projet/res/bgplay.png");
	    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	    positionp.x = 0;
	    positionp.y = 0;

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
		    }
		    break;
		}
		}
		SDL_BlitSurface(p, NULL, screen, &positionp);
		SDL_Flip(screen);
	    }
	}
	

	void afficher(Image p1, SDL_Surface *screen)
	{
	    SDL_UpperBlit(p1.img, &p1.pos2, screen, &p1.pos1);
	    
	}
	void liberer (Image A)
	{
	SDL_FreeSurface(A.img);
	}


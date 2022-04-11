#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"


//fonction initilation minimap
void initminimap(minimap* m)
{ 
	m->image_minimap=IMG_Load("minimap.png");
	m->position_minimap.x=0;
	m->position_minimap.y=0;
	m->image_bonhomme=IMG_Load("miniJoueur.png");
	m->position_bonhomme.x=0;
	m->position_bonhomme.y=0;
}


//fonction initilation time up
void inittimeup(timeUp* t)
{ 
	t->image_timeUp=IMG_Load("timeUp.png");
	t->position_timeUp.x=350;
	t->position_timeUp.y=90;
}


//fonction maj minimap 
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
	m->position_bonhomme.x=posJoueur.x * redimensionnement/100;
	m->position_bonhomme.y=posJoueur.y * redimensionnement/100;
	posJoueur.x = posJoueur.x + camera.x;
	posJoueur.y = posJoueur.y + camera.y;
	
}


//fonction afficher minimap
void afficher (minimap m, SDL_Surface * screen)
{
	SDL_BlitSurface(m.image_minimap,NULL,screen,&m.position_minimap);
	SDL_BlitSurface(m.image_bonhomme,NULL,screen,&m.position_bonhomme);

}


//afficher time up
void affichertimeup (timeUp t, SDL_Surface * screen)
{
	SDL_BlitSurface(t.image_timeUp,NULL,screen,&t.position_timeUp);	
}


//fonction afficher temps

void affichertemps(int temps ,SDL_Surface *screen)
{
   
    TTF_Init();

    char *s;

    TTF_Font *police=NULL;
    SDL_Surface *txt;
    police=TTF_OpenFont("arial.ttf",30);
    SDL_Color couleur= {0,0,0};
    SDL_Rect postemps;
    postemps.x=0;
    postemps.y=0;


    sprintf(s,"Time: %d",temps);

    txt=TTF_RenderText_Blended(police,s,couleur);


    SDL_BlitSurface(txt,NULL,screen,&postemps);

    SDL_FreeSurface(txt);
  

TTF_CloseFont (police); 
TTF_Quit();
     

}


void liberer(minimap *m)
{
	SDL_FreeSurface(m->image_minimap);
	SDL_FreeSurface(m->image_bonhomme);
}


//fonction sauvegarder

void sauvegarder(int score, char nomjoueur[], char nomfichier[],SDL_Surface *screen)
{
TTF_Init();
int i=0;//,done=1;
char *test;
SDL_Event event;

    TTF_Font *police=NULL;
    SDL_Surface *txt;
    police=TTF_OpenFont("arial.ttf",30);
    SDL_Color couleur= {0,0,0};
    SDL_Rect posnomjoueur;
    posnomjoueur.x=0;
    posnomjoueur.y=0;

SDL_Surface *backclavier=NULL;
backclavier=IMG_Load("backclavier.jpg");
SDL_Rect pos_backclavier;
pos_backclavier.x=0;
pos_backclavier.y=0;

SDL_Surface *clavier=NULL;
clavier=IMG_Load("clavier.png");
SDL_Rect pos_clavier;
pos_clavier.x=200;
pos_clavier.y=120;


FILE *F=NULL;
F=fopen ("nomfichier.txt","w");
if (F!=NULL)
{
//while(done==1)
//{

SDL_BlitSurface(backclavier,NULL,screen,&pos_backclavier);
SDL_BlitSurface(clavier,NULL,screen,&pos_clavier);

while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_KEYDOWN:
                                     if(i<10)
{
             if(event.key.keysym.sym == SDLK_a)
                                       {
                                        strcat(nomjoueur,"a");
i++;

                                       }
else if(event.key.keysym.sym == SDLK_b)
                                       {
                                        strcat(nomjoueur,"b");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_i)
                                       {
                                        strcat(nomjoueur,"i");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_c)
                                       {
                                        strcat(nomjoueur,"c");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_d)
                                       {
                                        strcat(nomjoueur,"d");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_e)
                                       {
                                        strcat(nomjoueur,"e");
i++;
                                       }  
else if(event.key.keysym.sym == SDLK_f)
                                       {
                                        strcat(nomjoueur,"f");
i++;
                                       }
if(event.key.keysym.sym == SDLK_g)
                                       {
                                        strcat(nomjoueur,"g");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_h)
                                       {
                                        strcat(nomjoueur,"h");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_j)
                                       {
                                        strcat(nomjoueur,"j");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_k)
                                       {
                                        strcat(nomjoueur,"k");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_l)
                                       {
                                        strcat(nomjoueur,"l");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_m)
                                       {
                                        strcat(nomjoueur,"m");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_n)
                                       {
                                        strcat(nomjoueur,"n");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_o)
                                       {
                                        strcat(nomjoueur,"o");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_p)
                                       {
                                        strcat(nomjoueur,"p");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_q)
                                       {
                                        strcat(nomjoueur,"q");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_r)
                                       {
                                        strcat(nomjoueur,"r");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_s)
                                       {
                                        strcat(nomjoueur,"s");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_t)
                                       {
                                        strcat(nomjoueur,"t");
i++;
                                       }

else if(event.key.keysym.sym == SDLK_u)
                                       {
                                        strcat(nomjoueur,"u");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_v)
                                       {
                                        strcat(nomjoueur,"v");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_w)
                                       {
                                        strcat(nomjoueur,"w");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_x)
                                       {
                                        strcat(nomjoueur,"x");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_y)
                                       {
                                        strcat(nomjoueur,"y");
i++;
                                       }
else if(event.key.keysym.sym == SDLK_z)
                                       {
                                        strcat(nomjoueur,"z");
i++;

                                       }
    else if(event.key.keysym.sym == SDLK_SPACE)
{
                                        strcat(nomjoueur," ");
i++;

                                       }


}

if((event.key.keysym.sym==SDLK_BACKSPACE)&&(i>0))
 {
  int clock=strlen(nomjoueur)-1;
  test=calloc(clock,sizeof(char));
  strncpy(test,nomjoueur,strlen(nomjoueur)-1);
 
         
  printf("too long= %d ",clock);
  strcpy(nomjoueur,test);
          i--;


 }

/*if(event.key.keysym.sym ==SDLK_ESCAPE)
                                       {

                                        done++;
					//done=0;

                                       }*/



break;



//}

}

}



printf("%s",nomjoueur);
printf("%d",i);

txt=TTF_RenderText_Blended(police,nomjoueur,couleur);
SDL_BlitSurface(txt,NULL,screen,&posnomjoueur);
SDL_FreeSurface(txt);
SDL_Flip(screen);

}

SDL_FreeSurface(screen);
TTF_CloseFont (police);
TTF_Quit();
SDL_Quit();


}

//fonction meilleur score



int meilleur(char nomfichier[], int*score, char nomjoueur[])
{
int max;
char meilleur[10];
FILE *F=NULL;
F=fopen("nomfichier.txt","r");
max=0;
if (F!=NULL)
{
   while (fscanf(F,"%s %d\n",nomjoueur,score)!=EOF)
   {
	if (*score>max)
	{
		max=*score;
		strcpy(meilleur,nomjoueur);
	}

   }

}

fclose(F);
return max;
}






	
	
	

          












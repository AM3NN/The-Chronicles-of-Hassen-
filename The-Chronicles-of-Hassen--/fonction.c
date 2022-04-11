#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include "fichier.h"

void init_enigme( enigme* e )
{
    e->image_enigme = IMG_Load("font.jpg");
    e->position_enigme.x = 0;
    e->position_enigme.y = 0;
    e->resultat = 0;
    e->correct =IMG_Load("true.jpg");
    e->wrong =IMG_Load("false.jpg");
    e->position_correct.x =1440;
    e->position_correct.y =540;
    e->position_wrong.x = 1440;
    e->position_wrong.y = 540;
//chargement
    e->police=TTF_OpenFont("Indy Women.ttf",54 );//chargement 
    e->reponse_1 = NULL;
    e->pos_reponse_1.x=480;
    e->pos_reponse_1.y=810;

    e->reponse_2 = NULL;
    e->pos_reponse_2.x=960;
    e->pos_reponse_2.y=810;

    e->reponse_3 = NULL;
    e->pos_reponse_3.x=1440;
    e->pos_reponse_3.y=810;

    e->police_q=TTF_OpenFont("Indy Women.ttf",54 );

    e->question = NULL;
    e->pos_question.x=480;
    e->pos_question.y=270;
    e->num_enigme = 1;


void afficherenigme ( enigme *e, SDL_Surface* screen)
{
	SDL_BlitSurface(e->image_enigme,NULL, screen, &en->position_enigme );
	SDL_BlitSurface(e->reponse_1,NULL,screen,&en->pos_reponse_1);
        SDL_BlitSurface(e->reponse_2,NULL,screen,&en->pos_reponse_2);
        SDL_BlitSurface(e->reponse_3,NULL,screen,&en->pos_reponse_3);
        SDL_BlitSurface(e->question,NULL,screen,&en->pos_question);
}
void free_surface_enigme( enigme *e )
{
    SDL_FreeSurface(e->image_enigme);
    SDL_FreeSurface(e->correct);
    SDL_FreeSurface(e->wrong);
    SDL_FreeSurface(e->reponse_1);
    SDL_FreeSurface(e->reponse_2);
    SDL_FreeSurface(e->reponse_3);
    SDL_FreeSurface(e->question);
    TTF_CloseFont(e->police);
    TTF_CloseFont(e->police_q);
}

void enigme_generer(enigme *e ,char *fichier)
{
	FILE* fichier = NULL;
	char ques[50] = {0};
	char rep1[30] = {0};
	char rep2[30] = {0};
	char rep3[30] = {0};
	int caracterelu,ligne =1;
	srand(time(0));
	do {
		e->num_enigme = rand()%3 + 1;
	}while ( e->num_enigme <1 || e->num_enigme > 3 );

	fichier = fopen("fichier","r");
	if ( fichier != NULL )
	{
		while ( caracterelu!=EOF && ligne < e->num_enigme )
		{
			caracterelu = fgetc(fichier);
			if ( caracterelu == '\n')
				ligne++;
		}
		fscanf(fichier,"%s %s %s %s",ques, rep1, rep2, rep3);
		printf("%s , %s , %s , %s" , ques, rep1, rep2, rep3);
		fclose(fichier);
	}
	e->question = TTF_RenderText_Blended(e->police_q,ques,ColorMaroon);
	e->reponse_1 = TTF_RenderText_Blended(e->police,rep1,ColorMaroon);
	e->reponse_2 = TTF_RenderText_Blended(e->police,rep2,ColorMaroon);
	e->reponse_3 = TTF_RenderText_Blended(e->police,rep3,ColorMaroon);

}


int resolution(enigme e, SDL_Surface screen )
{
    SDL_Event event;
    int continuer=1;
    SDL_Color Maroon = {128,0,0};
    while(continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;

                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>480 && event.button.x<640 && event.button.y>742.5 && event.button.y<877.5)//reponse1 
                {
			if ( e->num_enigme == 1 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 2 )
			{
				e->resultat= 1;
			}
			else if ( e->num_enigme == 3 )
			{
				e->resultat= 1;
			}
			else if ( e->num_enigme == 4 )
			{
				e->resultat= 2;
			}
                    
                }
                if ( event.button.x>960 && event.button.x<1120 && event.button.y>742.5 && event.button.y<877.5)//reponse2
                {
                    	if ( e->num_enigme == 1 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 2 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 3 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 4 )
			{
				e->resultat= 1;
			}
                }
                if ( event.button.x>1440 && event.button.x<1600 && event.button.y>742.5 && event.button.y<877.5)//reponse3 
                {
                    	if ( e->num_enigme == 1 )
			{
				e->resultat= 1;
			}
			else if ( e->num_enigme == 2 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 3 )
			{
				e->resultat= 2;
			}
			else if ( e->num_enigme == 4 )
			{
				e->resultat= 2;
			}
                }
            }
            break; 
            }
        }
        break;

 void resolution (int *r )
{
	SDL_Event event ;
  	int continuer=1;
	
	while(continuer)
	{SDL_WaitEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
		continuer=0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  *r= 1;
				continuer=0;
			   break ;
			   case  SDLK_z:
			   *r= 2;
				continuer=0;
			   break;
			   case SDLK_e: 
			   *r=3 ;
			continuer=0;
			  break;
			    }
       break ;

                 
	}
	}
	
  
}
        }
        afficher_enigme ( e, screen);

        if ( e->resultat == 1 )
        {
            SDL_BlitSurface(e->correct,NULL, screen, &e->position_correct );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;
	
	    return 1;
        }
        else if ( e->resultat == 2 )
        {
            SDL_BlitSurface(e->wrong,NULL, screen, &e->position_wrong );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;

	    return 2;
        }
        
        SDL_Flip(screen);


    }

}


















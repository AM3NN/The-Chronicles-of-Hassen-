#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
int main()
{
TTF_Init();
SDL_Surface *screen;
SDL_Event event;   
SDL_Rect  pos_reponse_1,pos_reponse_2,pos_reponse_3,pos_question;
enigme  e; 

 e->image_enigme = IMG_Load("font.jpg");
    e->position_enigme.x = 0;
    e->position_enigme.y = 0;
    e->resultat = 0;
}

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

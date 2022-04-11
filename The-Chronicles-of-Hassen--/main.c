#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#include "enigme.h"
int main (int argc,char** argv)
        {
            SDL_Surface *p1 = NULL,*screen=NULL;
             enigme e;
            
            SDL_Event event;
            int bl=0;
            int continuer = 2;

            p1= IMG_Load("bgplay.png");
            screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
            positionp.x = 0;
            positionp.y = 0;
            initenigme(&p);
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
                if(dt=1)
                deplacerPerso(&p ,screen,dt);
                else
                animer_perso_stable_droite(&p);

                break;

                  }
                  case SDLK_s:
                dt=0;
                deplacerPerso(&p ,screen,dt);

                case SDLK_q:
                {
                if(dt=2)
                deplacerPerso(&p ,screen,dt);
                else
                                animer_perso_stable_gauche(&p);

                break;
                }
                case SDLK_SPACE:
                 {
                        dt=3;
                deplacerPerso(&p ,screen,dt);
                break;
                case SDLK_UP:
               apply_acceleration(&p, dy);
                break;

                case SDLK_DOWN:
                vdown(&p);
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
               saut(&p);
                SDL_Flip(screen);
            }
            }
            liberer(p);
            SDL_FreeSurface(p1);
                SDL_Quit();

          return 0;
}

#include <SDL/SDL.h>
#include "enemy.h"
#include <SDL/SDL_image.h>
void initenemy(enemy* A)
	{
	A->img=IMG_Load("/home/iheb/Desktop/tache dyeli/devilcat.png");
	if(A->img==NULL) {
	printf("unable to load img : %s\n", SDL_GetError());
	}
	A->pos1.x=300;
	A->pos1.y=300;
	
	A->pos2.w=219; //nb colonnes;tet3ada taswira li baed
	A->pos2.h=230; //nb de lignes;tbadel el direction mtaa el animation
	}
void initbackg(enemy* backg)
	{
	backg->img=IMG_Load("/home/iheb/Desktop/tache dyeli/forest-800x600.png");
	if(backg->img == NULL){
	printf("unable to load bitmap : %s\n", SDL_GetError());
	}
	
	backg->pos1.x=0;
	backg->pos1.y=0;
	backg->pos2.w=800;
	backg->pos2.h=600;
	
	}
void afficher(enemy e, SDL_Surface * screen)
	{
	    SDL_BlitSurface(e.img, &e.pos2, screen, &e.pos1);
	    
	} 
void afficherenemy(enemy e, SDL_Surface * screen)
	{
	    SDL_BlitSurface(e.img, NULL, screen, &e.pos1);
	    
	}
void liberer(enemy e)
	{
	SDL_FreeSurface(e.img);
	}
void deplacer(enemy * e)
	{
	int PosMax=500;
	int PosMin=0;
	if (e->pos1.x>PosMax)
		e->direction=0;
	if (e->pos1.x<PosMin)
		e->direction=1;
	if (e->direction==0)
		e->pos1.x--;
	else
		e->pos1.x++;
	}
/*int collisionBB(personne p,enemy e)
	{
	if((p.pos1.x+100<e.pos1.x) || (p.pos1.x>e.pos1.x+e.pos2.w) || (p.pos1.y+100<e.pos1.y) || (p.pos1.y>e.pos1.y+e.pos2.h)
	collision=0;
	else 
	collision=1;
	return collision;
	}
*/

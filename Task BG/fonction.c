#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"

//initialisation du background
	void initbackground (background *b)
{
b->img=IMG_Load("/home/mahdi/Desktop/Task BG/res/Tuto.png");
if (b->img == NULL)
{
printf("unable to load Image : %s\n", SDL_GetError());
}
b->pos.x=0;
b->pos.y=0;
b->pos_camera.x=0; 
b->pos_camera.y=500;
b->pos_camera.w = 1920;
b->pos_camera.h = 1080;
}

//initialisation du masque
void initmasque (background *b)
{
b->masque = IMG_Load("/home/mahdi/Desktop/Task BG/res/masque.png");
if (b->masque == NULL)
{
printf ("unable to load Image : %s\n", SDL_GetError());
}
b->pos.x = 0;
b->pos.y = 0;
}

/*
void initchest (image *c)
{
c->pic = IMG_Load ("/home/mahdi/Desktop/Task BG/res/Chest.png");
if (c->pic==NULL)
{
printf ("unable to load Image : %s\n", SDL_GetError());
}
c->pos.x = 1065;
c->pos.y = 809;
c->pos.x = 170;
c->pos.y = 30;
}
*/
/*
	void initperso(image *p)
{
p->pic=IMG_Load("/home/mahdi/Desktop/Task BG/res/ps.png");
if (p->pic == NULL)
{
printf ("unable to load hassen : %s\n",SDL_GetError());
}
p->pos.x=193;
p->pos.y=809;
}
*/
	void afficherBack (background b, SDL_Surface * screen)
{
SDL_BlitSurface(b.img, &b.pos_camera, screen, &b.pos);
}

	/*void afficherimage (image img, SDL_Surface * screen)
{
SDL_BlitSurface(img.pic,NULL, screen, &img.pos);
}
*/
	void afficheranim (background e, SDL_Surface * screen)
{
SDL_BlitSurface(e.img,NULL,screen,&e.pos);
}

SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y)
{
	SDL_Color color;

	Uint32 col=0;

	char* pPosition=(char*)pSurface->pixels;

	pPosition+=(pSurface->pitch *y);
	pPosition+=(pSurface->format->BytesPerPixel *x);

	memcpy(&col,pPosition,pSurface->format->BytesPerPixel);

	SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);

return(color);
}

int collisionPP (Personne p, SDL_Surface * masque)
{
SDL_Color couleur_obs;
SDL_Color green = {106, 189, 69};
SDL_Rect tab[9];

tab[0].x=p.pos.x;
tab[0].y=p.pos.y;

tab[1].x=p.pos.x+(p.pos.w)/2;
tab[1].y=p.pos.y;

tab[2].x=p.pos.x+p.pos.w;
tab[2].y=p.pos.y;

tab[3].x=p.pos.x;
tab[3].y=p.pos.y+(p.pos.h)/2;

tab[4].x=p.pos.x;
tab[4].y=p.pos.y+p.pos.h;

tab[5].x=p.pos.x+(p.pos.w)/2;
tab[5].y=p.pos.y+p.pos.h;

tab[6].x=p.pos.x+p.pos.w;
tab[6].y=p.pos.y+p.pos.h;

tab[7].x=p.pos.x+p.pos.w;
tab[7].y=p.pos.y+(p.pos.h)/2;

int collision = 0, i=0;
while ((collision == 0) && (i<8))
{

if(green.r == GetPixel(masque,tab[i].x,tab[i].y).r && green.g == GetPixel(masque,tab[i].x,tab[i].y).g && green.b == GetPixel(masque,tab[i].x,tab[i].y).b)
{
	collision=1;
	
}
else
{
	i++;
}

}
	return collision;
}

void scrolling (background * b, int direction, int pasAvancement)
{
	/*Personne p;
	int collide;
	collide = collisionPP (p,b->masque);*/
	if (direction==1)
	b->pos_camera.x += pasAvancement;
	if (direction==2)
	b->pos_camera.x -= pasAvancement;
	if (direction==3)
	b->pos_camera.y += pasAvancement;
	if (direction==4)
	b->pos_camera.y -= pasAvancement;
	
}

void animerBackground (background * e)
{
		e->tab[0] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire1.png");
		e->tab[1] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire2.png");
		e->tab[2] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire3.png");
		e->tab[3] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire4.png");
		e->tab[4] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire5.png");
		e->tab[5] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire6.png");
		e->tab[6] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire7.png");
		e->tab[7] = IMG_Load ("/home/mahdi/Desktop/Task BG/res/fire8.png");
		e->tab1=0;
		e->pos.x = 0;
		e->pos.y = -220;
}

void liberer (background b)
{
	SDL_FreeSurface (b.img);
}


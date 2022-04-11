#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

struct enigme
{
	SDL_Surface* image_enigme;
	SDL_Rect position_enigme;
	int resultat;
	SDL_Surface *correct,*wrong;
	SDL_Rect position_correct,position_wrong;
	TTF_Font *police,*police_q;
	SDL_Surface *reponse_1,*reponse_2,*reponse_3,*question;
	SDL_Rect  pos_reponse_1,pos_reponse_2,pos_reponse_3,pos_question;
	int num_enigme;
	
};
typedef struct enigme enigme;
void init_enigme( enigme* en );
void afficher_enigme ( enigme *en, SDL_Surface* screen);
void free_surface_enigme( enigme *en );
void enigme_generer(enigme *en ,char *fichier);
#endif // ENIGME_H_INCLUDED

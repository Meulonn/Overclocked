#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
{
	int continuer = 1,test=1;
	int up=0,down=0;
	int volume=5;
	int x1,x2,x3,x4;




SDL_Surface *ecran = NULL, *ecran2= NULL;
SDL_Surface *image1 = NULL,*image1G = NULL, *image2 = NULL, *image2G = NULL,*image3 = NULL, *image3G = NULL,*image_backg = NULL,*options = NULL;
SDL_Surface *texte = NULL,*quitter = NULL;
 

SDL_Rect posimage, posimage1, posimage2, posimage3, posimage1G, posimage2G, posimage3G,posoptions;
SDL_Rect postexte, postexteG,posquitter;


Mix_Music *musique; 
Mix_Chunk *bref;
Mix_AllocateChannels(32);


SDL_Event event;
   

TTF_Font *police;
	SDL_Color policeNoire = {0,0,0};
 	SDL_Color policeBlanche = {255,255,255}; 
 	SDL_Color policeRouge = {255,0,0};




SDL_Init(SDL_INIT_VIDEO); 
TTF_Init();

police = TTF_OpenFont("Mount Hills.otf",20); 
quitter = TTF_RenderText_Blended(police, "Press 'esc' to quit ", policeNoire);


SDL_WM_SetCaption("Rewind", NULL);


   ecran = SDL_SetVideoMode(1200,627,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   ecran2 = SDL_SetVideoMode(1200,627,32, SDL_HWSURFACE | SDL_DOUBLEBUF);



if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
     { printf("%s", Mix_GetError()); }


   
   musique = Mix_LoadMUS("musique2.mp3");
   Mix_PlayMusic(musique, -1);
   bref = Mix_LoadWAV("son.wav");
   
   image_backg = IMG_Load ("bgcarth.jpg");  
   image1 = IMG_Load ("Asset_1.png");
   image1G = IMG_Load ("Asset_2.png");
   image2 = IMG_Load ("Asset_3.png");
   image2G = IMG_Load ("Asset_4.png");
   image3 = IMG_Load ("Asset_5.png");
   image3G = IMG_Load ("Asset_6.png");
   options = IMG_Load ("bg.png");
	//SDL_LoadBMP("image.bmp");


   posimage.x = 0;
   posimage.y = 0;
   posimage.w = ecran -> w;   
   posimage.h = ecran -> h;

   posimage1.x = 800;
   posimage1.y = 200;
   posimage1.w = ecran -> w;   
   posimage1.h = ecran -> h;

   posimage2.x = 800;
   posimage2.y = 300;
   posimage2.w = ecran -> w;   
   posimage2.h = ecran -> h;

   posimage3.x = 800;
   posimage3.y = 400;
   posimage3.w = ecran -> w;   
   posimage3.h = ecran -> h;

   posimage1G.x = 800;
   posimage1G.y = 200;
   posimage1G.w = ecran -> w;   
   posimage1G.h = ecran -> h;

   posimage2G.x = 800;
   posimage2G.y = 300;
   posimage2G.w = ecran -> w;   
   posimage2G.h = ecran -> h;

   posimage3G.x = 800;
   posimage3G.y = 400;
   posimage3G.w = ecran -> w;   
   posimage3G.h = ecran -> h;

   postexte.x = 50;
   postexte.y = 350;

   posquitter.x = 0;
   posquitter.y = 10;

   posoptions.x = 0;
   posoptions.y = 0;
   posoptions.w = ecran -> w;   
   posoptions.h = ecran -> h;

   SDL_BlitSurface(image_backg, NULL, ecran, &posimage);
   SDL_Flip(ecran);
   SDL_Delay(500);
   SDL_BlitSurface(image3, NULL, ecran, &posimage3);
   SDL_Flip(ecran);
   SDL_Delay(1000);
   SDL_BlitSurface(image2, NULL, ecran, &posimage2); 
   SDL_Flip(ecran);
   SDL_Delay(3100);
   SDL_BlitSurface(image1, NULL, ecran, &posimage1);  
   SDL_Flip(ecran);
   SDL_BlitSurface(texte, NULL, ecran, &postexte); 
   SDL_BlitSurface(quitter, NULL, ecran, &posquitter);
   SDL_Flip(ecran);



   while(continuer)
   {
      SDL_WaitEvent(&event);

      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;

//	INTERFACE OPTIONS 

case SDL_MOUSEBUTTONUP:


if((event.motion.x>800 && event.motion.y>303 && event.motion.x<1162 && event.motion.y<392)&&(event.button.button == SDL_BUTTON_LEFT))
{
SDL_BlitSurface(options, NULL, ecran2, &posoptions);
SDL_Flip(ecran2);
do{

SDL_WaitEvent(&event);
}while(event.key.keysym.sym!=SDLK_s);
SDL_BlitSurface(image_backg,NULL,ecran,&posimage);
 SDL_BlitSurface(image1,NULL,ecran,&posimage1);
 SDL_BlitSurface(image2,NULL,ecran,&posimage2);
 SDL_BlitSurface(image3,NULL,ecran,&posimage3);
 SDL_BlitSurface(quitter, NULL, ecran, &posquitter); 
 SDL_Flip(ecran);
}
break;

//	EVENEMENT SOURIS

case SDL_MOUSEMOTION:
        									if(((event.motion.x>posimage3.x)&&(event.motion.x<posimage3.x+posimage3.w)&&(event.motion.y>posimage3.y)&&(event.motion.y<posimage3.y+posimage3.h)))
 {
 SDL_BlitSurface(image_backg,NULL,ecran,&posimage);
 SDL_BlitSurface(image1,NULL,ecran,&posimage1);
 SDL_BlitSurface(image2,NULL,ecran,&posimage2);
 SDL_BlitSurface(image3G,NULL,ecran,&posimage3G);
 SDL_BlitSurface(quitter, NULL, ecran, &posquitter); 
 SDL_Flip(ecran);
if (test==1)
{
Mix_PlayChannel(1,bref,0);
test=0;

}
}


 if(((event.motion.x>posimage2.x)&&(event.motion.x<posimage2.x+posimage2.w)&&(event.motion.y>posimage2.y)&&(event.motion.y<posimage2.y+posimage2.h)))
 {
 SDL_BlitSurface(image_backg,NULL,ecran,&posimage);
 SDL_BlitSurface(image1,NULL,ecran,&posimage1);
 SDL_BlitSurface(image2G,NULL,ecran,&posimage2);
 SDL_BlitSurface(image3,NULL,ecran,&posimage3);
 SDL_BlitSurface(quitter, NULL, ecran, &posquitter); 
 SDL_Flip(ecran);
if (test==1)
{
Mix_PlayChannel(1,bref,0);
test=0;

}
}


  if(((event.motion.x>posimage1.x)&&(event.motion.x<posimage1.x+posimage1.w)&&(event.motion.y>posimage1.y)&&(event.motion.y<posimage1.y+posimage1.h)))
{
 SDL_BlitSurface(image_backg,NULL,ecran,&posimage);
 SDL_BlitSurface(image1G,NULL,ecran,&posimage1);
 SDL_BlitSurface(image2,NULL,ecran,&posimage2);
 SDL_BlitSurface(image3,NULL,ecran,&posimage3);
 SDL_BlitSurface(quitter, NULL, ecran, &posquitter); 
 SDL_Flip(ecran);
if (test==1)
{
Mix_PlayChannel(1,bref,0);
test=0;

}
}


 if((event.motion.x > posimage.x && event.motion.x<posimage1.x) ||(event.motion.y<posimage1.y && event.motion.y>posimage.y)|| (event.motion.y> posimage3.y+posimage3.h)|| (event.motion.x>posimage1.x+posimage1.w))
{
 SDL_BlitSurface(image_backg,NULL,ecran,&posimage);
 SDL_BlitSurface(image1,NULL,ecran,&posimage1);
 SDL_BlitSurface(image2,NULL,ecran,&posimage2);
 SDL_BlitSurface(image3,NULL,ecran,&posimage3);
  SDL_BlitSurface(quitter, NULL, ecran, &posquitter);
 SDL_Flip(ecran);
test=1;
}
break;
SDL_Flip(ecran);


//	EVENEMENT CLAVIER

	case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			continuer=0;
		break;


	case SDLK_UP:
		do 
		{
			up=up+1;
		if (up==4)
				up=1;

		if (up==1)
		{
		SDL_BlitSurface(image3G,NULL,ecran,&posimage3G);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}	
		else if (up==2)
		{
		SDL_BlitSurface(image2G,NULL,ecran,&posimage2G);
		SDL_BlitSurface(image3,NULL,ecran,&posimage3);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}
		else if (up==3)
		{
		SDL_BlitSurface(image1G,NULL,ecran,&posimage1G);
		SDL_BlitSurface(image2,NULL,ecran,&posimage2);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}		
		}while((event.key.keysym.sym == SDLK_UP) && (up==4) );
		break;


	case SDLK_DOWN:
		do 
		{
			down=down+1;
		if (down==4)
				down=1;
	
		if (down==1)
		{
		SDL_BlitSurface(image1G,NULL,ecran,&posimage1G);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}	
		else if (down==2)
		{
		SDL_BlitSurface(image2G,NULL,ecran,&posimage2G);
		SDL_BlitSurface(image1,NULL,ecran,&posimage1);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}
		else if (down==3)
		{
		SDL_BlitSurface(image3G,NULL,ecran,&posimage3G);
		SDL_BlitSurface(image2,NULL,ecran,&posimage2);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}		
		}while((event.key.keysym.sym == SDLK_DOWN) && (down==4) );
		break;

	case SDLK_F5:
	SDL_WM_ToggleFullScreen(ecran);
	break;


	case SDLK_p:
                            if( Mix_PlayingMusic() == 0 )
                            {
                                Mix_PlayMusic( musique, -1 );
                            }
                            else
                            {
                                if( Mix_PausedMusic() == 1 )
                                {
                                    Mix_ResumeMusic();
                                }
                                else
                                {
                                    Mix_PauseMusic();
                                }
                            }
                            break;

                            
	case SDLK_F9:
                            Mix_HaltMusic();
                            break;



	case SDLK_k:
	volume--;
            
            
	switch(volume)
	{	
		case 0 :
		Mix_PauseMusic();
		case 1 :
			x1= Mix_VolumeMusic(MIX_MAX_VOLUME/10);
			break;

		case 2 :
			x2=Mix_VolumeMusic(MIX_MAX_VOLUME/5);
			break;

		case 3 :
			x3= Mix_VolumeMusic(MIX_MAX_VOLUME/3);
			break;

                case 4 :
			Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			break;

		case 5 :
			Mix_VolumeMusic(MIX_MAX_VOLUME/(3/2));
			break;


	}
		break;

	case SDLK_j:
	volume++;


	switch(volume)
	{
              
              
		case 1 :
			Mix_ResumeMusic();
			break;

		case 2 :
			Mix_VolumeMusic(x1);
			break;

		case 3 :
			Mix_VolumeMusic(x2);
			break;

		case 4 :
			Mix_VolumeMusic(x3);
			break;

		case 5 :
			Mix_VolumeMusic(MIX_MAX_VOLUME);
			break;
	}



       }
      }
   }

	SDL_FreeSurface(image1);
	SDL_FreeSurface(image1G);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image2G);
	SDL_FreeSurface(image3);
	SDL_FreeSurface(image3G);
	SDL_FreeSurface(image_backg);
	SDL_FreeSurface(options);
	SDL_FreeSurface(texte);
	SDL_FreeSurface(quitter);

	TTF_Quit();
	Mix_FreeMusic(musique); 
	Mix_CloseAudio(); 
	SDL_Quit();
	return EXIT_SUCCESS;
}



#ifndef __j1INTROSCENE_H__
#define __j1INTROSCENE_H__

#include "j1Module.h"
#include "p2DynArray.h"
#include "p2Animation.h"

struct SDL_Texture;
class j1GUIelement;
class j1Command;

struct SettingsMenu {

	j1GUIelement* image = nullptr;
	j1GUIelement* exit = nullptr;
	j1GUIelement* button = nullptr;
	j1GUIelement* title = nullptr;
	j1GUIelement* scroll1 = nullptr;
	j1GUIelement* scroll2 = nullptr;
	j1GUIelement* label1 = nullptr;
	j1GUIelement* label2 = nullptr;
};

struct CreditsMenu {
	
	j1GUIelement* button = nullptr;
	j1GUIelement* title = nullptr;
	j1GUIelement* credits = nullptr;
	j1GUIelement* link = nullptr;
};

struct HighscoreMenu {

	j1GUIelement* title = nullptr;
	j1GUIelement* best_score = nullptr;
	j1GUIelement* best_time = nullptr;
	j1GUIelement* button = nullptr;
	j1GUIelement* label1 = nullptr;
	j1GUIelement* label2 = nullptr;

};

class j1IntroScene : public j1Module
{
public:

	j1IntroScene();

	// Destructor
	virtual ~j1IntroScene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool GuiObserver(GUI_Event type, j1GUIelement* element, p2SString txt, p2SString name);

	void AddUIElements();	

public:

	SDL_Texture* texture =nullptr;
	SDL_Texture* title_texture=nullptr;
	SDL_Texture* fire_texture = nullptr;	
	j1GUIelement* play_button= nullptr;
	j1GUIelement* continue_button = nullptr;
	j1GUIelement* exit_button = nullptr;

	bool want_continue = false;
	bool want_exit = false;
	bool already_played = false;

	SettingsMenu settings_menu;
	CreditsMenu credits_menu;
	HighscoreMenu highscore_menu;

	p2SString			click_Fx1;	
	p2SString			click_Fx2;
	p2SString			music;
	p2SString			background_tex;
	p2SString			title_tex;
	p2SString			fire_tex;

	Animation			fire;

	char				timerText[100];
	char				scoreText[100];

	float				final_time;
	int					final_score;
};

#endif // __j1INTROSCENE_H__
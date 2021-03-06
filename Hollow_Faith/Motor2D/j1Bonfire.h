#ifndef __j1BONFIRE_H__
#define __j1BONFIRE_H__

#define JUMP_INIT_VY 11.4166666666 //initial velocity on the Y coord. //16.2
#define JUMP_INIT_AY 0.47568444444 //initial acceleration on the Y coord. //0.867

#define JUMP_TIME 3000

#include "j1Module.h"
#include "p2Animation.h"
#include "j1Entity.h"

struct SDL_Texture;


class j1Bonfire : public j1Entity
{

public:

	// - - - - ANIMATIONS  - - - -

	Animation		light_off;
	Animation		light_on;
	

	// - - - - TRIGGERS - - - -

	bool			alreadyCollided;
	bool			active = false;	

public:

	j1Bonfire(fPoint pos, int count, bool actv=false);

	// Destructor
	~j1Bonfire();

	bool Awake(pugi::xml_node&);
	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool Load(pugi::xml_node& file);
	bool Save(pugi::xml_node& file) const;

	void OnCollision(Collider* c1, Collider* c2);
};

#endif //  __j1BONFIRE_H__

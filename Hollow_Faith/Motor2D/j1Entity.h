#ifndef __j1ENTITY_H__
#define __j1ENTITY_H__

#include "p2Point.h"
#include "p2Animation.h"
#include "p2Log.h"
#include "SDL/include/SDL_render.h"

#define MAXNUMOFCOLLIDERS 1

enum collDirCheck
{
	DIR_UNKNOWN = -1,

	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_MAX
};


class j1Entity
{
public:
	enum entityType
	{
		NO_TYPE,
		PLAYER,		
		ENEMY_FLY,
		ENEMY_LAND,
		STONE,
		BONFIRE,
		COINS,
	};

public:
	
	j1Entity(entityType type);
	~j1Entity();
	
	virtual bool Awake(pugi::xml_node& config) { return true; };
	virtual bool Start() { return true; };
	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt) { return true; };
	virtual bool PostUpdate() { return true; };	

	virtual bool CleanUp() { return true; };
	virtual bool Save(pugi::xml_node& file) const { return true; };
	virtual bool Load(pugi::xml_node& file) { return true;  };
	
	void PositionUpdate(float dt);						//Update entity's position
	void Draw(float dt);	

	virtual void OnCollision(Collider* c1, Collider* c2) {};
	void CollisionPosUpdate();

public:
	
	// - - - - ENTITY BASICS - - - -

	entityType			type;

	Collider*			collider=nullptr;
	SDL_Rect			entity_collider;

	p2SString			texture_path;
	SDL_Texture*		texture=nullptr;
	
	SDL_RendererFlip	flip = SDL_RendererFlip::SDL_FLIP_NONE;
	

	bool				ignoreColl = false;
	bool				godMode = false;

	bool				elim = false;
	

	// - - - - MOBILITY - - - -

	fPoint				speed = {0.0f,0.0f};
	fPoint				position = {0.0f,0.0f};
	float				Acceleration = 0.0f;

	int					distance;


	// - - - - ANIMATIONS - - - -

	Animation*			current_animation = nullptr;
	
	
	// - - - - WORLD - - - -
	
	fPoint				savedPosition;
	int					num_bonfire;
	float				gravityForce;
	
};

#endif
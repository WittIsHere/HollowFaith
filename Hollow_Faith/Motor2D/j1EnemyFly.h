#ifndef __j1ENEMYFLY_H__
#define __j1ENEMYFLY_H__

#include "p2Point.h"
#include "p2Animation.h"
#include "j1Module.h"
#include "p2DynArray.h"
#include "j1Timer.h"
#include "p2Point.h"


struct SDL_Texture;
struct Collider;

class j1EnemyFly : public j1Enemy
{

public:

	// - - - - ANIMATIONS - - - -

	Animation			fly;

public:

	j1EnemyFly();
	j1EnemyFly(fPoint position);

	// Destructor
	~j1EnemyFly();

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

	void OnCollision(Collider* c1, Collider* c2);


	// - - - - PATHFINDING LAND ENEMY LOGIC - - - -

	bool GeneratingThePath(float timer, float dt, int auxAgroDistance);
	bool FollowingThePath(float speed, float dt);

};

#endif // __ENEMYFLY_H__
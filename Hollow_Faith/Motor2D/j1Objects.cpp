#include "j1Objects.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Scene.h"
#include "j1Player.h"
#include "j1Entity.h"
#include "j1Textures.h"
#include "j1Enemy.h"


j1Objects::j1Objects()
{
	name.create("objects");
}

j1Objects::~j1Objects()
{
}

bool j1Objects::Awake(pugi::xml_node& config)
{
	bool ret = true;
	texture_path = config.child("graphics").attribute("path").as_string();

	LOG("%s", texture_path.GetString());
	return ret;
}

bool j1Objects::Start()
{
	bool ret = true;
	texture = App->tex->Load(texture_path.GetString());

	return ret;
}

bool j1Objects::PreUpdate()
{

	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{

		if (tmp->data->type == j1Entity::entityType::PLAYER || tmp->data->type == j1Entity::entityType::ENEMY)
			ret = tmp->data->PreUpdate();
		tmp = tmp->next;
	}

	return ret;
}
bool j1Objects::Update(float dt)
{

	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{

		if (tmp->data->type == j1Entity::entityType::PLAYER || tmp->data->type == j1Entity::entityType::ENEMY)
			ret = tmp->data->Update(dt);
		tmp = tmp->next;
	}

	return ret;
}

bool j1Objects::PostUpdate()
{
	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{
		ret = tmp->data->PostUpdate();
		tmp = tmp->next;
	}
	return ret;
}

bool j1Objects::CleanUp()
{
	bool ret = true;
	App->tex->UnLoad(texture);
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{
		tmp->data->CleanUp();
		tmp = tmp->next;
	}

	return ret;
}

bool j1Objects::Save(pugi::xml_node& file) const
{
	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{
		tmp->data->Save(file);
		tmp = tmp->next;
	}
	return ret;
}

bool j1Objects::Load(pugi::xml_node& file)
{
	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;

	while (tmp != nullptr)
	{
		if (tmp->data->type == j1Entity::entityType::PLAYER || tmp->data->type == j1Entity::entityType::ENEMY)
		{
			tmp->data->Load(file);
		}
		tmp = tmp->next;
	}
	return ret;
}


bool j1Objects::Draw(float dt)
{

	bool ret = true;
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{
		tmp->data->Draw(dt);
		tmp = tmp->next;
	}
	return ret;
}

bool j1Objects::DebugDraw()
{
	/*p2List_item<j1Entity*>* tmp = Entities.start;
	SDL_Rect col;
	SDL_Rect col2;
	while (tmp != nullptr)
	{
		col.h = tmp->data->Collider.h, col.w = tmp->data->Collider.w, col.x = tmp->data->Collider.x, col.y = tmp->data->Collider.y;
		App->render->DrawQuad(col, 255, 0, 0, 50);

		tmp = tmp->next;
	}*/
	return true;
}


j1Entity* j1Objects::AddEntity(j1Entity::entityType type, iPoint position)
{
	j1Entity* tmp = nullptr;

	switch (type)
	{
	case j1Entity::entityType::PLAYER:
		tmp = new j1Player();
		break;

	case j1Entity::entityType::ENEMY:
		tmp = new j1Enemy();
		break;
	}

	if (tmp)
		Entities.add(tmp);

	return tmp;
}

void j1Objects::DeleteEntities()
{
	p2List_item<j1Entity*>* tmp = Entities.start;
	while (tmp != nullptr)
	{
		p2List_item<j1Entity*>* tmp2 = tmp;
		RELEASE(tmp->data);
		Entities.del(tmp2);
		tmp = tmp->prev;
	}
}
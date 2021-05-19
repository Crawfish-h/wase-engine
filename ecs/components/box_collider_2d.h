#pragma once

#include "collider.h"

#include "../../core/renderer.h"
#include "../../core/debug_draw.h"
#include "../../ecs/components/transform.h"

#include <SDL.h>

class BoxCollider2D : public Collider
{
public:
	int width, height;
	float offsetX = 0, offsetY = 0;
	bool showCollider = false;

private:
	float x, y;
	float mouseX, mouseY;

	SDL_Rect rectToDraw;

public:
	BoxCollider2D(const int width, const int height);

	void update(float dt);
	void render();

	bool onMouseEnter();
	bool onMouseExit();
};
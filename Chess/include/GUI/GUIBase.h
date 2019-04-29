#pragma once
#include "SFML/Graphics/Sprite.hpp"
class GUIBase : 
	public sf::Sprite
{
private:
	void (*OnClickCallback)(...);
public:
	GUIBase();
	virtual ~GUIBase();

	virtual void OnClick() = 0;
	void SetOnClickCallback(void* callback_fun);
};


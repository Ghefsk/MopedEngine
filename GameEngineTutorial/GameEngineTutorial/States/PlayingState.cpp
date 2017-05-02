#include "PlayingState.h"
#include <iostream>
#include "../Application.h"
#include "../Input.h"
#include "../Display.h"


namespace State
{
	State::Playing::Playing(Application &application) :
		Game_State(application)
	{
		shape.setSize(sf::Vector2f(50,50));
		shape.setOrigin(25, 25);
		shape.setPosition(500, 500); 
		shape.setFillColor(sf::Color::Green);

	}

	void State::Playing::input()
	{


		if (Input::Joystick::getAxisPosition(sf::Joystick::Axis::X) > 30)
		{
			xSpeed = 0.1; 
		}
		else if (Input::Joystick::getAxisPosition(sf::Joystick::Axis::X) < -30)
		{
			xSpeed = -0.1;
		}
		else
		{
			xSpeed = 0; 
		}
		if (Input::Joystick::getAxisPosition(sf::Joystick::Axis::Y) > 30)
		{
			ySpeed = 0.1;
		}
		else if (Input::Joystick::getAxisPosition(sf::Joystick::Axis::Y) < -30)
		{
			ySpeed = -0.1;
		}
		else
		{
			ySpeed = 0; 
		}

	}

	}

	void State::Playing::update(float dt)
	{
		shape.move(sf::Vector2f(xSpeed, ySpeed));

	}

	void State::Playing::draw()
	{
		Display::draw(shape);
	}



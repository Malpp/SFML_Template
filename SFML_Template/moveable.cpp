#include "stdafx.h"
#include "moveable.h"
#include "Game.h"

void Moveable::update( float delta_time_ )
{
	sf::Vector2f move_by_pos = getNextMove( delta_time_ ) * delta_time_;
	sprite_.move( move_by_pos );

	if(isAtEdge())
	{
		handleEdge();
	}
}

bool Moveable::isAtEdge()
{
	sf::Vector2f current_pos = sprite_.getPosition();
	if (current_pos.x > Game::GAME_WIDTH - half_texture_size_.x ||
		current_pos.x < half_texture_size_.x ||
		current_pos.y > Game::GAME_HEIGHT - half_texture_size_.y ||
		current_pos.y < half_texture_size_.y)
		return true;

	return false;
}

void Moveable::handleEdge()
{
	sf::Vector2f current_pos = sprite_.getPosition();
	sprite_.setPosition( sf::Vector2f(
		std::max( half_texture_size_.x,
			std::min( Game::GAME_WIDTH - half_texture_size_.x, current_pos.x ) ),

		std::max( half_texture_size_.y,
			std::min( Game::GAME_HEIGHT - half_texture_size_.y, current_pos.y ) )
	) );
}

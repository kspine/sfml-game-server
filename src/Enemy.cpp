#include "Enemy.h"

Enemy::Enemy(int width, int height, int x, int y)
{
	rect.setSize(sf::Vector2f(width, height));
	rect.setPosition(x, y);

	std::cout << "Enemy " << " has been successfully initialized." << std::endl;
}

void Enemy::initPointers(Player p)
{
	ptr_Player = &p;
}

void Enemy::enemyAI()
{
	
	x_dist = ptr_Player->rect.getPosition().x - rect.getPosition().x;
	y_dist = ptr_Player->rect.getPosition().y - rect.getPosition().y;
	//std::cout << std::sqrt(std::pow(x_dist,2) - std::pow(y_dist,2)) << std::endl;
	// if in attack radius
	if(std::sqrt(std::pow(x_dist,2) - std::pow(y_dist,2)) < atk_range.getRadius() &&
	std::sqrt(std::pow(x_dist,2) - std::pow(y_dist,2)) > 0)
	{
		
		//attack();
	}

		if (std::abs(x_dist) <= std::abs(y_dist) && 
			ptr_Player->rect.getPosition().y <= rect.getPosition().y && isAggro) 
		{
			if(ptr_Player->rect.getPosition().x >= rect.getPosition().x)
			{
				rect.move(spd, 0);
			}
			if(ptr_Player->rect.getPosition().x <= rect.getPosition().x)
			{
				rect.move(-spd, 0);
			}
			rect.move(0, -spd);
		}

		if (std::abs(y_dist) <= std::abs(x_dist) &&
			ptr_Player->rect.getPosition().x < rect.getPosition().x && isAggro) //LEFT
		{
			if(ptr_Player->rect.getPosition().y <= rect.getPosition().y)
			{
				rect.move(0, -spd);
			}
			if(ptr_Player->rect.getPosition().y >= rect.getPosition().y)
			{
				rect.move(0, spd);
			}

			rect.move(-spd, 0);
		}

		if (std::abs(y_dist) >= std::abs(x_dist) && 
			ptr_Player->rect.getPosition().y > rect.getPosition().y && isAggro) // DOWN
		{
			if(ptr_Player->rect.getPosition().x < rect.getPosition().x)
			{
				rect.move(-spd, 0);
			}
			if(ptr_Player->rect.getPosition().x > rect.getPosition().x)
			{
				rect.move(spd, 0);
			}

			rect.move(0, spd);
		}

		if (std::abs(x_dist) >= std::abs(y_dist) && 
			ptr_Player->rect.getPosition().x > rect.getPosition().x && isAggro) // RIGHT
		{
			if(ptr_Player->rect.getPosition().y <= rect.getPosition().y)
			{
				rect.move(0, -spd);
			}
			if(ptr_Player->rect.getPosition().y >= rect.getPosition().y)
			{
				rect.move(0, spd);
			}

			rect.move(spd, 0);
		}
		WalkCount++;
		
		if (WalkCount == 9)
		{
			WalkCount = 0;
		}
}


void Enemy::isInAggroRadius()
{
	//std::cout << ptr_Player->rect.getPosition().x << std::endl;
	int dist = std::sqrt(std::pow(ptr_Player->rect.getPosition().x - rect.getPosition().x,2)
		+ std::pow(ptr_Player->rect.getPosition().y - rect.getPosition().y,2));

	if ( dist < Aggro_Radius.getRadius() )
	{
		isAggro = true;
	}
	else
	{
		isAggro = false;
	}
	//std::cout << "The player is " << dist << " away from the enemy" << std::endl;
}

void Enemy::update()
{
	Aggro_Radius.setPosition(
	rect.getPosition().x - Aggro_Radius.getRadius(),
	rect.getPosition().y - Aggro_Radius.getRadius()
	);

	atk_range.setPosition(
	rect.getPosition().x - atk_range.getRadius(),
	rect.getPosition().y - atk_range.getRadius()
	);
}

void Enemy::attack()
{
}

Enemy::~Enemy()
{
	// ptr_Player = NULL;
	// delete ptr_Player;
}

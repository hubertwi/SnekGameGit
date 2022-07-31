#pragma once
#include "Snake.h"
#include "Obstacle.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake snake);
	void Spawn(std::mt19937& rng, const Board& brd, const Snake snake);
	void Respawn( std::mt19937& rng, const Board& brd, const Snake snake, const Obstacle* obstacles, const int& nObstacles);
	void Draw(Board& brd) const; 
	const Location& GetLocation() const;

private:
	bool notInObstacle = false;
	static constexpr Color c = Colors::Red;
	Location loc;
};
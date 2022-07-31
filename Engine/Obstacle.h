#pragma once
#include "Board.h"
#include <random>

class Obstacle
{
public:
	Obstacle();
	Obstacle(std::mt19937& rng, const Board& brd, const class Snake& snake, const class Goal& goal);
	void SpawnObstacle(std::mt19937& rng, const Board& brd, const class Snake& snake, const class Goal& goal);
	void Draw(Board& brd) const;
	bool IsInTile(const Location& target, Obstacle* obstacles, int& nObstacles) const;
	const Location& GetLocation() const;

private:
	static constexpr Color c = Colors::Gray;
	Location loc;
	static constexpr int nMaxObstacles = 25;

};

#include "Obstacle.h"
#include "Goal.h"
#include "Snake.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(std::mt19937& rng, const Board& brd, const Snake& snake, const class Goal& goal)
{
	SpawnObstacle(rng, brd,snake, goal);
}

void Obstacle::SpawnObstacle(std::mt19937& rng, const Board& brd, const Snake& snake, const class Goal& goal)
{

	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);
	do
	{
		loc.x = xDist(rng);
		loc.y = yDist(rng);
	} while (snake.IsInTile(loc) || (loc == goal.GetLocation()));

}

void Obstacle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

bool Obstacle::IsInTile(const Location& target, Obstacle* obstacles, int& nObstacles) const
{
	for (int i = 0; i < nObstacles; i++)
	{
		if (obstacles[i].GetLocation() == target)
		{
			return true;
		}

	}
	return false;
}

const Location& Obstacle::GetLocation() const
{
	return loc;
}



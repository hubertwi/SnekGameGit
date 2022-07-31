#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake snake)
{

	Spawn(rng, brd, snake);

}

void Goal::Spawn(std::mt19937& rng, const Board& brd, const Snake snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snake.IsInTile(newLoc));


	loc = newLoc;
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake snake, const Obstacle* obstacles, const int& nObstacles)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);

	Location newLoc;
	do
	{
		while (!notInObstacle)
		{
			notInObstacle = true;
			newLoc.x = xDist(rng);
			newLoc.y = yDist(rng);
			for (int i = 0; i < nObstacles; i++)
			{
				if (obstacles[i].GetLocation() == newLoc)
				{
					notInObstacle = false;
				}
			}
		}
		notInObstacle = false;

	} while (snake.IsInTile(newLoc));


	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}

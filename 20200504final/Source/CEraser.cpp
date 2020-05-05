#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
namespace game_framework {

	int CEraser::GetX1()
	{
		return x;
	}

	int CEraser::GetY1()
	{
		return y;
	}

	int CEraser::GetX2()
	{
		return x + animation.Width();
	}

	int CEraser::GetY2()
	{
		return y + animation.Height();
	}

	void CEraser::Initialize(map* m)
	{
		int X_POS[4] = { 0,100,618,618 };
		int Y_POS[4] = { 210 - animation.Height(),0,160,160 };
		world_1 = m;
		timer_bullet = 0;
		jumpCounter = 1;

		for (int i = 0; i < sizeof(X_POS); i++)
		{
			if (world_1->Getcurrentmap() == i)
			{
				x = X_POS[i];
				y = Y_POS[i];
			}
		}
		velocity = 15;
		isdoublejump = isMovingLeft = isMovingRight = isMovingUp = isMovingDown = attack = isjumping = mapmovingleft = false;
		isOnFloor = true;
		direction = 0;
	}

	void CEraser::LoadBitmap()
	{
		animation.AddBitmap(IDB_CHAC, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_chac2, RGB(255, 255, 255));
	}

	void CEraser::OnMove()
	{
		TRACE("%d...!", y);
		int x_POS[4] = { 0,100,618,618 };
		int y_POS[4] = { 210 - animation.Height(),0,160,140 };

		if (world_1->isMapEnd(x, y))
		{
			for (int z = 1; z < sizeof(x_POS); z++)
			{
				if (z == world_1->Getcurrentmap())
				{
					x = x_POS[z];
					y = y_POS[z];
				}
			}
		}

		if (attack)
		{
			if (clock() - timer_bullet >= 400)
			{
				timer_bullet = clock();
				if (direction == 0)
					bullet.push_back(new Bullet(x + animation.Width(), y + (animation.Height() / 2), direction));
				else
					bullet.push_back(new Bullet(x, y + (animation.Height() / 2), direction));
			}
		}

		if (!world_1->judgearea(x, &y, animation.Height(), &isOnFloor) && !isMovingUp && !isjumping)
		{
			isMovingDown = true;
			isMovingUp = false;
		}
		else {
			isMovingDown = false;
		}

		if (isOnFloor) SetOnFloor();



		const int STEP_SIZE = 7;
		int i = 0;

		if (isMovingLeft) {
			if (world_1->Getcurrentmap() == 0)
			{
				if ((x - world_1->GetX() <= 7) || world_1->judgewall(x, y, 0))
				{
					SetMovingLeft(false);
					mapmovingleft = false;
				}
				else if (x < 200)
				{
					mapmovingleft = true;
				}
				else
				{
					x -= STEP_SIZE;
					mapmovingleft = false;
				}
			}
			else if (!world_1->Getcurrentmap() == 0)
			{
				if (world_1->judgewall(x, y, 0))
					SetMovingLeft(false);
				else x -= STEP_SIZE;
			}
		}


		if (isMovingRight && world_1->Getcurrentmap() == 0)
		{
			if (world_1->judgewall(x, y, 1))
			{
				mapmoving = false;
				SetMovingRight(false);
			}
			else if (x >= 240 && 680 - world_1->GetX() < 2105) { mapmoving = true; }
			else if (x < 660) { x += STEP_SIZE; }
		}
		else if (isMovingRight && !world_1->Getcurrentmap() == 0)
		{
			if (world_1->judgewall(x, y, 1))
				SetMovingRight(false);
			else x += STEP_SIZE;
		}
		else  mapmoving = false;


		if (isMovingUp)
		{
			jump("jump");
		}
		if (isMovingDown)
		{
			isMovingUp = false;
			jump("fall");
		}
	}

	void CEraser::jump(string state)
	{

		if (isMovingUp)
		{
			if (abs(velocity) > initial_velocity) velocity = initial_velocity;
			if (jumpCounter == 1) { velocity = initial_velocity; jumpCounter += 1; }

			if (velocity > 0)
			{
				y -= velocity;
				velocity--;
			}

			else
			{
				isMovingUp = false;
				isMovingDown = true;
				velocity = 1;
			}
		}
		else
		{
			isMovingUp = false;
			y += velocity;
			if (velocity < initial_velocity)
				velocity++;
		}
	}

	void CEraser::SetOnFloor()
	{
		jumpCounter = 0;
	}

	int CEraser::GetJumpCount()
	{
		return jumpCounter;
	}

	bool CEraser::GetOnFloor()
	{
		if (isOnFloor) return true;
		return false;
	}

	void CEraser::shooting(bool flag)
	{
		attack = flag;
	}
	void CEraser::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CEraser::SetMovingLeft(bool flag)
	{
		if (world_1->Getcurrentmap() == 0)
		{
			isMovingLeft = flag;
			mapmovingleft = flag;
		}
		else
		{
			isMovingLeft = flag;
		}
	}

	void CEraser::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CEraser::SetMovingUp(bool flag)
	{
		jumpCounter += 1;
		isMovingUp = flag;
	}

	void CEraser::Setdir(int n)
	{
		direction = n;
	}
	void CEraser::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	bool CEraser::GetMovingSituation()
	{
		return mapmoving;
	}

	bool CEraser::GetMovingLeft()
	{
		return mapmovingleft;
	}

	void CEraser::OnShow()
	{
		if (direction == 0)
		{
			animation.SetTopLeft(x, y);
			animation.OnShow();
		}
		else
		{
			animation2.SetTopLeft(x, y);
			animation2.OnShow();
		}
		for (int i = 0; i<int(bullet.size()); i++)
		{
			bullet[i]->OnShow();
			if (!bullet[i]->HitSituation())
			{
				bullet[i]->SetHit(world_1->hitmonster(bullet[i]->GetX(), bullet[i]->GetY()));
			}
		}
	}
}
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Goomba.h"

namespace game_framework {

	void Goomba::Initalize()
	{
		x = 500;
		y = 155;
		hp = 2;
		ishitting = false;
		LoadBitmap();
	}

	void Goomba::SetMapXY(int x, int y)
	{
		mx = x;
		my = y;
	}

	int Goomba::GetX()
	{
		return x;
	}

	int Goomba::GetY()
	{
		return y;
	}

	void Goomba::LoadBitmap()
	{
		goomba_move.AddBitmap(IDB_goomba_1, RGB(0, 160, 0));
		goomba_move.AddBitmap(IDB_goomba_2, RGB(0, 160, 0));

	}

	bool Goomba::GetHit(int bx, int by)
	{
		if ((bx > x + mx && bx < x + mx + goomba_move.Width()) && (by > y&&by < y + goomba_move.Height()))
		{
			hp -= 1;
			return true;
		}
		return false;
	}

	void Goomba::OnMove()
	{
		goomba_move.SetDelayCount(8);
		goomba_move.OnMove();
	}

	void Goomba::OnShow()
	{
		x -= 1;
		if (hp > 0)
		{
			goomba_move.SetTopLeft(x + mx, y + my);
			goomba_move.OnShow();

		}
		else
		{
			x = 0;
			y = 0;
			SetMapXY(0, 0);
		}
	}
}
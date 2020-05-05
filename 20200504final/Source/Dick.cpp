#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Dick.h"
namespace game_framework {
	dick::dick(int x,int y,int dir)
	{
		dx = x;
		dy = y;
		direction = dir;
		LoadBitmap();
	}

	void dick::LoadBitmap()
	{
		if (direction == 0 )
		{
			Dick[direction].AddBitmap(IDB_dick_standard, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire1, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire2, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire3, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire4, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire5, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire6, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_dickfire7, RGB(255, 255, 255));
		}
		else
		{
			Dick[direction].AddBitmap(IDB_rdickfire7, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdick_standard, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire1, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire2, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire3, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire4, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire5, RGB(255, 255, 255));
			Dick[direction].AddBitmap(IDB_rdickfire6, RGB(255, 255, 255));
			
		}
		Dick[direction].SetDelayCount(5);
	}

	void dick::OnMove()
	{
		Dick[direction].OnMove();
	}

	void dick::OnShow()
	{
		if (direction == 0)
		{
			if (Dick[0].GetCurrentBitmapNumber() == 0)
				Dick[0].SetTopLeft(dx, dy);
			if (Dick[0].GetCurrentBitmapNumber() == 1)
				Dick[0].SetTopLeft(dx, dy - 6);
			if (Dick[0].GetCurrentBitmapNumber() == 2)
				Dick[0].SetTopLeft(dx, dy - 7);
			if (Dick[0].GetCurrentBitmapNumber() == 3)
				Dick[0].SetTopLeft(dx, dy - 1);
			if (Dick[0].GetCurrentBitmapNumber() == 4)
				Dick[0].SetTopLeft(dx, dy + 3);
			if (Dick[0].GetCurrentBitmapNumber() == 5)
				Dick[0].SetTopLeft(dx, dy - 7);
			if (Dick[0].GetCurrentBitmapNumber() == 6)
				Dick[0].SetTopLeft(dx, dy - 8);
			if (Dick[0].GetCurrentBitmapNumber() == 7)
				Dick[0].SetTopLeft(dx, dy - 9);
		}
		else
		{
			if (Dick[1].GetCurrentBitmapNumber() == 0)
				Dick[1].SetTopLeft(dx -41, dy);
			if (Dick[1].GetCurrentBitmapNumber() == 1)
				Dick[1].SetTopLeft(dx -33 ,dy-6 );
			if (Dick[1].GetCurrentBitmapNumber() == 2)
				Dick[1].SetTopLeft(dx -29, dy -7);
			if (Dick[1].GetCurrentBitmapNumber() == 3)
				Dick[1].SetTopLeft(dx -38, dy -1);
			if (Dick[1].GetCurrentBitmapNumber() == 4)
				Dick[1].SetTopLeft(dx- 70 ,dy +3);
			if (Dick[1].GetCurrentBitmapNumber() == 5)
				Dick[1].SetTopLeft(dx -69, dy -7);
			if (Dick[1].GetCurrentBitmapNumber() == 6)
				Dick[1].SetTopLeft(dx -64, dy -8);
			if (Dick[1].GetCurrentBitmapNumber() == 7)
				Dick[1].SetTopLeft(dx -60, dy -9);
		}
		Dick[direction].OnShow();
	}
	
	
	
}
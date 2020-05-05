#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "map.h"
namespace game_framework {
	map::map()
	{
		Inital();
	}

	map::~map()
	{
		for (int i = 0; i < (int)dic.size(); i++)
		{
			delete dic[i];
		}
		for (int i = 0; i < (int)el.size(); i++)
		{
			delete el[i];
		}
	}

	void map::MonsterInitial()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.Initalize();
	}

	bool map::judgearea(int x, int *y, int height, bool *onFloor)
	{
		if (Getcurrentmap() == 2)
		{
			for (int i = 0; i<int(el.size()); i++)
			{
				if (x + 12 >= el[i]->GetX() && x <= el[i]->GetX2() && abs(*y + height - el[i]->GetY()) <= 15)
				{
					*y = el[i]->GetY() - 25;
					*onFloor = true;
					return true;
				}
			}
		}
		for (int i = 0; i < int(area.size()); i++)
		{
			if (x + 25 - sx >= area[i][0] && x - sx <= area[i][2] && abs(*y + height - area[i][1]) <= 10)
			{
				*y = area[i][1] - 35;
				*onFloor = true;
				return true;
			}
		}

		*onFloor = false;
		return false;
	}

	bool map::judgewall(int x, int y, int id)
	{
		for (int i = 0; i < int(wall.size()); i++)
		{
			if (id == 0)
			{
				if (abs(x - sx - wall[i][0]) <= 5 && y - sy >= wall[i][1] && y - sy <= wall[i][3])
					return true;
			}
			else
			{
				if (abs(x + 30 - sx - wall[i][0]) <= 5 && y - sy >= wall[i][1] && y - sy <= wall[i][3])
					return true;
			}
		}
		return false;
	}

	void map::LoadBitmap()
	{
		if (mpanimation != NULL) {
			delete mpanimation;
		}
		mpanimation = new CAnimation;
		if (currentmap == 0)
			mpanimation->AddBitmap(IDB_world_new_2);
		if (currentmap == 1)
			mpanimation->AddBitmap(IDB_world2_1);
		if (currentmap == 2)
			mpanimation->AddBitmap(IDB_world2_2);
		if (currentmap == 3)
			mpanimation->AddBitmap(IDB_world2_3);
	}

	void map::MonsterLoadBitmap()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.Initalize();
	}
	void map::Inital()
	{
		int x[4] = { 0,0,0,0 };
		int y[4] = { 0,0,0,0};
		for (int i = 0; i < sizeof(x); i++)
		{
			if (Getcurrentmap() == i)
			{
				sx = x[i];
				sy = y[i];
			}
		}
		isMovingRight = isMovingLeft = false;
		vector<int> w;
		vector<int> ar;
		area.clear();
		wall.clear();
		if (currentmap == 0)
		{
			ar.push_back(0);
			ar.push_back(210);
			ar.push_back(892);
			ar.push_back(210);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1106);
			ar.push_back(181);
			ar.push_back(1322);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1346);
			ar.push_back(214);
			ar.push_back(1399);
			ar.push_back(214);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1400);
			ar.push_back(105);
			ar.push_back(1425);
			ar.push_back(105);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1425);
			ar.push_back(138);
			ar.push_back(1470);
			ar.push_back(138);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1470);
			ar.push_back(107);
			ar.push_back(1507);
			ar.push_back(107);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1650);
			ar.push_back(127);
			ar.push_back(1812);
			ar.push_back(127);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1939);
			ar.push_back(273);
			ar.push_back(1986);
			ar.push_back(273);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1980);
			ar.push_back(326);
			ar.push_back(2057);
			ar.push_back(326);
			area.push_back(ar);
			ar.clear();
			w.push_back(1985);
			w.push_back(277);
			w.push_back(1985);
			w.push_back(471);
			wall.push_back(w);
			w.clear();
			w.push_back(1323);
			w.push_back(183);
			w.push_back(1323);
			w.push_back(480);
			wall.push_back(w);
			w.clear();
			w.push_back(1293);
			w.push_back(224);
			w.push_back(1293);
			w.push_back(384);
			wall.push_back(w);
			w.clear();
			w.push_back(1941);
			w.push_back(287);
			w.push_back(1941);
			w.push_back(480);
			wall.push_back(w);
			w.clear();
			w.push_back(1268);
			w.push_back(196);
			w.push_back(1268);
			w.push_back(222);
			wall.push_back(w);
			w.clear();
			w.push_back(1400);
			w.push_back(123);
			w.push_back(1400);
			w.push_back(226);
			wall.push_back(w);
			w.clear();
		}
		else if (currentmap == 1)
		{
			ar.push_back(0);
			ar.push_back(79);
			ar.push_back(478);
			ar.push_back(79);
			area.push_back(ar);
			ar.clear();
			ar.push_back(558);
			ar.push_back(79);
			ar.push_back(610);
			ar.push_back(79);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(181);
			ar.push_back(56);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(135);
			ar.push_back(181);
			ar.push_back(610);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(282);
			ar.push_back(478);
			ar.push_back(282);
			area.push_back(ar);
			ar.clear();
			ar.push_back(558);
			ar.push_back(282);
			ar.push_back(610);
			ar.push_back(282);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(383);
			ar.push_back(56);
			ar.push_back(383);
			area.push_back(ar);
			ar.clear();
			ar.push_back(135);
			ar.push_back(383);
			ar.push_back(610);
			ar.push_back(383);
			area.push_back(ar);
			ar.clear();
		}
		else if (Getcurrentmap() == 2)
		{
			for (int i = 0; i < (int)el.size(); i++)
			{
				delete el[i];
			}
			el.clear();
			el.push_back(new elevator(458, 435, 458, 31));
			el.push_back(new elevator(280, 435, 280, 240));
			el.push_back(new elevator(280, 229, 280, 31));
			el.push_back(new elevator(103, 435, 103, 301));
			el.push_back(new elevator(103, 301, 103, 165));
			el.push_back(new elevator(103, 165, 103, 31));
			ar.push_back(583);
			ar.push_back(181);
			ar.push_back(640);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(181);
			ar.push_back(55);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
		}
		else if (currentmap == 3)
		{
			for (int i = 0; i < (int)dic.size(); i++)
			{
				delete dic[i];
			}
			dic.clear();
			dic.push_back(new dick(18,352,0));
			dic.push_back(new dick(18, 251, 0));
			dic.push_back(new dick(625, 352, 1));
			dic.push_back(new dick(625, 251, 1));
			ar.push_back(572);
			ar.push_back(185);
			ar.push_back(640);
			ar.push_back(185);
			area.push_back(ar);
			ar.clear();
			ar.push_back(519);
			ar.push_back(286);
			ar.push_back(625);
			ar.push_back(286);
			area.push_back(ar);
			ar.clear();
			ar.push_back(440);
			ar.push_back(386);
			ar.push_back(625);
			ar.push_back(386);
			area.push_back(ar);
			ar.clear();
			ar.push_back(249);
			ar.push_back(297);
			ar.push_back(381);
			ar.push_back(297);
			area.push_back(ar);
			ar.clear();
			ar.clear();
			ar.push_back(0);
			ar.push_back(185);
			ar.push_back(71);
			ar.push_back(185);
			area.push_back(ar);
			ar.clear();
			ar.push_back(18);
			ar.push_back(286);
			ar.push_back(123);
			ar.push_back(286);
			area.push_back(ar);
			ar.clear();
			ar.push_back(18);
			ar.push_back(386);
			ar.push_back(202);
			ar.push_back(386);
			area.push_back(ar);
			ar.clear();
			
		}
	}

	int map::Getcurrentmap()
	{
		return currentmap;
	}

	int map::GetX()
	{
		return sx;
	}

	int map::GetY()
	{
		return sy;
	}

	void map::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void map::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	bool map::hitmonster(int bx, int by)
	{
		return enemy_goomba.GetHit(bx, by);
	}

	void map::MonsterOnMove()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.OnMove();
	}

	bool map::OnMove()
	{
		const int STEP_SIZE = 7;
		if (isMovingRight)
		{
			if (640 - sx <= mpanimation->Width()) {
				sx -= STEP_SIZE;
				return true;
			}
			return false;
		}
		if (isMovingLeft)
		{

			sx += STEP_SIZE;
			return true;
		}
		return false;
	}
	void map::OnShow()
	{
		mpanimation->SetTopLeft(sx, sy);
		mpanimation->OnShow();
		if (Getcurrentmap() == 0)
		{
			enemy_goomba.SetMapXY(sx, sy);
			enemy_goomba.OnShow();
		}
		else if (Getcurrentmap() == 2)
		{
			for (int i = 0; i < (int)el.size(); i++)
				el[i]->On_ShowandMove();
		}
		else if (Getcurrentmap() == 3)
		{
			for (int i = 0; i < (int)dic.size(); i++)
			{
				dic[i]->OnShow();
				dic[i]->OnMove();
			}

		}
	}

	bool map::isMapEnd(int ex, int ey)
	{
		if (currentmap == 0 && ex - sx >= 1987 && ex - sx <= 2104 && ey >= 480)
		{
			currentmap += 1;
			LoadBitmap();
			sx = 1934;
			sy = 1;
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 1 && ex < 1 && ey <= 181 && ey >= 80)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 2 && ex < 1 && ey <= 181)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		return false;
	}
	void map::Demo()
	{
		currentmap = 3;
	}
}
#include "Goomba.h"
#include "elevator.h"
#include "Dick.h"
#ifndef _MAP_H_
#define _MAP_H_
namespace game_framework {
	class map
	{
	public:
		map();
		~map();
		void Inital();
		int  GetX();
		int  GetY();
		void LoadBitmap();
		bool OnMove();
		void OnShow();
		void SetMovingRight(bool flag);
		void SetMovingLeft(bool flag);
		bool judgearea(int x, int* y, int height, bool*);
		bool judgewall(int x, int y, int id);
		bool hitmonster(int bx, int by);
		void MonsterOnMove();
		void MonsterLoadBitmap();
		void MonsterInitial();
		bool isMapEnd(int ex, int ey);
		void Demo();
		int	Getcurrentmap();
	protected:
		vector<elevator*> el;
		vector<dick*> dic;
		CAnimation* mpanimation = NULL;
		bool isMovingRight;
		bool isMovingLeft;
		char world[40][12] = { 0 };
		int currentmap = 0;
		int sx, sy;
		Goomba enemy_goomba;
		vector <vector<int>> area;
		vector<vector<int>> wall;
	};
}
#endif
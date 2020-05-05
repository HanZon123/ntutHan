#ifndef _DICK_H_
#define _DICK_H_
//#include "dick_bullet.h"
namespace game_framework {
	class dick
	{
	public:
		dick(int,int,int);
		void LoadBitmap();
		void OnMove();
		void OnShow();
	protected:
		int dx, dy;
		int direction;
		CAnimation Dick[2];
	};

}

#endif

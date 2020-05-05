#include "map.h"
#include "Bullet.h"
#ifndef _CERASER_H_
#define _CERASER_H_
namespace game_framework {
	class CEraser
	{
	public:
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize(map* m);				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		bool GetMovingSituation();
		bool GetMovingLeft();
		void shooting(bool flag);
		void jump(string state);
		void SetOnFloor();
		int GetJumpCount();
		bool GetOnFloor();
		void  Setdir(int n);
		
	protected:
		map *world_1;
		CAnimation animation;		// ���l���ʵe
		CAnimation animation2;
		vector<Bullet*> bullet;
		int x, y, flag = 1;					// ���l���W���y��
		int world[40][12] = { 0 };
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool mapmoving;
		bool mapmovingleft;
		bool attack;
		bool isOnFloor;
		bool isjumping;
		int jumpCounter;
		bool isdoublejump;
		int velocity;
		double timer_bullet;
		int initial_velocity = 15;
		int direction;
	};
}
#endif
/**
多态成立的三个条件
1. 要有继承
2. 要有函数重写(虚)
3. 父类指针(父类引用)指向子类对象
*/
#include <iostream>
#include <stdio.h>
using namespace std;

class HeroFighter
{
public:
	virtual int AttackPower()
	//int AttackPower()
	{
		return 10;
	}
};

class EnemyFighter
{
public:
	int DestoryPower()
	{
		return 15;
	}
};

class HeroAdv2Fighter : public HeroFighter
{
public:
	int AttackPower()
	{
		//HeroFighter::AttackPower()*2;
		return 20;
	}
protected:
private:
};

//一个模型 如果你把这个函数做成框架那。。。。。。。
void ObjFighter(HeroFighter *pBase, EnemyFighter *pEnemy)
{
	if (pBase->AttackPower() > pEnemy->DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}
}


int main()
{
	HeroFighter h1;
	EnemyFighter e1;
	HeroAdv2Fighter hAdvF;

	if (h1.AttackPower() > e1.DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}

	if (hAdvF.AttackPower() > e1.DestoryPower())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}

	printf("---------------------------\n");
	HeroFighter h2;
	EnemyFighter e2;
	HeroAdv2Fighter hAdvF2;

	ObjFighter(&h2, &e2);

	ObjFighter(&hAdvF2,  &e2);

	return 0;
}

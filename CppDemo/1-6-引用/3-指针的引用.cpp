#include "iostream"
using namespace std;


struct AdvTeacher
{
	char name[32];
	int age ;
};

/** getTeacher01和getTeacher02的作用是一样的*/

//给指针分配内存空间
void getTeacher01(AdvTeacher **p)
{
	AdvTeacher *tmp = (AdvTeacher *)malloc(sizeof(AdvTeacher));
	tmp->age = 30;
	*p = tmp;
}

//这个是 结构体变量指针的引用 指针的引用
//p2是 t2 的别名
void getTeacher02(AdvTeacher * &p2)
{
	p2 = (AdvTeacher *)malloc(sizeof(AdvTeacher));
	p2->age = 30;
}

//如果不加引用 那么 myT3会copy给t3，这样达不到修改age的目的
void getTeacher03(AdvTeacher &t3)
{
	t3.age = 11;
}

void main()
{
	AdvTeacher *t1 = NULL;
	AdvTeacher *t2 = NULL;
	getTeacher01(&t1);//二级指针传递进入，没毛病
	getTeacher02(t2);

	{
		AdvTeacher  myT3;
		myT3.age = 10;
		getTeacher03(myT3);

	}

	system("pause");
}
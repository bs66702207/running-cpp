#include "iostream"
using namespace std;

//下面可以这么成对使用吗
//new + free
//malloc + delete
//基础类型没有bug
//类不可以这么用

//new/delete int 基础类型
void main171()
{

	//int *p = (int *)malloc(sizeof(int));
	// 	int *p1 = new int;
	// 	*p1 = 1;
	// 	printf("%d\n", *p1);
	// 	delete p1;

	int *p2 = new int(10);
	printf("%d\n", *p2);
	//delete p2;
	free(p2);
	system("pause");
}

//分配数组
void main173()
{

	//int *p1 = (int *)malloc(10*sizeof(int));
	int *p1 = new int[10];

	for (int i=0; i<10; i++)
	{
		p1[i] = i+1;
		printf("%d\n", p1[i]);
	}

	delete[] (p1+1);
	//delete[] p1;
	//free(p1);

	// 	int *p2 = new int(10);
	// 	printf("%d\n", *p2);
	// 	delete p2;
	system("pause");
}


//指针做函数参数
class Test2
{
public:
	Test2(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"构造执行"<<endl;
	}
	~Test2()
	{
		cout<<"析构执行"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

void main174()
{
	Test2 *tmp = new Test2(5, 6);
	free(tmp);//内存空间是释放了，但是没有调用析构函数
	system("pause");
}

void main176()
{
	Test2 *tmp = (Test2 *)malloc(sizeof(Test2));//分配了内存空间，但是没有调用构造函数
	//free(tmp);
	delete(tmp);
	system("pause");
}


void main4444()
{

	//int *p1 = (int *)malloc(10*sizeof(int));
	int *p1 = new int[10];

	for (int i=0; i<10; i++)
	{
		p1[i] = i+1;
		printf("%d\n", p1[i]);
	}

	delete[] (p1+1);//内存首地址不能瞎改，这是不行的
	//delete[] p1;
	//free(p1);

	// 	int *p2 = new int(10);
	// 	printf("%d\n", *p2);
	// 	delete p2;
}


void main()
{
	main4444();
	system("pause");
}

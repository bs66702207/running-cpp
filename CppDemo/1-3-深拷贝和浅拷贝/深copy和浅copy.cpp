#include "iostream"
using namespace std;

class name
{ 
public :
	name(char *pn) ;  
	name( name &obj)
	{
		cout <<" copy Constructing " << endl ;
		char *pn = obj.getPn();
		pname = (char *)malloc(strlen(pn) +1);
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		size = strlen(pn) ;
	}
	~ name() ;
protected : 
	char *pname ;//这个指针要注意！       
	int size ;
public:
	char * getPn()
	{
		return pname;
	}	
	void operator=(name &obj1)
	{
		cout <<" 执行=操作" << endl ;
		char *pn = obj1.getPn();
		pname = (char *)malloc(strlen(pn) +1);//bug 内存泄漏，因为pname已经初始化过了
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		pname[0] = 'm';
		size = strlen(pn) ;
	}
} ;
name::name(char *pn)
{ 
	cout <<" Constructing " << pn << endl ;
	pname = (char *)malloc(strlen(pn) +1);
	if (pname!=0) strcpy(pname,pn) ;
	//pname = new char[strlen(pn)+1] ;
	//if (pname!=0) strcpy(pname,pn) ;
	size = strlen(pn) ;
} 
name :: ~ name()
{ 
	cout << " Destructing " << pname << endl ; 
	pname[0] = '\0' ;
	//delete  []pname ;
	free(pname);
	size = 0 ;
}


void playmain()
{
	name obj1("name1");
	//如果你不写copy构造函数，那么C++编译器会给我们提供一个默认的copy构造函数 （浅cpy）
	name obj2 = obj1;

	//如果你不写=操作，那么C++编译器会给我们提供一个=操作函数 （浅cpy）
	obj2 = obj1;
	cout<<obj2.getPn()<<endl;
}

void main()
{
	playmain();

	system("pause");
}
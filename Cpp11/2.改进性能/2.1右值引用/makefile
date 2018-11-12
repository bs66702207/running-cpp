GCC=g++ -std=c++11
FLAG=-fno-elide-constructors

all:
	$(GCC) 2-1-输出引用类型的示例.cpp -o 2-1.elf
	$(GCC) 2-2-MyString类的实现.cpp -o 2-2.elf
	$(GCC) 2-3-MyString的移动构造函数和移动赋值函数.cpp -o 2-3.elf
	$(GCC) 2-4-参数转发的实例.cpp -o 2-4.elf
	$(GCC) 2-5-emplace_back和push_back的比较.cpp -o 2-5.elf

clean:
	rm *.elf -f

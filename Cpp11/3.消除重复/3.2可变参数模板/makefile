GCC=g++ -std=c++11
FLAG=-fno-elide-constructors

all:
	$(GCC) 3-3-old实现的打印函数.cpp -o 3-3-old实现的打印函数.elf
	$(GCC) 3-3-new实现的打印函数.cpp -o 3-3-new实现的打印函数.elf
	$(GCC) 3-4-创建对象的工厂函数_1.cpp -o 3-4-创建对象的工厂函数_1.elf
	$(GCC) 3-4-创建对象的工厂函数_2.cpp -o 3-4-创建对象的工厂函数_2.elf

clean:
	rm *.elf -f

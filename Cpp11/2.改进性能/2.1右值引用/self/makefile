GCC=g++ -std=c++11
FLAG=-fno-elide-constructors

all:
	$(GCC) 1-右值demo.cpp -o 1-右值demo.elf
	$(GCC) 1-右值demo.cpp -o 1-右值demo_noelide.elf $(FLAG)
	$(GCC) 2-右值11demo.cpp -o 2-右值11demo.elf
	$(GCC) 2-右值11demo.cpp -o 2-右值11demo_noelide.elf $(FLAG)
	$(GCC) 4-说明2.cpp -o 4-说明2.elf
	$(GCC) 5-移动拷贝.cpp -o 5-移动拷贝.elf
	$(GCC) 6-万能包装器.cpp -o 6-万能包装器.elf
	$(GCC) 7-emplace_back的基本用法.cpp -o 7-emplace_back的基本用法.elf

clean:
	rm *.elf -f

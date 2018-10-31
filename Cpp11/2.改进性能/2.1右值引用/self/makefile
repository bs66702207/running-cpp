GCC=g++ -std=c++11
FLAG=-fno-elide-constructors

all:
	$(GCC) 1-右值demo.cpp -o 1-右值demo.elf
	$(GCC) 1-右值demo.cpp -o 1-右值demo_noelide.elf $(FLAG)
	$(GCC) 2-右值11demo.cpp -o 2-右值11demo.elf
	$(GCC) 2-右值11demo.cpp -o 2-右值11demo_noelide.elf $(FLAG)

clean:
	rm *.elf -f

#include <iostream>

#include <Looper.h>
#include <Exceptions.h>

using namespace std;

using namespace com::tsdl::util;
using namespace com::tsdl::err;

int main(int argc, char *argv[])
{
	struct itimerspec ts = { { 0, 0 }, { 10, 0 } };

	Looper looper(10);

	Timer timer(CLOCK_BOOTTIME, [&] () {
		looper.quit();
	});

	looper.prepare();

	looper.addEvent(1, [] () {
		cout << "Hello World!" << endl;
	});

	looper.removeTimer(timer);

	timer.setTime(0, &ts, NULL);

	looper.addTimer(timer);

	looper.loop();

	return 0;
}

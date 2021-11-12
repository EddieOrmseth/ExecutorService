#include <iostream>
#include <Windows.h>
#include "ExecutorService.hpp"

int testAddTask(int i, std::string str, double dub) {
    dub *= i * str.length();
    std::cout << dub;

    return i;
}

std::function<int(void*)> takePointer = [] (void* ptr) {
    std::cout << *((std::string*)ptr);

    return 0;
};

int main() {

//	ExecutorService* test = new ExecutorService(4, ExecutorService::SleepType::NOSLEEP);

//	std::queue<int>* inTest = new std::queue<int>();
//
//	std::function<int()> cat = [inTest] () {
//		std::cout << "Inside Task\n";
//		for (int i = 0; i < 100; i++) {
//			//inTest->push(i);
//		}
//		Sleep(100);
//		return 10;
//	};
//
//	std::cout << "Start Size: " << test->size() << "\n";
//	Sleep(100);
//
//
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//	int ID1 = test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//	test->addThread(false);
//	test->addThread(false);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//
//	std::cout << "Middle Size: " << test->size() << "\n";
//
//	test->destroyThread();
//	test->destroyThread();
//
//	Sleep(2000);
//
//	std::cout << "End Size: " << test->size() << "\n";
//
//	int ID2 = test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//	int ID3 = test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//    test->addLambdaTask(&cat);
//
//	test->addThread(false);

//    test->addTask(&testAddTask, 1, std::string("cat"), 45.6);

//	delete test;
//	delete inTest;

	//std::cout << "Main Thread Sleeping\n";
	////Sleep(5000);
	//std::cout << "Main Thread Waking Up\n";

	//std::cout << "Result: " << *test->waitForResult(ID1) << "\n";
	//test->waitForResult(ID2);
	//test->waitForResult(ID3);
	//test->waitForResult(ID1, 50);
	//test->waitForResult(ID2, 50);

	//delete inTest;
	//delete test;

	std::string* string = new std::string("cat");
	void* ptr = string;

    takePointer(ptr);

	return 0;
}

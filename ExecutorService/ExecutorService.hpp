#ifndef EXECUTORSERVICE
#define EXECUTORSERVICE

#include <queue>
#include <vector>
#include <thread>
#include <functional>
#include <iostream>
#include <mutex>
#include <chrono>
#include <condition_variable>

#ifdef __linux__
#include "arm-linux-gnueabihf\sys\unistd.h"
#endif

class ExecutorService {
public:

    enum class SleepType { // defines the behavior of the threads if there are no more available tasks

        NOSLEEP,
        HYBRIDSLEEP,
        ALLSLEEP

    };

    ExecutorService(); // uses hardware_concurrency() and SleepType::HYBRIDSLEEP
    ExecutorService(int thread_num); // uses SleepType::HYBRIDSLEEP
    ExecutorService(SleepType sleepType); // uses hardware_concurrency()
    ExecutorService(int thread_num, SleepType sleepType);
    ExecutorService(bool usingMain, SleepType sleepType); // uses hardware_concurrency() - 1

    ~ExecutorService(); // destructor, takes care of all variables and threads

    int addLambdaTask(std::function<int()>* function); // Lambda function must have no arguments and return an int

    template<typename F, typename... Args>
    int addTask(F function, Args... args) {

        //std::cout << "Adding Lambda Task\n";


        std::function<int(void)> newLambda = [function, args...]() {
            (*function)(args...);

            return 0;
        };

        return addLambdaTask(&newLambda);
    } // Pass in a function and it's arguments, the function must return an int

    void registerThisThread(bool wait); // Use the current thread in the thread pool. if wait then doesn't return until all tasks have completed, else it will return once the tasks queue is empty.

    // returns nullptr if result not found, each can only succeed once
    int* takeResult(int task_ID); // if the result is there, take it
    int* waitForResult(int task_ID); // waits for result using the default timeout
    int* waitForResult(int task_ID, uint64_t timeout); // wait for result using the given timeout, if no timeout pass a value <= 0

    void setWaitForTimeout(uint64_t timeout); // sets the default timeout for WaitForResult();
    uint64_t getWaitForTimeout(); // returns the default timeout for WaitForResult();
    bool checkFinished(int task_ID); // can be called multiple times, returns a bool of whether the Task has been completed
    int tasksLeft(); // returns the number of unclaimed tasks
    int getTasks_inProgress(); // returns the number of tasks started but unfinished

    int size(); // returns the number of threads
    void destroyThread(); // destroys / joins one thread
    void addThread(bool sleep); // Adds one thread to the pool

    bool allTasksComplete();
    void safePrint(std::string message);

private:

    void initialize(); // initializes the variables needed for the service to run

    int func_destroyThread(); // joins / destroys one thread
    int func_addThread(bool Sleep); // adds one thread

    std::function<int()> lam_destroyThread = [this]() { // lambda function passed into tasks list to destroy the thread that picks it up

        func_destroyThread();

        return 0;
    };

    std::function<int()> lam_addThread_WS = [this]() { // lambda function passed into tasks list to create a new thread that sleeps

        func_addThread(true);

        return 0;
    };

    std::function<int()> lam_addThread = [this]() { // lambda function passed into tasks list to create a new thread that does not sleep

        func_addThread(false);

        return 0;
    };

    struct Task { // struct used to creata a task

        std::function<int()>* function;
        int task_ID;
        int result = 0;

    };

    struct ThreadObj { // struct used to contain thread and related necessary variables

        std::thread* thread;
        bool* running;

    };

    int ID_counter = 0; // used to retrieve results
    int getID(); // used to retrieve results

    std::mutex* cv_mutex; // mutex for condition variable
    std::condition_variable* cond_var; // used to wake sleeping threads

    std::mutex* threads_mutex; // mutex used to access threads
    std::vector<ThreadObj*>* threads; // list of thread objects used

    int thread_num; // number of threads, defined at construction and during the addition and destruction of threads

    void runThread(std::thread* ID, bool* running); // waits for work to be available
    void runThread_WS(std::thread* ID, bool* running); // sleeps if there is no work to be done

    Task* takeTask(); // used by a thread to take the next available task
    std::mutex* tasks_mutex; // mutex used to access the tasks queue
    std::queue<Task*>* tasks; // queue used to hold / get tasks
    int tasks_inProgress = 0; // number of tasks that are currently running, updated in postResutls and takeTask

    void postResult(Task* result); // used to post the results of a task
    std::mutex* results_mutex; // mutex used to access results queue and associated variables
    std::vector<Task*>* results; // vector containning results of the tasks
    uint64_t waitFor_timeout = 1000; // 1 Seconds
    int unclaimedResults = 0; // number of resutls that haven't been taken by the user

    std::mutex* printingMutex;

};

#endif

/*
Improvements:
	Wrap return type in a class with pointer
*/
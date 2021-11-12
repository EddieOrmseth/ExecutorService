#include "ExecutorService.hpp"

ExecutorService::ExecutorService() {

    initialize();

    this->thread_num = std::thread::hardware_concurrency();

    std::cout << "Creating Threadpool with " << thread_num << " Threads\n";

    threads = new std::vector<ThreadObj*>(thread_num);

    // create threads
    std::cout << "Creating Threads\n";
    for (int i = 0; i < thread_num; i++) {

        if (i % 2 == 0) {
            std::cout << "Constructing Thread Without Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }
        else {
            std::cout << "Constructing Thread With Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }

    }

}

ExecutorService::ExecutorService(int thread_num, SleepType sleepType) {

    initialize();

    this->thread_num = thread_num;

    std::cout << "Creating Threadpool with " << thread_num << " Threads\n";

    threads = new std::vector<ThreadObj*>(thread_num);

    // create threads
    std::cout << "Creating Threads\n";
    for (int i = 0; i < thread_num; i++) {
        if (sleepType == SleepType::NOSLEEP) {
            std::cout << "Constructing Thread Without Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }
        else if (sleepType == SleepType::HYBRIDSLEEP) {

            if (i % 2 == 0) {
                std::cout << "Constructing Thread Without Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }
            else {
                std::cout << "Constructing Thread With Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }

        }
        else if (sleepType == SleepType::ALLSLEEP) {
            std::cout << "Constructing Thread With Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }

    }

}

ExecutorService::ExecutorService(int thread_num) {

    initialize();

    this->thread_num = thread_num;

    std::cout << "Creating Threadpool with " << thread_num << " Threads\n";

    threads = new std::vector<ThreadObj*>(thread_num);

    // create threads
    std::cout << "Creating Threads\n";
    for (int i = 0; i < thread_num; i++) {

        if (i % 2 == 0) {
            std::cout << "Constructing Thread Without Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }
        else {
            std::cout << "Constructing Thread With Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }

    }

}

ExecutorService::ExecutorService(ExecutorService::SleepType sleepType) {

    initialize();

    this->thread_num = std::thread::hardware_concurrency();

    std::cout << "Creating Threadpool with " << thread_num << " Threads\n";

    threads = new std::vector<ThreadObj*>(thread_num);

    // create threads
    std::cout << "Creating Threads\n";
    for (int i = 0; i < thread_num; i++) {
        if (sleepType == SleepType::NOSLEEP) {
            std::cout << "Constructing Thread Without Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }
        else if (sleepType == SleepType::HYBRIDSLEEP) {

            if (i % 2 == 0) {
                std::cout << "Constructing Thread Without Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }
            else {
                std::cout << "Constructing Thread With Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }

        }
        else if (sleepType == SleepType::ALLSLEEP) {
            std::cout << "Constructing Thread With Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }

    }

}

ExecutorService::ExecutorService(bool usingMain, SleepType sleepType) {

    initialize();

    if (true) {
        this->thread_num = std::thread::hardware_concurrency() - 1;
    }
    else {
        this->thread_num = std::thread::hardware_concurrency();
    }

    std::cout << "Creating Threadpool with " << thread_num << " Threads\n";

    threads = new std::vector<ThreadObj*>(thread_num);

    // create threads
    std::cout << "Creating Threads\n";
    for (int i = 0; i < thread_num; i++) {
        if (sleepType == SleepType::NOSLEEP) {
            std::cout << "Constructing Thread Without Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }
        else if (sleepType == SleepType::HYBRIDSLEEP) {

            if (i % 2 == 0) {
                std::cout << "Constructing Thread Without Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }
            else {
                std::cout << "Constructing Thread With Sleep\n";
                ThreadObj* threadobj = new ThreadObj;
                bool* running = new bool(true);
                threadobj->running = running;
                std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
                threadobj->thread = new_thread;

                threads->at(i) = threadobj;
            }

        }
        else if (sleepType == SleepType::ALLSLEEP) {
            std::cout << "Constructing Thread With Sleep\n";
            ThreadObj* threadobj = new ThreadObj;
            bool* running = new bool(true);
            threadobj->running = running;
            std::thread* new_thread = new std::thread([this, new_thread, running]() { runThread_WS(new_thread, running); });
            threadobj->thread = new_thread;

            threads->at(i) = threadobj;
        }

    }

}

void ExecutorService::initialize() {

    std::cout << "Initializing Variables\n";

    std::cout << "\tCreating Task Queue\n";
    tasks = new std::queue<Task*>;

    std::cout << "\tCreating Mutexes\n";
    cv_mutex = new std::mutex;
    threads_mutex = new std::mutex;
    tasks_mutex = new std::mutex;
    results_mutex = new std::mutex;
    printingMutex = new std::mutex();


    std::cout << "\tCreating Results Vector\n";
    results = new std::vector<Task*>;

    std::cout << "\tCreating Condition Variable\n";
    cond_var = new std::condition_variable;
}

ExecutorService::~ExecutorService() {

    volatile int stopper = 0;

    // Do not leave tasks unfinished
    while (getTasks_inProgress() != 0 || tasksLeft() != 0) { stopper++; }

    // delete threads
    std::cout << "Destroying / Joinning Threads\n";
    for (int i = 0; i < threads->size(); i++) {
        *threads->at(i)->running = false; // tells threads to stop running
    }

    // must give threads time to reach sleeping state
    std::cout << "Waiting for threads to finish for 1 second\n";

#ifdef __linux__
    usleep(1000000); // 1 second
#else

    stopper = 0;

    uint64_t start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    int timeout = 1000;

    while ((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start_time) < timeout) {

        stopper++;

    }

#endif

    std::cout << "Done waiting for threads to finish\n";

    cond_var->notify_all(); // tell sleeping threads to wake up

    for (int i = 0; i < thread_num; i++) {
        threads->at(i)->thread->join(); // correctly terminates threads
    }

    delete threads;

    // delete lambda functions
    while (!tasks->empty()) { delete tasks->front(); tasks->pop(); } // this shouldn't be necessary
    delete tasks;

    delete tasks_mutex;
    delete results_mutex;
    delete threads_mutex;
    delete printingMutex;

    while (results->size() > 0) { results->pop_back(); }
    delete results;

    delete cv_mutex;
    delete cond_var;
}

int ExecutorService::size() {
    return threads->size();
}

int ExecutorService::addLambdaTask(std::function<int()>* function) {

    //std::cout << "Adding Lambda Task\n";

    Task* task = new Task();

    task->function = function;
    task->task_ID = getID();
    task->result = 0;

    tasks_mutex->lock();

    tasks->push(task);


    tasks_mutex->unlock();

    cond_var->notify_all();

    return task->task_ID;
}

//template<typename F, typename... Args>
//int ExecutorService::addTask(F function, Args... args) {
//
//    //std::cout << "Adding Lambda Task\n";
//
//    Task* task = new Task();
//
//    auto newLambda = [function, args...] () {
//        f(args...);
//    };
//
//    task->function = newLambda;
//
//    task->task_ID = getID();
//    task->result = 0;
//
//    tasks_mutex->lock();
//
//    tasks->push(task);
//
//    tasks_mutex->unlock();
//
//    cond_var->notify_all();
//
//    return task->task_ID;
//}

void ExecutorService::registerThisThread(bool wait) {

    std::cout << "Main Thread Running (no sleep)\n";

    bool tasksCompleted = false;
    Task* task;

    bool running = true;

    while (running) {

        task = takeTask();

        if (task != nullptr) {
            //std::cout << "Thread " << ID << " Running Task\n";
            task->result = (*task->function)();

            postResult(task);
        }
        else {

        }

        if (tasksLeft() == 0) {
            if (wait) {
                if (allTasksComplete()) {
                    running = false;
                }
            }
            else {
                running = false;
            }
        }

    }

    std::cout << "Main Thread Exiting\n";

}


int ExecutorService::getID() {
    //std::cout << "ID: " << ID_counter + 1 << "\n";
    return ID_counter++;
}

ExecutorService::Task* ExecutorService::takeTask() {

    //std::cout << "";

    tasks_mutex->lock();

    if (tasks->size() > 0) {

        //std::cout << "Taking Task\n";

        Task* task = tasks->front();
        tasks->pop();
        tasks_inProgress++;

        tasks_mutex->unlock();

        return task;
    }
    else {

        tasks_mutex->unlock();

        return nullptr;
    }
}

void ExecutorService::runThread(std::thread* ID, bool* running) {

    std::cout << "Thread " << ID << "Running (no sleep)\n";

    Task* task;

    while (*running) {

        task = takeTask();

        if (task != nullptr) {
            //std::cout << "Thread " << ID << " Running Task\n";
            task->result = (*task->function)();

            postResult(task);
        }
        else {

        }

    }

    std::cout << "Thread " << ID << " Exiting\n";

}

void ExecutorService::runThread_WS(std::thread* ID, bool* running) {

    std::cout << "Thread " << ID << "Running (with sleep)\n";

    Task* task;

    while (*running) {

        task = takeTask();

        if (task != nullptr) {
            //std::cout << "Thread " << ID << " Running Task\n";
            task->result = (*task->function)();

            postResult(task);
        }
        else {

            std::cout << "Thread " << ID << " Sleeping\n";
            std::unique_lock<std::mutex>* lock = new std::unique_lock<std::mutex>(*cv_mutex);
            cond_var->wait(*lock);
            std::cout << "Thread " << ID << " Waking Up\n";
            lock->unlock();
            lock->release();

            delete lock;
        }

    }

    std::cout << "Thread " << ID << " Exiting\n";

}

int* ExecutorService::takeResult(int task_ID) {

    results_mutex->lock();

    int* result = new int;

    for (int i = 0; i < results->size(); i++) {

        if (results->at(i)->task_ID == task_ID) {

            std::cout << "Task Result Found\n";

            *result = results->at(i)->result;

            std::vector<Task*>::iterator position = results->begin();

            for (int g = 0; g < i; g++) {
                position++;
            }

            results->erase(position);

            unclaimedResults--;

            results_mutex->unlock();

            return result;
        }

    }

    std::cout << "Task Result Not Found\n";

    results_mutex->unlock();

    return nullptr;
}

bool ExecutorService::checkFinished(int task_ID) {

    results_mutex->lock();

    for (int i = 0; i < results->size(); i++) {

        if (results->at(i)->task_ID == task_ID) {

            results_mutex->unlock();

            return true;
        }

    }

    results_mutex->unlock();

    return false;
}

int* ExecutorService::waitForResult(int task_ID) {

    uint64_t start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    int* result{};
    bool found = false;

    while (!found && (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start_time) < waitFor_timeout) {

        result = takeResult(task_ID);

        if (result != nullptr) {
            found = true;
        }

    }

    return result;
}

int* ExecutorService::waitForResult(int task_ID, uint64_t timeout) {

    if (timeout > 0) {

        uint64_t start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        int* result{};
        bool found = false;

        while (!found && (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start_time) < timeout) {

            result = takeResult(task_ID);

            if (result != nullptr) {
                found = true;
            }

        }

        return result;

    }
    else {

        int* result{};
        bool found = false;

        while (!found) {

            result = takeResult(task_ID);

            if (result != nullptr) {
                found = true;
            }

        }

        return result;

    }

}

void ExecutorService::setWaitForTimeout(uint64_t timeout) {
    waitFor_timeout = timeout;
}

uint64_t ExecutorService::getWaitForTimeout() {
    return waitFor_timeout;
}

int ExecutorService::tasksLeft() {

    tasks_mutex->lock();

    int tasksLeft = tasks->size();

    tasks_mutex->unlock();

    return tasksLeft;
}

int ExecutorService::func_destroyThread() {

    std::thread::id this_ID = std::this_thread::get_id();
    int pos = -1;

    threads_mutex->lock();

    for (int i = 0; i < threads->size(); i++) {

        if (threads->at(i)->thread->get_id() == this_ID) {

            std::cout << "Destroying / Deteching Thread " << threads->at(i)->thread << "\n";

            if (i == -1) {
                std::cout << "Uh oh something bad happened\n";
                threads_mutex->unlock();
                return -1;
            }

            *threads->at(i)->running = false;
            threads->at(i)->thread->detach();
            pos = i;

            break;
        }

    }

    std::vector<ThreadObj*>::iterator position = threads->begin();

    for (int g = 0; g < pos; g++) {
        position++;
    }

    threads->erase(position);

    thread_num--;

    threads_mutex->unlock();

    if (pos == -1) {
        std::cout << "Uh oh something bad happened\n";
    }

    return 0;
}

int ExecutorService::func_addThread(bool sleep) {

    bool* status = new bool(true);
    std::thread* new_thread;

    if (sleep) {
        new_thread = new std::thread([this, new_thread, status]() { runThread_WS(new_thread, status); });
    }
    else {
        new_thread = new std::thread([this, new_thread, status]() { runThread(new_thread, status); });
    }

    std::cout << "Creating new Thread: " << new_thread << "\n";

    ThreadObj* threadobj = new ThreadObj;
    threadobj->running = status;
    threadobj->thread = new_thread;

    threads_mutex->lock();

    threads->push_back(threadobj);

    thread_num++;

    threads_mutex->unlock();

    return 0;
}

void ExecutorService::destroyThread() {

    addLambdaTask(&lam_destroyThread);

}

void ExecutorService::addThread(bool sleep) {

    if (threads->size() > 0) {
        if (sleep) {
            addLambdaTask(&lam_addThread_WS);
        }
        else {
            addLambdaTask(&lam_addThread);
        }
    }
    else {

        func_addThread(sleep);

    }

}

int ExecutorService::getTasks_inProgress() {

    tasks_mutex->lock();

    int left = tasks_inProgress;

    tasks_mutex->unlock();

    return left;
}

void ExecutorService::postResult(Task* result) {

    results_mutex->lock();
    tasks_mutex->lock();

    results->push_back(result);
    unclaimedResults++;
    tasks_inProgress--;

    results_mutex->unlock();
    tasks_mutex->unlock();
}

bool ExecutorService::allTasksComplete() {
    if (tasksLeft() == 0 && getTasks_inProgress() == 0) {
        return true;
    }
    else {
        return false;
    }
}

void ExecutorService::safePrint(std::string message) {
    printingMutex->lock();

    std::cout << message;

    printingMutex->unlock();
}
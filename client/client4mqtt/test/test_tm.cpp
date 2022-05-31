#include "ThreadModel.h"
#include <unistd.h>
#include <iostream>
#include <thread>
// 先定义事件回调
void cb_start(void *pData)
{
    printf("@cb_start call\n");
    std::cout << std::this_thread::get_id() << std::endl;
}
void cb_exit(void *pData)
{
    printf("@cb_exit call\n");
    std::cout << std::this_thread::get_id() << std::endl;
}
void cb_event1(void *pData)
{
    printf("@cb_event1 call\n");
    std::cout << std::this_thread::get_id() << std::endl;
}

int main(int argc, char *argv[])
{
    CThreadModel thread;
    thread.registerEventCB("start", cb_start);
    thread.registerEventCB("exit", cb_exit);
    thread.registerEventCB("event1", cb_event1);
    std::cout << std::this_thread::get_id() << std::endl;
    thread.start();
    thread.emitEvent("event1");
#ifdef __linux__
    sleep(2);
#else
    Sleep(60 * 1000);
#endif
    thread.quit();
    thread.wait();
    return 0;
}
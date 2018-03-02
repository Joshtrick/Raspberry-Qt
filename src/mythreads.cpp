#include "mythreads.hpp"

void *thread_1(void *ptr)
{
  ptr = (void*)(MainWindow*)malloc(sizeof(MainWindow));
  while(1)
  {
    ((MainWindow*)ptr)->mutex_dummy.lock();
    ((MainWindow*)ptr)->dummy_val = 'A';
    cout << "t1 -> The dummy value is: " << ((MainWindow*)ptr)->dummy_val << endl;
    ((MainWindow*)ptr)->mutex_dummy.unlock();
    hello_1();
  }
  free(ptr);
}

void *thread_2(void *ptr)
{
  ptr = (void*)(MainWindow*)malloc(sizeof(MainWindow));
  while(1)
  {
    ((MainWindow*)ptr)->mutex_dummy.lock();
    ((MainWindow*)ptr)->dummy_val = 'B';
    cout << "t2 -> The dummy value is: " << ((MainWindow*)ptr)->dummy_val << endl;
    ((MainWindow*)ptr)->mutex_dummy.unlock();
    hello_2();
  }
  free(ptr);
}

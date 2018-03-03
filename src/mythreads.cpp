#include "mythreads.hpp"

void *thread_1(void *ptr)
{
  MainWindow *window = (MainWindow*) ptr;
  while(1)
  {
    window->mutex_dummy.lock();
    window->dummy_val = 'A';
    cout << "t1 -> The dummy value is: " << window->dummy_val << endl;
    window->mutex_dummy.unlock();
    hello_1();
  }
}

void *thread_2(void *ptr)
{
  MainWindow *window = (MainWindow*) ptr;
  while(1)
  {
    window->mutex_dummy.lock();
    window->dummy_val = 'B';
    cout << "t2 -> The dummy value is: " << window->dummy_val << endl;
    window->mutex_dummy.unlock();
    hello_2();
  }
}

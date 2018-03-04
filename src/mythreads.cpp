#include "mythreads.hpp"
/*
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
*/
/*
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
*/

void *thread_1(void *ptr)
{
  MainWindow *window = (MainWindow*) ptr;
  window->server_tcp.socket_close(window->server_tcp.socket_fd);
  cout << "Socket closed" << endl;

}
void *thread_2(void *ptr)
{
  MainWindow *window = (MainWindow*) ptr;
  window->server_tcp.client_create(8000, "192.168.123.110");
  cout << "Server created" << endl;
  window->server_tcp.client_connect();
  /*
  window->server_tcp.server_listen();
  cout << "Server is listening" << endl;
  window->server_tcp.server_accept();
  cout << "Server accepts" << endl;
  */
}

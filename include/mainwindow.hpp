#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <pthread.h>
#include <string.h>

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMutex>

#include "mythreads.hpp"
#include "tcpip.hpp"

#define THREAD_NUM 2

using namespace std;

class MainWindow : public QWidget
{
  Q_OBJECT
public:
  MainWindow();
  ~MainWindow();

  QMutex mutex_dummy;

  pthread_t thread1;
  pthread_t thread2;

  TcpIp server_tcp;

  static char dummy_val;

public slots:
  void backend_run();
  void another_backend_run();

private:
  QPushButton *quit_button;
  QPushButton *start_button;
  QPushButton *another_start_button;
  QLabel *disp_label;
  QLabel *rst_label;
  QHBoxLayout *main_layout;
  QVBoxLayout *disp_layout;
  QHBoxLayout *button_layout;

};

#endif

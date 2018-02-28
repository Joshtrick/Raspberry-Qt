#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <thread>

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QThread>

#include "dummyworker.hpp"

class MainWindow : public QWidget
{
  Q_OBJECT
public:
  MainWindow();
  ~MainWindow();

  QThread *thread;
  DummyWorker *worker;

private:
  QPushButton *quit_button;
  QPushButton *start_button;
  QLabel *disp_label;
  QLabel *rst_label;
  QHBoxLayout *main_layout;
  QVBoxLayout *disp_layout;
  QHBoxLayout *button_layout;

};

#endif

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <thread>

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "hello.hpp"

class MainWindow : public QWidget
{
  Q_OBJECT
public:
  MainWindow();
  ~MainWindow();

  static void hello_loop_1();
  static void hello_loop_2();
private:
  QPushButton *quit_button;
  QPushButton *start_button;
  QLabel *disp_label;
  QLabel *rst_label;
  QHBoxLayout *main_layout;
  QVBoxLayout *disp_layout;
  QHBoxLayout *button_layout;

private slots:
  void backend_run();
};

#endif

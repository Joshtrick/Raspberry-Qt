#include "mainwindow.hpp"

MainWindow::MainWindow()
{
  //Start button
  start_button = new QPushButton("Start");
  QObject::connect(start_button, SIGNAL(clicked()), this, SLOT(backend_run()));
  start_button->setMinimumSize(1920*0.03,1080*0.02);
  start_button->setMaximumSize(1920*0.03,1080*0.02);

  //Quit button
  quit_button = new QPushButton("Quit");
  QObject::connect(quit_button, SIGNAL(clicked()), this, SLOT(close()));
  quit_button->setMinimumSize(1920*0.03,1080*0.02);
  quit_button->setMaximumSize(1920*0.03,1080*0.02);

  //Camera display
  disp_label = new QLabel("Display");
  disp_label->setMinimumSize(1920*0.45,1080*0.45);
  disp_label->setMaximumSize(1920*0.45,1080*0.45);

  //Result table
  rst_label = new QLabel("Result");

  //Main layout
  main_layout = new QHBoxLayout;
  //Layout on the left side for display and buttons
  disp_layout = new QVBoxLayout;
  //Layout for the buttons
  button_layout = new QHBoxLayout;
  //Configure layouts
  main_layout->addLayout(disp_layout);
  main_layout->addWidget(rst_label);
  main_layout->setStretchFactor(disp_layout, 3);
  main_layout->setStretchFactor(rst_label, 2);
  disp_layout->addWidget(disp_label);
  disp_layout->addLayout(button_layout);
  button_layout->addWidget(start_button);
  button_layout->addWidget(quit_button);

  setGeometry(0,0,1920*0.55,1080*0.55);
  setLayout(main_layout);
}

MainWindow::~MainWindow()
{
  delete start_button;
  delete quit_button;
  delete disp_label;
  delete rst_label;
  delete disp_layout;
  delete button_layout;
  delete main_layout;
}

void MainWindow::backend_run()
{
  std::thread thread_1(hello_loop_1);
  thread_1.detach();

  std::thread thread_2(hello_loop_2);
  thread_2.detach();
}

void MainWindow::hello_loop_1()
{
  while(1)
  {
    hello_1();
  }
}
void MainWindow::hello_loop_2()
{
  while(1)
  {
    hello_2();
  }
}

#ifndef DUMMYWORK_HPP
#define DUMMYWORK_HPP

#include <QObject>

#include "hello.hpp"

class DummyWorker : public QObject
{
  Q_OBJECT

public:
  DummyWorker();
  ~DummyWorker();

public slots:
  void process();

signals:
  void finished();
  void error(QString err);

private:
  // add your variables here
};

#endif

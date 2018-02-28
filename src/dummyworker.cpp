#include "dummyworker.hpp"

DummyWorker::DummyWorker()
{

}

// --- DECONSTRUCTOR ---
DummyWorker::~DummyWorker()
{
      // free resources
}

// --- PROCESS ---
// Start processing data.
void DummyWorker::process()
{

  while(1)
  {
    hello_1();
  }
  qDebug("Hello");
  emit finished();
}

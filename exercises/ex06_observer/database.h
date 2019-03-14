#ifndef DATABASE_H_
#define DATABASE_H_

#include "state.h"
#include "observer.h"
#include "subject.h"

class Database : public Observer {
public:
  Database(Subject * subject) : Observer(subject) {}
  void Update(const State& state);
  void Save();
private:
  State state_;
};

#endif

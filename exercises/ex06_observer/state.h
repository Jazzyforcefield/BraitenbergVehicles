#ifndef STATE_H_
#define STATE_H_

struct State {
public:
  double temperature;
  double humidity;
  double pressure;

  State() : temperature(0), humidity(0), pressure(0) {}
  State(double t, double h, double p) :
    temperature(t), humidity(h), pressure(p) {}
    
  State& operator=(const State& other) = default;
};

#endif

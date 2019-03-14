#include <iostream>

struct State {
  double temperature;
  double humidity;
  double pressure;
  State() : temperature(0), humidity(0), pressure(0) {}
  State(double t, double h, double p) : temperature(t), humidity(h), pressure(p) {}
};

class Weather {
public:
  Weather() {
    state_.temperature = 0;
    state_.humidity = 0;
    state_.pressure = 0;
  }

  State get_state() { return state_; }

  void Update(State s) {
    state_.temperature = s.temperature;
    state_.humidity = s.humidity;
    state_.pressure = s.pressure;
  }
private:
  State state_;
};

class WebDisplay {
public:
  WebDisplay(Weather * w) : weather_(w) {}
  void Display() {
    state_ = weather_->get_state();
    std::cout << state_.temperature << " " << state_.humidity << std::endl;
  }
private:
  Weather * weather_;
  State state_;
};

class Database {
public:
  Database(Weather * w) : weather_(w) {}
  void SaveData() {
    State state = weather_->get_state();
    std::cout << "Saving all the info: ";
    std::cout << state.temperature << " " << state.humidity << " " << state.pressure << std::endl;
    // Save this in a database: WriteDB(get_timestamp(), state);
  }
private:
  Weather * weather_;
};

int main() {
  Weather * weather = new Weather;
  WebDisplay * wb = new WebDisplay(weather);
  Database * db = new Database(weather);

  weather->Update(State(36,10,5.2));
  wb->Display();
  db->SaveData();
}

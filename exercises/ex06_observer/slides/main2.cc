#include <iostream>

class Weather {
public:
  Weather() : temperature_(0), humidity_(0), pressure_(0) {}

  double get_temperature() { return temperature_; }
  double get_humidity() { return humidity_; }
  double get_pressure() { return pressure_; }

  void Update(double temp, double hum, double press) {
    temperature_ = temp;
    humidity_ = hum;
    pressure_ = press;
  }

private:
  double temperature_;
  double humidity_;
  double pressure_;
};

class WebDisplay {
public:
  WebDisplay(Weather * w) : weather_(w) {}
  void Display() {
    temperature_ = weather_->get_temperature();
    humidity_ = weather_->get_humidity();
    std::cout << temperature_ << " " << humidity_ << std::endl;
  }
private:
  Weather * weather_;
  double temperature_;
  double humidity_;
};

class Database {
public:
  Database(Weather * w) : weather_(w) {}
  void SaveData() {
    double temperature = weather_->get_temperature();
    double humidity = weather_->get_humidity();
    double pressure = weather_->get_pressure();
    std::cout << "Saving all the info: ";
    std::cout << temperature << " " << humidity << " " << pressure << std::endl;
    // Save this in a database
    // WriteDB(get_timestamp(), temperature, humidity, pressure);
  }
private:
  Weather * weather_;
};

int main() {
  Weather * weather = new Weather;
  WebDisplay * wb = new WebDisplay(weather);
  Database * db = new Database(weather);

  weather->Update(36,10,5.2);
  wb->Display();
  db->SaveData();
}

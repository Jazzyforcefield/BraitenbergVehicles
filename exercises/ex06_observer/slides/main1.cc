#include <iostream>

class WebDisplay {
public:
  void Notify(double temp, double humidity) {
    temperature_ = temp;
    humidity_ = humidity;
    Display();
  }
  void Display() {
    std::cout << temperature_ << " " << humidity_ << std::endl;
  }
private:
  double temperature_;
  double humidity_;
};

class Database {
public:
  void Notify(double temp, double humidity, double pressure) {
    std::cout << "Saving all the info: ";
    std::cout << temp << " " << humidity << " " << pressure << std::endl;
    // Save this in a database
    // WriteDB(get_timestamp(), temp, humidity, pressure);
  }
};

class Weather {
public:
  Weather(WebDisplay * wd, Database * db) : web_display_(wd), database_(db) {}

  void Update(double temp, double humidity, double press) {
    temperature_ = temp;
    humidity_ = humidity;
    pressure_ = press;

    web_display_->Notify(temperature_, humidity_);
    database_->Notify(temperature_, humidity_, pressure_);
  }

private:
  double temperature_;
  double humidity_;
  double pressure_;
  WebDisplay * web_display_;
  Database * database_;
};

int main() {
  WebDisplay * wb = new WebDisplay;
  Database * db = new Database;
  Weather * weather = new Weather(wb, db);
  weather->Update(36,10,5.2);
}

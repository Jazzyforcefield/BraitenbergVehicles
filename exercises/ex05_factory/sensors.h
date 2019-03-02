class Sensors {
public:
  Sensors() : right_signal_(0), left_signal_(0) {}
  int get_right() { return right_signal_; }
  int get_left() { return left_signal_; }
  void Clear() { 
    right_signal_ = 0;
    left_signal_ = 0;
  }
private:
  int right_signal_;
  int left_signal_;
};

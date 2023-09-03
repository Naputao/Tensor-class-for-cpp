#include <exception>
#include <stdexcept>
#include <vector>
using namespace std;
class Tensor : public vector<double> {

public:
  Tensor() {}
  Tensor(const vector<double> vc) {
    this->reserve(vc.size());
    for (vector<double>::const_iterator it = vc.begin(); it != vc.end(); ++it) {
      this->push_back(*it);
    }
  }
  Tensor(const double vc[], const int size) {
    this->reserve(size);
    for (int it = 0; it != size; ++it) {
      this->push_back(vc[it]);
    }
  }

  void product(const Tensor ts) {
    if (ts.size() != this->size()) {
      throw domain_error("Diff Size!");
    }
    Tensor::const_iterator ts_it = ts.begin();
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) *= (*ts_it++);
    }
  }

  void product(const double d) {
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) *= d;
    }
  }

  void add(const Tensor ts) {
    if (ts.size() != this->size()) {
      throw domain_error("Diff Size!");
    }
    Tensor::const_iterator ts_it = ts.begin();
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) += (*ts_it++);
    }
  }

  void add(const double d) {
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) += d;
    }
  }
  void substract(const Tensor ts) {
    if (ts.size() != this->size()) {
      throw domain_error("Diff Size!");
    }
    Tensor::const_iterator ts_it = ts.begin();
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) -= (*ts_it++);
    }
  }

  void substract(const double d) {
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) -= d;
    }
  }

  void divide(const Tensor ts) {
    if (ts.size() != this->size()) {
      throw domain_error("Diff Size!");
    }
    Tensor::const_iterator ts_it = ts.begin();
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) /= (*ts_it++);
    }
  }

  void divide(const double d) {
    Tensor::iterator this_it = this->begin();
    while (this_it != this->end()) {
      (*this_it++) /= d;
    }
  }

  static double dotproduct(const Tensor ts0, const Tensor ts1) {
    if (ts0.size() != ts1.size()) {
      throw domain_error("Diff Size!");
    }
    Tensor::const_iterator it0 = ts0.begin();
    Tensor::const_iterator it1 = ts1.begin();
    double d = 0;
    while (it0 != ts0.end()) {
      d += (*it0++) * (*it1++);
    }
    return d;
  }

  static double sum(const Tensor ts) {
    Tensor::const_iterator it = ts.begin();
    double d = 0;
    while (it != ts.end()) {
      d += (*it++);
    }
    return d;
  }

  static Tensor *product(const Tensor ts0, const Tensor ts1) {
    if (ts0.size() != ts1.size()) {
      throw domain_error("Diff Size!");
    }
    Tensor *ans = new Tensor;
    ans->reserve(ts0.size());
    Tensor::const_iterator it0 = ts0.begin();
    Tensor::const_iterator it1 = ts1.begin();
    double d = 0;
    while (it0 != ts0.end()) {
      ans->push_back((*it0++) * (*it1++));
    }
    return ans;
  }

  static Tensor *product(const Tensor ts, const double d) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back(d * (*it));
    }
    return ans;
  }

  static Tensor *add(const Tensor ts0, const Tensor ts1) {
    if (ts0.size() != ts1.size()) {
      throw domain_error("Diff Size!");
    }
    Tensor *ans = new Tensor;
    ans->reserve(ts0.size());
    Tensor::const_iterator it0 = ts0.begin();
    Tensor::const_iterator it1 = ts1.begin();
    double d = 0;
    while (it0 != ts0.end()) {
      ans->push_back((*it0++) + (*it1++));
    }
    return ans;
  }

  static Tensor *add(const Tensor ts, const double d) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back(d + (*it));
    }
    return ans;
  }

  static Tensor *substract(const Tensor ts0, const Tensor ts1) {
    if (ts0.size() != ts1.size()) {
      throw domain_error("Diff Size!");
    }
    Tensor *ans = new Tensor;
    ans->reserve(ts0.size());
    Tensor::const_iterator it0 = ts0.begin();
    Tensor::const_iterator it1 = ts1.begin();
    double d = 0;
    while (it0 != ts0.end()) {
      ans->push_back((*it0++) - (*it1++));
    }
    return ans;
  }

  static Tensor *substract(const Tensor ts, const double d) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back((*it) - d);
    }
    return ans;
  }

  static Tensor *substract(const double d, const Tensor ts) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back(d - (*it));
    }
    return ans;
  }

  static Tensor *divide(const Tensor ts0, const Tensor ts1) {
    if (ts0.size() != ts1.size()) {
      throw domain_error("Diff Size!");
    }
    Tensor *ans = new Tensor;
    ans->reserve(ts0.size());
    Tensor::const_iterator it0 = ts0.begin();
    Tensor::const_iterator it1 = ts1.begin();
    double d = 0;
    while (it0 != ts0.end()) {
      ans->push_back((*it0++) / (*it1++));
    }
    return ans;
  }

  static Tensor *divide(const Tensor ts, const double d) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back((*it) / d);
    }
    return ans;
  }

  static Tensor *divide(const double d, const Tensor ts) {
    Tensor *ans = new Tensor;
    ans->reserve(ts.size());
    Tensor::const_iterator it = ts.begin();
    while (it != ts.end()) {
      ans->push_back(d / (*it));
    }
    return ans;
  }
};

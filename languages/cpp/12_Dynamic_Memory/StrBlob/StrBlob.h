#pragma once

#include <initializer_list>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;

public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

public:
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  // element access
  std::string &front();
  std::string &back();
  StrBlobPtr begin();
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, std::size_t sz = 0);

public:
  std::string &deref() const;
  StrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

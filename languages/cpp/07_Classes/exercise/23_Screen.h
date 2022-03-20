// Write your own version of the Screen class.

#ifndef SCREEN
#define SCREEN

#include <cstddef>
#include <string>
#include <vector>

class Screen {
public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}

  char get() const { return contents[cursor]; }
  char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;

private:
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  std::string contents;
  mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

inline void Screen::some_member() const { ++access_ctr; }

#endif /* SCREEN */

#include "API.h"
#ifndef LCD_CALLBACK
#define LCD_CALLBACK
namespace lcd
{
class Callback;
class Panel;
class Panel
{
public:
  virtual bool IsPassingDown() { return false; }
  virtual void Render() { }
  virtual void Evaluate(int selector) { }
};
class Callback
{
protected:
  bool Released;
  bool Initial;

public:
  virtual void Evaluate(int selection) {}
  virtual ~Callback() {}
  bool IsReleased()
  {
    return Released;
  }
};

class NavigateCallback : public Callback
{
public:
  NavigateCallback(MenuPanel *panel);
  ~NavigateCallback();
  void Evaluate(int selection);

private:
  MenuPanel *NavigatePanel;
};

class VoidCallback : public Callback
{
public:
  VoidCallback(void (*func)(int));
  ~VoidCallback();
  void Evaluate(int selection);

private:
  void (*Function)(int);
};

class SelectorCallback : public Callback
{
public:
  SelectorCallback(int *integer, FILE *output);
  ~SelectorCallback();
  void Evaluate(int selection);

private:
  int *Integer;
  FILE *Output;
};
}
#endif

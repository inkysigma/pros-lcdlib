#include "API.h"

#ifndef LCD_MENU_PANEL
#define LCD_MENU_PANEL
namespace lcd
{
class MenuPanel : public Panel
{
  private:
    const char *FirstLine;
    const char *SecondLine;
    unsigned short Passdown;
    Callback *FirstCallback;
    Callback *SecondCallback;
    Callback *ThirdCallback;
    Callback *FourthCallback;
    Callback *FifthCallback;
    Callback *SixthCallback;
    FILE *Uart;

  public:
    MenuPanel(const char *firstLine, const char *secondLine,
              Callback *firstCallback,
              Callback *secondCallback,
              Callback *thirdCallback,
              Callback *fourthCallback,
              Callback *fifthCallback,
              Callback *sixthCallback,
              FILE *uart);
    MenuPanel(const char *firstLine, const char *secondLine,
              Callback *firstCallback,
              Callback *secondCallback,
              Callback *thirdCallback,
              Callback *fourthCallback,
              Callback *fifthCallback,
              FILE *uart);
    MenuPanel(const char *firstLine, const char *secondLine,
              Callback *firstCallback,
              Callback *secondCallback,
              Callback *thirdCallback,
              Callback *fourthCallback,
              FILE *uart);
    MenuPanel(const char *firstLine, const char *secondLine,
              Callback *firstCallback,
              Callback *secondCallback,
              Callback *thirdCallback,
              FILE *uart);
    MenuPanel(const char *firstLine, const char *secondLine,
              Callback *firstCallback,
              Callback *secondCallback,
              FILE *uart);
    MenuPanel(const char *firstLine,
              const char *secondLine,
              Callback *firstCallback,
              FILE *uart);
    MenuPanel(const char *firstLine, const char *secondLine,
              FILE *uart);
    virtual ~MenuPanel();
    bool IsPassingDown();
    void Render();
    void Evaluate(int selector);
};
}
#endif
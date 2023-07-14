void send_mouse(int8_t *buf);

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 4
#define MOUSE_BACK 8
#define MOUSE_FORWARD 16
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE) # For compatibility with the Mouse library

class kMouse
{
  private:
    uint8_t _buttons;
  public:
    void buttons(uint8_t b);
    //  void click(uint8_t b = MOUSE_LEFT);
    void move(signed char x, signed char y, signed char wheel = 0);
    void press(uint8_t b = MOUSE_LEFT);   // press LEFT by default
    void release(uint8_t b = MOUSE_LEFT); // release LEFT by default
    bool isPressed(uint8_t b = MOUSE_LEFT); // check LEFT by default
};

void kMouse::move(signed char x, signed char y, signed char wheel)
{
  int8_t m[4];
  m[0] = _buttons;
  m[1] = x;
  m[2] = y;
  m[3] = wheel;
  send_mouse(m);
}

void kMouse::buttons(uint8_t b)
{
  if (b != _buttons)
  {
    _buttons = b;
    move(0, 0, 0);
  }
}

void kMouse::press(uint8_t b)
{
  _buttons = _buttons | b;
  int8_t m[4];
  m[0] = _buttons;
  m[1] = 0;
  m[2] = 0;
  m[3] = 0;
  send_mouse(m);
}

void kMouse::release(uint8_t b)
{
  _buttons = _buttons & ~b;
  int8_t m[4];
  m[0] = _buttons;
  m[1] = 0;
  m[2] = 0;
  m[3] = 0;
  send_mouse(m);
}

bool kMouse::isPressed(uint8_t b)
{
  if ((b & _buttons) > 0)
    return true;
  return false;
}

class kMouse Mouse;

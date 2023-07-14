const char pre_code[] PROGMEM = R"rawliteral(
#include "Keyboard.h"

void setup()
{
  Serial.begin(9600);
  Keyboard.begin();
}

void loop()
{
  macro();
  while(1);
}

void macro()
{
// 시작시 마우스를 좌측 상단으로 옮기고 시작  
for( int i = 0; i < 100; i++)
{
  Mouse.move(-100, 0, 0);
}
for( int i = 0; i < 100; i++)
{
  Mouse.move(0, -100, 0);
}
)rawliteral";

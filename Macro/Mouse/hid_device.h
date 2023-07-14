#define LED1 18
#define LED2 19
#define BTN1 15
#define BTN2 4

#include "kkeyboard.h"
#include "kMouse.h"
#include "setting.h"

#include <Arduino.h>
#include <Ticker.h>

unsigned char default_reset[6] =
{
  0x57, 0xAB, 0x0, 0x0C, 0x0, 0x0E
};

unsigned char set_mode_data[56] =
{

  0x57, 0xAB, 0x0, 0x9, 0x32, 0x0, 0x0, 0x0, 0x0, 0x1, 0xC2, 0x0, 0x0, 0x0, 0x0, 0x3, 0x86, 0x1A, 0x29, 0xE1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xBB
};

// 마우스 키보드 제조사 설정 데이타
unsigned char set_manufact[100] =
{
  0x57, 0xAB, 0x0, 0x0B, 0x8, 0x0, 0x6, 0x6A, 0x79, 0x73, 0x6F, 0x66, 0x74, 0xBA
};

unsigned char set_product[100] =
{
  0x57, 0xAB, 0x0, 0x0B, 0x13, 0x1, 0x11, 0x6B, 0x70, 0x72, 0x6F, 0x6A, 0x65, 0x63, 0x74, 0x20, 0x75, 0x73, 0x62, 0x20, 0x68, 0x69, 0x64, 0x20, 0x73
};

// 칩 초기화 하기
void ch9329_initalize()
{
  // 초기화 ( 최초 한번만 실행하면 됨)
  ///////////////////////////////////////////////////////////
  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  delay(100);
  for ( int i = 0; i < 6; i++)
  {
    Serial1.write(default_reset[i]);
  }
  delay(1000);
  Serial1.begin(115200, SERIAL_8N1, 16, 17);
  delay(100);
  for ( int i = 0; i < 6; i++)
  {
    Serial1.write(default_reset[i]);
  }
}

void ch9329_set_mode(int mode)
// 통신 속도 및 모드 설정 함수
{
  set_mode_data[5] = mode; // 0 ~ 3 : 0 : 키보드 마우스 CUSTOM , 1 : 키보드 , 2 : 키보드 + 마우스 , 3 : CUSTOM

  set_mode_data[16] = ch9329_vid;
  set_mode_data[17] = ch9329_vid >> 8;
  set_mode_data[18] = ch9329_pid;
  set_mode_data[19] = ch9329_pid >> 8;

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < 55; i++)
    {
      Serial1.write(set_mode_data[i]);
      check_sum += set_mode_data[i];
    }
    Serial1.write(check_sum);
  }
}

void ch9329_set_manufact(char *manufact)
// 제조사 설정
{
  int manufact_len = strlen(manufact);
  set_manufact[4] = manufact_len + 2;
  set_manufact[6] = manufact_len;
  strcpy((char*)(set_manufact + 7), manufact);

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < manufact_len + 7 ; i++)
    {
      Serial1.write(set_manufact[i]);
      check_sum += set_manufact[i];
    }
    Serial1.write(check_sum);
  }
}

void ch9329_set_product(char *product)
// 제품명 설정
{
  int product_len = strlen(product);
  set_product[4] = product_len + 2;
  set_product[6] = product_len;
  strcpy((char*)(set_product + 7), product);

  delay(100);
  {
    uint8_t check_sum = 0;
    for ( int i = 0; i < product_len + 7 ; i++)
    {
      Serial1.write(set_product[i]);
      check_sum += set_product[i];
    }
    Serial1.write(check_sum);
  }
}

Ticker blinker;

void usb_hid_process();

void onTimer()
{
  usb_hid_process();
}

bool check_ch9329()
{
  Serial1.write(0x57);
  Serial1.write(0xAB);
  Serial1.write(0x00);
  Serial1.write(0x01);
  Serial1.write(0x00);
  Serial1.write(0x03);
  delay(1000);
  if ( Serial1.available() < 14 ) return false;

  while (Serial1.available() )
  {
    Serial.println(Serial1.read(), HEX);
  }
  Serial.println("######################");
  return true;
}

void usb_hid_init()
{
  // LED 및 버튼 초기화
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, 16, 17);
  Serial2.begin(115200, SERIAL_8N1, 23, -1);
  Serial2.setRxBufferSize(1024);

  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  ch9329_set_mode(0);
  delay(100);
  ch9329_set_manufact((char*)keyboard_manufact);
  delay(100);
  ch9329_set_product((char*)keyboard_product);
  delay(100);
  Serial1.begin(115200, SERIAL_8N1, 16, 17);
  ch9329_set_mode(0);
  delay(100);
  ch9329_set_manufact((char*)keyboard_manufact);
  delay(100);
  ch9329_set_product((char*)keyboard_product);
  delay(100);
  blinker.attach(0.001, onTimer);
}

void send_keyboard(uint8_t *buf)
{
  uint8_t buffer[14];
  buffer[0] = 0x57;
  buffer[1] = 0xAB;
  buffer[2] = 0x00;
  buffer[3] = 0x02;
  buffer[4] = 0x08;

  memcpy(buffer + 5, buf, 8);

  uint16_t sum = 0;
  for ( int i = 0; i < 13; i++)
  {
    sum = sum + buffer[i];
  }
  buffer[13] = sum;

  Serial1.write(buffer, 14);
}

void send_mouse(int8_t *buf)
{
  uint8_t buffer[11];
  buffer[0] = 0x57;
  buffer[1] = 0xAB;
  buffer[2] = 0x00;
  buffer[3] = 0x05;
  buffer[4] = 0x05;
  buffer[5] = 0x01;

  memcpy(buffer + 6, buf, 4);

  uint16_t sum = 0;
  for ( int i = 0; i < 10; i++)
  {
    sum = sum + buffer[i];
  }

  buffer[10] = sum;
  Serial1.write(buffer, 11);
}

unsigned long prev_recording_millis = 0;

uint8_t prev_keyboard[8];

void check_modifier(uint8_t *prev_buf, uint8_t *cur_buf)
{
  for ( int i = 0; i < 8; i++)
  {
    int prev_val = ( prev_buf[0] >> i ) & 0b00000001;
    int cur_val = ( cur_buf[0] >> i ) & 0b00000001;

    if ( ( prev_val == 0 ) && ( cur_val == 1 ) ) // 눌러진 경우
    {
      Serial.print("Keyboard.press(");
      switch (i)
      {
        case 0:
          Serial.print("KEY_LEFT_CTRL");
          break;
        case 1:
          Serial.print("KEY_LEFT_SHIFT");
          break;
        case 2:
          Serial.print("KEY_LEFT_ALT");
          break;
        case 3:
          Serial.print("KEY_LEFT_GUI");
          break;
        case 4:
          Serial.print("KEY_RIGHT_CTRL");
          break;
        case 5:
          Serial.print("KEY_RIGHT_SHIFT");
          break;
        case 6:
          Serial.print("KEY_RIGHT_ALT");
          break;
        case 7:
          Serial.print("KEY_RIGHT_GUI");
          break;
      }
      Serial.println(");");
    }
    if ( ( prev_val == 1 ) && ( cur_val == 0 ) ) // 뗀 경우
    {
      Serial.print("Keyboard.release(");
      switch (i)
      {
        case 0:
          Serial.print("KEY_LEFT_CTRL");
          break;
        case 1:
          Serial.print("KEY_LEFT_SHIFT");
          break;
        case 2:
          Serial.print("KEY_LEFT_ALT");
          break;
        case 3:
          Serial.print("KEY_LEFT_GUI");
          break;
        case 4:
          Serial.print("KEY_RIGHT_CTRL");
          break;
        case 5:
          Serial.print("KEY_RIGHT_SHIFT");
          break;
        case 6:
          Serial.print("KEY_RIGHT_ALT");
          break;
        case 7:
          Serial.print("KEY_RIGHT_GUI");
          break;
      }
      Serial.println(");");
    }
  }
  //  prev_buf[0] = cur_buf[0];
}

void OemToCodeKey(uint8_t key)
{
  int key_val = 0;

  if ( key == 0x28 )
  {
    Serial.print("KEY_RETURN");
  }
  else if ( key == 0x29 )
  {
    Serial.print("KEY_ESC");
  }
  else if ( key == 0x2A )
  {
    Serial.print("KEY_BACKSPACE");
  }
  else if ( key == 0x2B )
  {
    Serial.print("KEY_TAB");
  }
  else if ( key == 0x39 )
  {
    Serial.print("KEY_CAPS_LOCK");
  }
  else if ( key == 0x49 )
  {
    Serial.print("KEY_INSERT");
  }
  else if ( key == 0x4A )
  {
    Serial.print("KEY_HOME");
  }
  else if ( key == 0x4B )
  {
    Serial.print("KEY_PAGE_UP");
  }
  else if ( key == 0x4C )
  {
    Serial.print("KEY_DELETE");
  }
  else if ( key == 0x4D )
  {
    Serial.print("KEY_END");
  }
  else if ( key == 0x4E )
  {
    Serial.print("KEY_PAGE_DOWN");
  }
  else if ( key == 0x4F )
  {
    Serial.print("KEY_RIGHT_ARROW");
  }
  else if ( key == 0x50 )
  {
    Serial.print("KEY_LEFT_ARROW");
  }
  else if ( key == 0x51 )
  {
    Serial.print("KEY_DOWN_ARROW");
  }
  else if ( key == 0x52 )
  {
    Serial.print("KEY_UP_ARROW");
  }
  // [F1-F12]
  else if (key >= 0x3A && key <= 0x45)
  {
    Serial.print("KEY_F");
    Serial.print(key - 0x3A + 1);
  }
  // [a-z]
  else if (key > 0x03 && key < 0x1e)
  {
    key_val = (key - 4 + 'a');
    Serial.print("'");
    Serial.write(key_val);
    Serial.print("'");
  }
  // Numbers
  else if (key > 0x1d && key < 0x27)
  {
    key_val = (key - 0x1e + '1');
    Serial.print("'");
    Serial.write(key_val);
    Serial.print("'");
  }
  // Keypad Numbers
  else if (key > 0x58 && key < 0x62)
  {
    key_val = key;
    Serial.print("0x");
    Serial.print(key_val, HEX);
  }
  /*
    else if (key > 0x2c && key < 0x39) // symKeysUp , symKeysLo
    {
      key_val = key;
      Serial.print(key_val, HEX);
    }
  */
  else if (key > 0x53 && key < 0x59)
  {
    key_val = key;
    Serial.print("0x");
    Serial.print(key_val, HEX);
  }
  else if ( key == KEY_RETURN)
  {
    Serial.print("KEY_RETURN");
  }
  else
  {
    int i;
    for ( int i = 0; i < 128; i++)
    {
      if ( key == _asciimap[i] )
      {
        Serial.print("0x");
        Serial.print(i, HEX);
      }
    }

    if ( i == 128 )
    {
      Serial.print("0x00 /* KEY FAIL */");
    }

    /*
        key_val = key;
        Serial.print("0x");
        Serial.print(key_val, HEX);
    */
  }
  return;
}

void check_key(uint8_t *prev_buf, uint8_t *cur_buf)
{
  /*
    for( int i = 0; i < 8; i++)
    {
      Serial.print((int)prev_buf[i]);
      Serial.print(",");
    }
    Serial.println("");
    for( int i = 0; i < 8; i++)
    {
      Serial.print((int)cur_buf[i]);
      Serial.print(",");
    }
    Serial.println("");
  */

  // release 키 찾기
  {
    int i;
    for ( i = 1; i < 8; i++)
    {
      int prev_value = prev_buf[i];
      if ( prev_value != 0 ) // 기존에 키가 있었던 경우만
      {
        int j;
        for ( j = 1; j < 8; j++)
        {
          int cur_value = cur_buf[j];
          if ( prev_value == cur_value )
          {
            break;
          }
        }
        if ( j == 8 ) // 기존의 눌러진 키가 현재 없는 경우
        {
          Serial.print("Keyboard.release(");
          OemToCodeKey(prev_value);
          //          Serial.print(prev_value);
          Serial.println(");");
          //          prev_buf[i] = 0;
        }
      }
    }
  }

  // press 키 찾기
  {
    int i;
    for ( i = 1; i < 8; i++)
    {
      int cur_value = cur_buf[i];
      if ( cur_value != 0 ) // 현재 눌러진 키만 체크
      {
        int j;
        for ( j = 1; j < 8; j++)
        {
          int prev_value = prev_buf[j];
          if ( prev_value == cur_value )
          {
            break;
          }
        }
        if ( j == 8 ) // 현재 눌러진 키가 기존에 없는 경우
        {
          Serial.print("Keyboard.press(");
          OemToCodeKey(cur_value);
          //          Serial.print(cur_value);
          Serial.println(");");
          //          cur_buf[i] = 0;
        }
      }
    }
  }
}

int prev_mouse_button = 0;

void usb_hid_process()
{
  if ( Serial2.available() >= 6 )
  {
    int val = Serial2.read();
    if ( val == 20 )
    {
      int cmd = Serial2.read();

      if ( cmd == 2 ) // 마우스 신호의 경우
      {
        int8_t buf[4];
        Serial2.read((char*)buf, 4);

        if ( recording_mode == true )
        {
          unsigned long cur = millis();
          int delay_value = cur - prev_recording_millis;
          Serial.print("delay(");
          Serial.print(delay_value);
          Serial.println(");");
          prev_recording_millis = cur;

          if ( prev_mouse_button != buf[0] )
          {
            int prev_left_btn = prev_mouse_button & MOUSE_LEFT;
            int prev_right_btn = prev_mouse_button & MOUSE_RIGHT;
            int prev_mid_btn = prev_mouse_button & MOUSE_MIDDLE;

            int left_btn = buf[0] & MOUSE_LEFT;
            int right_btn = buf[0] & MOUSE_RIGHT;
            int mid_btn = buf[0] & MOUSE_MIDDLE;

            if ( ( prev_left_btn == 0 ) && ( left_btn != 0 ) )
            {
              Serial.println("Mouse.press(MOUSE_LEFT);");
            }
            if ( ( prev_left_btn != 0 ) && ( left_btn == 0 ) )
            {
              Serial.println("Mouse.release(MOUSE_LEFT);");
            }

            if ( ( prev_right_btn == 0 ) && ( right_btn != 0 ) )
            {
              Serial.println("Mouse.press(MOUSE_RIGHT);");
            }
            if ( ( prev_right_btn != 0 ) && ( right_btn == 0 ) )
            {
              Serial.println("Mouse.release(MOUSE_RIGHT);");
            }

            if ( ( prev_mid_btn == 0 ) && ( mid_btn != 0 ) )
            {
              Serial.println("Mouse.press(MOUSE_MIDDLE);");
            }
            if ( ( prev_mid_btn != 0 ) && ( mid_btn == 0 ) )
            {
              Serial.println("Mouse.release(MOUSE_MIDDLE);");
            }
            prev_mouse_button = buf[0];
          }

          if ( ( buf[1] != 0 ) || ( buf[2] != 0 ) || ( buf[3] != 0 ) )
          {
            Serial.print("Mouse.move(");
            Serial.print(buf[1]);
            Serial.print(",");
            Serial.print(buf[2]);
            Serial.print(",");
            Serial.print(buf[3]);
            Serial.println(");");
          }
        }

        if ( echo_mode == true )
        {
          Serial.print("MOUSE DATA = ");
          Serial.print((int)buf[0]);
          Serial.print(",");
          Serial.print((int)buf[1]);
          Serial.print(",");
          Serial.print((int)buf[2]);
          Serial.print(",");
          Serial.print((int)buf[3]);
          Serial.println("");
        }

        if ( mouse_flag == true )
        {
          send_mouse(buf);
        }
      }

      if ( cmd == 6 ) // 키보드 신호의 경우
      {
        unsigned long start_millis = millis();
        if ( Serial2.available() < 8 )
        {
          if ( millis() > start_millis + 100 ) return;
        }

        uint8_t buf[8];
        Serial2.read((char*)buf, 8);

        if ( recording_mode == true )
        {
          unsigned long cur = millis();
          int delay_value = cur - prev_recording_millis;
          Serial.print("delay(");
          Serial.print(delay_value);
          Serial.println(");");
          prev_recording_millis = cur;


          int i;
          for ( int i = 0; i < 8; i++)
          {
            if ( buf[i] != 0 ) break;
          }
          if ( i == 8 )
          {
            Serial.println("// Keyboard.releaseAll();");
          }
          check_modifier(prev_keyboard, buf);
          check_key(prev_keyboard, buf);
          memcpy(prev_keyboard, buf, 8);
        }


        /*
                  Serial.print("delay(random(");
                  int delay_value = cur - prev_recording_millis;
                  Serial.print(int(delay_value*(1.0-random_ratio/100.0)));
                  Serial.print(",");
                  Serial.print(int(delay_value*(1.0+random_ratio/100.0)));
                  Serial.print(")); //");
                  Serial.println(delay_value);

                  Serial.print("send_keyboard2(");
                  Serial.print((int)buf[0]);
                  Serial.print(",");
                  Serial.print((int)buf[1]);
                  Serial.print(",");
                  Serial.print((int)buf[2]);
                  Serial.print(",");
                  Serial.print((int)buf[3]);
                  Serial.print(",");
                  Serial.print((int)buf[4]);
                  Serial.print(",");
                  Serial.print((int)buf[5]);
                  Serial.print(",");
                  Serial.print((int)buf[6]);
                  Serial.print(",");
                  Serial.print((int)buf[7]);
                  Serial.print(");");
                  Serial.println("");
        */

        if ( echo_mode == true )
        {
          Serial.print("KEYBOARD DATA = ");
          Serial.print((int)buf[0], HEX);
          Serial.print(",");
          Serial.print((int)buf[1], HEX);
          Serial.print(",");
          Serial.print((int)buf[2], HEX);
          Serial.print(",");
          Serial.print((int)buf[3], HEX);
          Serial.print(",");
          Serial.print((int)buf[4], HEX);
          Serial.print(",");
          Serial.print((int)buf[5], HEX);
          Serial.print(",");
          Serial.print((int)buf[6], HEX);
          Serial.print(",");
          Serial.print((int)buf[7], HEX);
          Serial.println("");
        }

        if ( keyboard_flag == true )
        {
          send_keyboard(buf);
        }
      }
    }
  }
}

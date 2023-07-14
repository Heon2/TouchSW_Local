#define LED1 18
#define LED2 19
#define BTN1 15
#define BTN2 4

#include "kkeyboard.h"
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

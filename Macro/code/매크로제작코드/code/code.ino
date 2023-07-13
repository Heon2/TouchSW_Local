// ESP32 2.0.4
// 업로드 옵션 : default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
int recording_mode = false;

#include "hid_device.h"

#define CHECK_STOP() if ( check_stop() == false ) return;

volatile int play_flag = 0; // 0 : 정지 , 1 : 재생
volatile unsigned long prev_btn1_change_millis;
volatile int pause_flag = 0; // 1 : 일시정지
volatile unsigned long prev_btn2_change_millis;

int start_msg_flag = 0;
int end_msg_flag = 0;

void stop_isr()
{
  if ( ( millis() - prev_btn1_change_millis ) < 200 ) return; // debouncing
  play_flag = !play_flag;
  prev_btn1_change_millis = millis();

  if ( play_flag == true )
  {
    recording_mode = true;
    prev_recording_millis = millis();
    start_msg_flag = 1;
  }
  else
  {
    recording_mode = false;
    end_msg_flag = 1;
  }
}

void pause_isr()
{
  if ( ( millis() - prev_btn2_change_millis ) < 200 ) return; // debouncing
  pause_flag = !pause_flag;
  prev_btn2_change_millis = millis();
}

bool check_stop()
{
  while (1)
  {
    if ( play_flag == 0 )
      // 재생 정지된 경우 구동 정지
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      pause_flag = 0;
      return false; // 구동 정지
    }
    else
    {
      digitalWrite(LED1, HIGH);
    }

    if ( pause_flag == 0 )
      // 일시 정지가 아닌 경우 구동
    {
      digitalWrite(LED2, LOW);
      return true;
    }
    digitalWrite(LED2, HIGH);
  }
  return true;
}

void setup()
{
  Serial.begin(11500);
  // 마우스, 키보드 초기화
  usb_hid_init();
  keyboard_flag = true; // 키보드 전송 모드 ON
  mouse_flag = true; // 마우스 전송 모드 ON
  macro_flag = true; // 매크로 모드 OFF
  echo_mode = false; // 시리얼 모니터에 마우스, 키보드 신호 출력
  attachInterrupt(BTN1, stop_isr, RISING);
  attachInterrupt(BTN2, pause_isr, RISING);
  ///////////////////////////////////////////////////////////
  // 레오나르도의 setup의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
}

void loop()
{
  if ( start_msg_flag == 1 )
  {
    Serial.println("//###########################################");
    Serial.println("//###    MACRO START    #####################");
    Serial.println("//###########################################");
    Serial.println("//###########################################");
    Serial.println("void macro_code()");
    Serial.println("{");
    start_msg_flag = 0;
  }

  if ( end_msg_flag == 1 )
  {
    Serial.println("}");
    Serial.println("//###########################################");
    Serial.println("//###    MACRO END      #####################");
    Serial.println("//###########################################");
    Serial.println("//###########################################");
    end_msg_flag = 0;
  }
}

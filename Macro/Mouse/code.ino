// ESP32 2.0.4
// 업로드 옵션 : default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)

#include "codedata.h"

#define CHECK_STOP() if ( check_stop() == false ) return;

int recording_mode = false;

#include "hid_device.h"

volatile int play_flag = 0; // 0 : 정지 , 1 : 재생
volatile unsigned long prev_btn1_change_millis;
volatile unsigned long prev_btn2_change_millis;

int start_msg_flag = 0;
int end_msg_flag = 0;

void recording_isr()
{
  if ( ( millis() - prev_btn1_change_millis ) < 200 ) return; // debouncing

  // 재생중일 경우 기록 시작 안함
  if ( play_flag != false ) return;

  prev_btn1_change_millis = millis();

  if ( recording_mode == false )
    // 기록중이 아니었으면
  {
    recording_mode = true; // 기록중으로
    prev_recording_millis = millis();
    start_msg_flag = 1;
  }
  else
  {
    recording_mode = false;
    end_msg_flag = 1;
  }
}

void play_isr()
{
  if ( ( millis() - prev_btn2_change_millis ) < 200 ) return; // debouncing

  if ( recording_mode == true ) return; // 기록중일때는 재생 안함
  play_flag = !play_flag;
  prev_btn2_change_millis = millis();
}

bool check_stop()
{
  if ( play_flag == 0 )
    // 재생 정지된 경우 구동 정지
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    return false; // 구동 정지
  }
  else
  {
    digitalWrite(LED1, HIGH);
  }
  return true;
}

void setup()
{
  Serial.begin(115200);
  // 마우스, 키보드 초기화
  usb_hid_init();
  keyboard_flag = true; // 키보드 전송 모드 ON
  mouse_flag = true; // 마우스 전송 모드 ON
  macro_flag = true; // 매크로 모드 OFF
  echo_mode = false; // 시리얼 모니터에 마우스, 키보드 신호 출력
  attachInterrupt(BTN1, recording_isr, RISING);
  attachInterrupt(BTN2, play_isr, RISING);
  ///////////////////////////////////////////////////////////
  // 레오나르도의 setup의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
}

void loop()
{
  if ( start_msg_flag == 1 )
  {
    Mouse.buttons(0); Mouse.move(0, 0, 0); // 마우스 버튼 모두 떼기
    mouse_move_to_left_top();
    Serial.println(pre_code);
    start_msg_flag = 0;
  }

  if ( end_msg_flag == 1 )
  {
    Serial.println("}");
    end_msg_flag = 0;
  }

  if ( play_flag == true )
  {
    macro();
    play_flag = false;
  }
}

void mouse_move_to_left_top()
{
  for ( int i = 0; i < 100; i++)
  {
    Mouse.move(-100, 0, 0);
  }
  for ( int i = 0; i < 100; i++)
  {
    Mouse.move(0, -100, 0);
  }
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
}

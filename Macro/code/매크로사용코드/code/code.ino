// ESP32 2.0.4
// 업로드 옵션 : default 4MB with SPIFFS (1.2MB / 1.5MB SPIFFS)
#include "hid_device.h"

#define CHECK_STOP() if ( check_stop() == false ) return;

volatile int play_flag = 0; // 0 : 정지 , 1 : 재생
volatile unsigned long prev_btn1_change_millis;
volatile int pause_flag = 0; // 1 : 일시정지
volatile unsigned long prev_btn2_change_millis;

////////////////////////////////////////////////////////////
// 스인미
////////////////////////////////////////////////////////////
const char sinmi_command = KEY_INSERT;  // 스인미
unsigned long sinmi_count;  // 스인미 쿨타임 계산 변수
long sinmi_rand_sec;        // 스인미 쿨타임 랜덤 배정 변수
const long sinmi_cooltime_min = 260000;
const long sinmi_cooltime_max = 300000;

void sinmi()
{
    Keyboard.press(sinmi_command);      // PRESS sinmi
    random_delay(100, 150);
    Keyboard.release(sinmi_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 인피니티 스펠
////////////////////////////////////////////////////////////
const char infinity_command = KEY_F1;  // 인피니티
unsigned long infinity_count;  // 인피니티 쿨타임 계산 변수
long infinity_rand_sec;        // 인피니티 쿨타임 랜덤 배정 변수
const long infinity_cooltime_min = 130000;
const long infinity_cooltime_max = 150000;

void infinity()
{
    Keyboard.press(infinity_command);      // PRESS infinity
    random_delay(100, 150);
    Keyboard.release(infinity_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 매서풀
////////////////////////////////////////////////////////////
const char magic_command = KEY_F2;  // 매서풀
unsigned long magic_count;  // 매서풀 쿨타임 계산 변수
long magic_rand_sec;        // 매서풀 쿨타임 랜덤 배정 변수
const long magic_cooltime_min = 190000;
const long magic_cooltime_max = 230000;

void magic()
{
    Keyboard.press(magic_command);      // PRESS 매서풀
    random_delay(100, 150);
    Keyboard.release(magic_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 그여축
////////////////////////////////////////////////////////////
const char grandis_command = KEY_F3;  // 그여축
unsigned long grandis_count;  // 그여축 쿨타임 계산 변수
long grandis_rand_sec;        // 그여축 쿨타임 랜덤 배정 변수
const long grandis_cooltime_min = 250000;
const long grandis_cooltime_max = 300000;

void grandis()
{
    Keyboard.press(grandis_command);      // PRESS 그여축
    random_delay(100, 150);
    Keyboard.release(grandis_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 로디드 다이스
////////////////////////////////////////////////////////////
const char dice_command = '1';  // 다이스
unsigned long dice_count;  // 다이스 쿨타임 계산 변수
long dice_rand_sec;        // 다이스 쿨타임 랜덤 배정 변수
const long dice_cooltime_min = 250000;
const long dice_cooltime_max = 300000;

void dice()
{
    Keyboard.press(dice_command);      // PRESS 다이스
    random_delay(100, 150);
    Keyboard.release(dice_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 경험치 도핑 : 경쿠, 경뿌, 익스골드, 경축비
////////////////////////////////////////////////////////////
const char exp0_command = '7';  // 경쿠
const char exp1_command = '8';  // 경뿌
const char exp2_command = '9';  // 익스골드
const char exp3_command = '0';  // 경축비
unsigned long exp_count;  // 도핑 쿨타임 계산 변수
long exp_rand_sec;        // 다이스 쿨타임 랜덤 배정 변수
const long exp_cooltime_min = 1820000;  //30분 20초
const long exp_cooltime_max = 1830000;  //30분 30초

void exp()
{
    Keyboard.press(exp0_command);      // PRESS 경쿠
    random_delay(100, 150);
    Keyboard.release(exp0_command);
    random_delay(13, 30);
    Keyboard.press(exp1_command);      // PRESS 경뿌
    random_delay(100, 150);
    Keyboard.release(exp1_command);
    random_delay(13, 30);
    Keyboard.press(exp2_command);      // PRESS 익스골드
    random_delay(100, 150);
    Keyboard.release(exp2_command);
    random_delay(13, 30);
    Keyboard.press(exp3_command);      // PRESS 경축비
    random_delay(100, 150);
    Keyboard.release(exp3_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// 재획비
////////////////////////////////////////////////////////////
const char exp120_command = '1';  // 재획비
unsigned long exp120_count;  // 재획비 쿨타임 계산 변수
long exp120_rand_sec;        // 재획비 쿨타임 랜덤 배정 변수
const long exp120_cooltime_min = 7200000;
const long exp120_cooltime_max = 7260000;

void exp120()
{
    Keyboard.press(exp120_command);      // PRESS 재획비
    random_delay(100, 150);
    Keyboard.release(exp120_command);
    random_delay(13, 30);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

void random_delay(int boundary_1, int boundary_2)
{
    int randNumber = random(boundary_1, boundary_2);
    delay(randNumber);
}


void send_keyboard2(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7, uint8_t data8)
{
  uint8_t buffer[8];
  buffer[0] = data1;
  buffer[1] = data2;
  buffer[2] = data3;
  buffer[3] = data4;
  buffer[4] = data5;
  buffer[5] = data6;
  buffer[6] = data7;
  buffer[7] = data8;
  send_keyboard(buffer);
}

void stop_isr()
{
  if ( ( millis() - prev_btn1_change_millis ) < 200 ) return; // debouncing
  play_flag = !play_flag;
  prev_btn1_change_millis = millis();
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
  echo_mode = true; // 시리얼 모니터에 마우스, 키보드 신호 출력
  attachInterrupt(BTN1, stop_isr, RISING);
  attachInterrupt(BTN2, pause_isr, RISING);
  sinmi_count = millis();
  sinmi_rand_sec = random(sinmi_cooltime_min, sinmi_cooltime_max);

  ///////////////////////////////////////////////////////////
  // 레오나르도의 setup의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
}

int SPECTOR_MACRO_FUNCTION_NUM = 9; //  스펙터 매크로 개수
int LEF_MACRO_FUNCTION_NUM = 9; // 레프 매크로 개수

void loop()
{
  ///////////////////////////////////////////////////////////
  // 레오나르도의 loop의 내용을 아래에 추가하세요
  ///////////////////////////////////////////////////////////
  CHECK_STOP();
  
  spector_random_macro(SPECTOR_MACRO_FUNCTION_NUM);   // 랜덤으로 스팩터 매크로 함수 실행
  lef_random_macro(LEF_MACRO_FUNCTION_NUM);         // 랜덤으로 레프 매크로 함수 실행

  // 스인미 실행 체크
  if(( millis() - sinmi_count ) > sinmi_rand_sec )
  {
      sinmi();
      sinmi_rand_sec = random(sinmi_cooltime_min, sinmi_cooltime_max);
      sinmi_count = millis();
      CHECK_STOP();
  }
  Keyboard.releaseAll();

}

void spector_random_macro(int num)
{
  int specter_random_factor = random(num);

  if ( specter_random_factor == 0 ) specter_macro_code0();
  if ( specter_random_factor == 1 ) specter_macro_code1();
  if ( specter_random_factor == 2 ) specter_macro_code2();
  if ( specter_random_factor == 3 ) specter_macro_code3();
  if ( specter_random_factor == 4 ) specter_macro_code4();
  if ( specter_random_factor == 5 ) specter_macro_code5();
  if ( specter_random_factor == 6 ) specter_macro_code6();
  if ( specter_random_factor == 7 ) specter_macro_code7();
  if ( specter_random_factor == 8 ) specter_macro_code8();
}

void lef_random_macro(int num)
{
  int lef_random_factor = random(num);

  if ( lef_random_factor == 0 ) lef_macro_code0();
  if ( lef_random_factor == 1 ) lef_macro_code1();
  if ( lef_random_factor == 2 ) lef_macro_code2();
  if ( lef_random_factor == 3 ) lef_macro_code3();
  if ( lef_random_factor == 4 ) lef_macro_code4();
  if ( lef_random_factor == 5 ) lef_macro_code5();
  if ( lef_random_factor == 6 ) lef_macro_code6();
  if ( lef_random_factor == 7 ) lef_macro_code7();
  if ( lef_random_factor == 8 ) lef_macro_code8();
}
//###########################################
//###    MACRO START    #####################
//###########################################
//###########################################
void ex_macro_code1()
{
delay(168);
send_keyboard2(0,0,11,0,0,0,0,0);
delay(105);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(132);
send_keyboard2(0,0,12,0,0,0,0,0);
delay(84);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(152);
send_keyboard2(0,0,14,0,0,0,0,0);
delay(121);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,13,0,0,0,0,0);
delay(136);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(158);
send_keyboard2(0,0,15,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(873);
send_keyboard2(0,0,16,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,17,0,0,0,0,0);
delay(95);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(183);
send_keyboard2(0,0,18,0,0,0,0,0);
delay(111);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(68);
send_keyboard2(0,0,19,0,0,0,0,0);
delay(132);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(152);
send_keyboard2(0,0,20,0,0,0,0,0);
delay(163);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(658);
send_keyboard2(0,0,21,0,0,0,0,0);
delay(101);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(68);
send_keyboard2(0,0,22,0,0,0,0,0);
delay(111);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(95);
send_keyboard2(0,0,23,0,0,0,0,0);
delay(131);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(110);
send_keyboard2(0,0,24,0,0,0,0,0);
delay(85);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(116);
send_keyboard2(0,0,25,0,0,0,0,0);
delay(126);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(84);
send_keyboard2(0,0,26,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(262);
send_keyboard2(0,0,27,0,0,0,0,0);
delay(100);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(205);
send_keyboard2(0,0,28,0,0,0,0,0);
delay(79);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(158);
send_keyboard2(0,0,29,0,0,0,0,0);
delay(110);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(173);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(59);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(79);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(106);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(73);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,40,0,0,0,0,0);
delay(58);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(2018);
send_keyboard2(0,0,89,0,0,0,0,0);
delay(68);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(111);
send_keyboard2(0,0,90,0,0,0,0,0);
delay(58);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(105);
send_keyboard2(0,0,91,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(283);
send_keyboard2(0,0,92,0,0,0,0,0);
delay(64);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(110);
send_keyboard2(0,0,93,0,0,0,0,0);
delay(69);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(131);
send_keyboard2(0,0,94,0,0,0,0,0);
delay(64);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(324);
send_keyboard2(0,0,95,0,0,0,0,0);
delay(74);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,96,0,0,0,0,0);
delay(48);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(142);
send_keyboard2(0,0,97,0,0,0,0,0);
delay(84);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
delay(283);
send_keyboard2(0,0,98,0,0,0,0,0);
delay(73);
send_keyboard2(0,0,0,0,0,0,0,0);
CHECK_STOP();
}
//###########################################
//###    MACRO END      #####################
//###########################################
//###########################################

void specter_macro_code0()
{

}
void specter_macro_code1()
{
  
}
void specter_macro_code2()
{
  
}
void specter_macro_code3()
{
  
}
void specter_macro_code4()
{
  
}
void specter_macro_code5()
{
  
}
void specter_macro_code6()
{
  
}
void specter_macro_code7()
{
  
}
void specter_macro_code8()
{
  
}
void specter_macro_code9()
{
  
}

void lef_macro_code0()
{
  
}
void lef_macro_code1()
{
  
}
void lef_macro_code2()
{
  
}
void lef_macro_code3()
{
  
}
void lef_macro_code4()
{
  
}
void lef_macro_code5()
{
  
}
void lef_macro_code6()
{
  
}
void lef_macro_code7()
{
  
}
void lef_macro_code8()
{
  
}
#include <Keyboard.h>   // Keyboard library
int factor = 3.0;
void attack();

const int button = 7;
const int led = 13;

volatile int flag = 0;  // 0:매크로 정지, 1:매크로 구동

// 스킬 정의
// 기본 공격(크루얼스텝)
const char attack_command_1 = 'v';  // 기본공격
const char attack_command_2 = 'b';  // 기본공격
const char attack_command_3 = KEY_LEFT_CTRL;    // 기본공격
const char meso_explosion_command = KEY_LEFT_SHIFT; // 메소 익스플로젼
const char bail_of_shadow_command = 'a';    // 베일 오브 쉐도우(전체스킬)
const char dark_flare_command = 'd';    // 다크 플레어
const char jump_command = KEY_LEFT_ALT;  // 점프
const char double_jump_command = 'x';   // 더블 점프

const char sinmi_command = KEY_F7;  // 스인미
unsigned long sinmi_count;  // 스인미 쿨타임 계산 변수
long sinmi_rand_sec;        // 스인미 쿨타임 랜덤 배정 변수
const long sinmi_cooltime_min = 260000;
const long sinmi_cooltime_max = 300000;

unsigned long attack_count; // 1~5번 공격 쿨타임 계산 변수
long attack_rand_sec;       // 1~5번 공격 쿨타임 랜덤 배정 변수
const long attack_cooltime_min = 60000;
const long attack_cooltime_max = 70000;

void random_delay(int boundary_1, int boundary_2)
{
    int randNumber = random(boundary_1, boundary_2);
    delay(randNumber);
}

void isr();
volatile unsigned long button_millis;   // Debouncing을 위하여 마지막으로 버튼 누른 시간을 저장

void isr()
{
    Keyboard.releaseAll();
    if(( millis() - button_millis ) < 500)  return; // debouncing
    if(flag)
    {
        falg = 0;
    }
    else
    {
        flag = 1;
    }
    Serial.println("BUTTON");
    digitalWrite(led, flag);
    button_millis = millis();
}

void right_jump_explosion()
{
    // 오른쪽으로
    Keyboard.press(KEY_RIGHT_ARROW);
    random_delay(20, 40);
    {
        // 점프후
        Keyboard.press(jump_command);
        random_delay(100, 150);
        Keyboard.press('x');
        random_delay(100, 150);
        Keyboard.release('x');
        random_delay(80, 110);
        Keyboard.press(jump_command);
        random_delay(80, 110);
    }
    // 오른쪽 키 해제
    Keyboard.release(KEY_RIGHT_ARROW);
    random_delay(20 * factor,30 * factor);

    // 크루얼스텝
    attack();

    // 익스플로전
    Keyboard.press(meso_explosion_command);
    random_delay(20,35);
    Keyboard.release(meso_explosion_command);
    random_delay(80 * 3.5, 110 * 3.5);
}

void left_jump_explsion()
{
    // 왼쪽으로
    Keyboard.press(KEY_LEFT_ARROW);
    random_delay(20, 40);
    {
        // 점프후
        Keyboard.press(jump_command);
        random_delay(100, 150)
        Keyboard.press('x');
        random_delay(100, 150);
        Keyboard.release('x');
        random_delay(80, 110);
        Keyboard.press(jump_command);
        random_delay(80, 110);
    }
    // 왼쪽 키 해제
    Keyboard.release(KEY_LEFT_ARROW);
    random_delay(20 * factor, 30 * factor);

    // 크루얼스텝
    attack();

    // 익스플로전
    Keyboard.press(meso_explosion_command);
    random_delay(20, 35);
    Keyboard.release(meso_explosion_command);
    random_delay(80 * 3.5, 110 * 3.5);
}

void attack()
{
    int randNum = random(0, 3);
    int randNumber = 0;
    switch (randNum)
    {
    case 0:
        Keyboard.press(attack_command_1);
        random_delay(13, 30);
        Keyboard.release(attack_command_1);
        break;
    case 1:
        Keyboard.press(attack_command_2);
        random_delay(13, 30);
        Keyboard.release(attack_command_2);
        break;
    case 2:
        Keyboard.press(attack_command_3);
        random_delay(13, 30);
        Keyboard.release(attack_command_3);
        break;    
    }
    random_delay(200, 250);
}

void sinmi()
{
#ifdef _DEBUG
    Serial.print(millis());
    Serial.print("-");
    Serial.println("sinmi");
#endif
    Keyboard.press(sinmi_command);      // PRESS sinmi
    random_delay(100, 150);
    Keyboard.release(sinmi_command);
    random_delay(13, 30);
}

void setup()
{
    Keyboard.begin();
    Serial.begin(9600);
    randomSeed(analogRead(0));
    button_millis = millis();

    pinMode(button, INOUT_PULLUP);
    attackInterrupt(digitalPinToInterrupt(button), isr, FALLING);

    pinMode(led, OUTPUT);   // 작동중을 알리기 위한 LED
    digitalWrite(led, LOW);

    sinmi_count = millis();
    sinmi_rand_sec = random(sinmi_cooltime_min, sinmi_cooltime_max);
    attack_count = millis();
    attack_rand_sec = random(attack_cooltime_min, attack_cooltime_max);
}

void loop()
{
    Serial.println(millis());
    if(flag)    // 버튼 누르지 않은 경우만 실행
    {
        if(( millis() - attack_count) > attack_rand_sec )
        {
            // 1. a누르고 시작
            Keyboard.press('a');    // PRESS 'a'
            random_delay(100, 150);
            Keyboard.release('a')   // RELEASE 'a'
            random_delay(200, 250);
            if ( flag == 0 )    return;

            // 2. 오른쪽으로 점프익 * 7번
            for(int i = 0; i<7; i++)
            {
                if( i==2 )
                {
                    // 2칸에서 스인미 실행 체크
                    if(( millis() - sinmi_count ) > sinmi_rand_sec )
                    {
                        // 스인미 체크
                        sinmi();
                        sinmi_rand_sec = random(sinmi_cooltime_min, sinmi_cooltime_max);
                        sinmi_count = millis();
                        if(flag == 0)   return;
                    }
                }
            
                right_jump_explosion();
                if( flag == 0 ) return;
            }

            // 3. 3층으로 ←↑ 방향누르고 q
            Keyboard.press(KEY_LEFT_ARROW);
            random_delay(100, 150);
            Keyboard.press(KEY_UP_ARROW);
            random_delay(100, 150);
            Keyboard.press('q');
            random_delay(100, 150);
            Keyboard.release('q');
            random_delay(100 * 2, 150 * 2);
            Keyboard.release(KEY_UP_ARROW);
            random_delay(100, 150);
            Keyboard.release(KEY_LEFT_ARROW);
            random_delay(500, 600);
            if (flag == 0)  return;

            // 4. alt+(x) 후 (d)
            Keyboard.press(KEY_LEFT_ALT);
            random_delay(100, 150);
            Keyboard.press('x');
            random_delay(100, 150);
            Keyboard.release('x');
            random_delay(80, 110);
            Keyboard.release(KEY_LEFT_ALT);
            random_delay(1000, 1200);
            Keyboard.press('d');
            random_delay(100, 150);
            Keyboard.release('d');
            random_delay(100, 150);
            if (flag == 0)  return;

            // 5. 왼쪽으로 점프익 * 5번
            for(int i = 0; i<5; i++)
            {
                left_jump_explsion();
                if(flag==0) return;
            }

            attack_count = millis();
            attack_rand_sec = random(attack_cooltime_min, attack_cooltime_max);
        }

        // 6.오른쪽으로 점프익 * 5번
        for (int i = 0; i<5; i++)
        {
            right_jump_explosion();
            if(flag == 0)   return;
        }

        random_delay(1000, 1500);
        if(flag == 0)   return;

        // 7. 왼쪽으로 점프익 * 5번
        for( int i =0; i<5;i++)
        {
            left_jump_explsion();
            if(flag == 0)   return;
        }
    }
}
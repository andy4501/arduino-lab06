#include <Keypad.h>
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define WHOLE 1 //全分符
#define HALF 0.5 //半分符
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625

int duration = 500;
int no;
int tune[] = { NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C8, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_G3, NOTE_A3 ,NOTE_B3 ,NOTE_C4 ,NOTE_D4 };

const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns


// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {{'7', '4', '1', '0'},
{'8', '5', '2', 'A'},
{'9', '6', '3', 'B'},
{'C', 'D', 'E', 'F'}};

// 定義 Keypad 連到 Arduino 的接腳 // 按鍵模組，列1~4接腳。
byte rowPins[ROWS] = {2, 3, 4, 5};
// 連到 Keypad 的 4 個 Rows // 按鍵模組，行1~4接腳。
byte colPins[COLS] = {6, 7, 8, 9};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );

void setup(){
Serial.begin(9600);
Serial.println("Please press the keyboard:");

}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if(key!=NO_KEY)
{
if(key>='0' && key<='9')
no=key-'0';

else if(key>='A' && key<='F')
no=key-'A'+10;
tone(17, tune[no],duration);

Serial.print("Key Value : ");
Serial.println(key);//印出所按下的字元
}
}

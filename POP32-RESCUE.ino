<<<<<<< HEAD
#include <POP32_Pixy2.h>
#include <POP32.h>

int L2, L1, C, R1, R2, Dist; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, SlowerSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID แทรกเส้น

#define head_Kp 5 
#define head_Ki 0.0 
#define head_Kd 20

float head_sp = 125; float head_error, hI, hD, hPrevError, head_spd; // ตัวแปรเกี่ยวกับ PID กล้อง(หมุน)
#define dis_Kp 5
#define dis_Ki 0.0 
#define dis_Kd 15

float dis_sp = 170; float dis_error, dI, dD, dPrevError, dis_spd;  // ตัวแปรเกี่ยวกับ PID กล้อง (เคลื่อนที่)

const int h_gap = 10;
const int d_gap = 5;

POP32_Pixy2 pixy;

void setup() {
  pixy.init();
  Speed = 70;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 50; //ความเร็วตอนช้า 50
  SlowerSpeed = 25;
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 70

  beep(1);        //เสียงบัซเซอร์ 0-3

  GripDown();     //ยกแขนลง
  //Grip();
  Put();         //คีบ
  //ShowLCD();      //แสดงค่าเริ่ิ่มต้น LCD ตอนเปิิดเครื่อง
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //Grip();
  //delay(500);   //หน่วงเวลา
//  oled.text(0, 0, "Press A to continue");
//  oled.text(2, 0, "Press B to Skip");
//  oled.show();
  //  if (SW_A) {
  //    SensorCal();
  //  }
  // else {
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  waitAnykey();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  //Forward(Speed, 3000); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็็นนเวลา 2 วินาที
  //TracNormalJC(Speed, 60);
  //TurnLeft();
  // TurnRight();
  // UTurn();
  // TracNormalJC(Speed, 50);
  // TracNomalTime(Speed,1000);
  //MotorStop();
  //TracPos();
=======
#include <POP32.h>
int L2, L1, C, R1, R2, Dist, BL, BC, BR; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBC, RefBR; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID


void setup() {
  Speed = 20;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 40; //ความเร็วตอนช้า 50
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 70
  beep(1);        //เสียงบัซเซอร์ 0-3

  //GripDown();     //ยกแขนลง
  //Grip();         //คีบ
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิดเครื่อง
  //delay(500);   //หน่วงเวลา

  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  // Forward(Speed, 1000); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็นนเวลา 2 วินาที
  // TurnLeft();
  // TurnRight();
  // UTurn();
  // MotorStop();
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
  ResetTimer1();
}

void loop() {
<<<<<<< HEAD
  TracPos1();
  //TracPos();
  //Can2();
  //Finish();
=======
   CanNormal1();
  // Can1();
   Finish();
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
}

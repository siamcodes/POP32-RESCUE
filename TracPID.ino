void TracPID()      //แทรกเส้นแบบ PID
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(Error) <= 1) KpTemp = 1; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID

  LeftOutput = LeftSpeed + Output;        //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  FD2(LeftOutput, RightOutput);   //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error;               //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;              //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJC(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeed(MotorSpeed);
  CalError();
<<<<<<< HEAD
  while (Error < 100) {                  //ยังไม่เจอแยก ให้้ทำการ TracPID
    CheckObstacle();
    TracPos();
=======
  while (Error < 100) {                 //ยังไม่เจอแยก ให้ทำการ TracPID
    // CheckObstacle();                 //เช็คสิ่งกีดขวาง
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
    TracPID();
    CalError();
  }
  Forward(MotorSpeed, Time);
}

<<<<<<< HEAD

//void TracSonar(int MotorSpeed, int Distance) { //แทรกเส้น PID นเจอวัตถุให้หยุด
//  InitialSpeed(MotorSpeed);
//  while (sonar() > Distance) {   //เกินระยะที่กำหนดดให้ แทรก
//    CalError();
//    TracPID();
//  }
//}

=======
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
void TracTime(int MotorSpeed, int Time) {   //แทรกเส้น PID แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {                   //ยังไม่ถึงเวลาที่กำหนดให้ทำต่อไป
    CalError();
    TracPID();
    ReadTimer0();
  }
}

<<<<<<< HEAD
void CheckObstacle() {
  ConvertADC();
  if (Dist <= 20) {
    ao();
    beep();
    delay(200);
    sr(40);
    delay(400);
    fd2(30, 65);
    delay(1200);
    /*sl(20);
      delay(150);
      fd(30)0;*/
    ConvertADC();
    while (R2 == 1) {
      ConvertADC();
    }
    MotorStop();
=======
//void TracSonar(int MotorSpeed, int Distance) {  //แทรกเส้น PID นเจอวัตถุให้หยุด
//  InitialSpeed(MotorSpeed);
//  while (sonar() > Distance) {    //เกินระยะที่กำหนดดให้ แทรก
//    CalError();
//    TracPID();
//  }
//}

//----------------------------------------------------------------
void TracPIDBackward()  //เดินตามเส้นถอยหลังแบบ PID
{
  int Output, LeftOutput, RightOutput, KpTemp;
  if (abs(Error) <= 1) KpTemp = 1; else KpTemp = Kp;
  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID
  LeftOutput = LeftSpeed + Output;        //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  BK2(LeftOutput, RightOutput);   //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error;               //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;              //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJCBackward(int MotorSpeed, int Time) {  //แทรกเส้นถอยหลังแบบ PID
  InitialSpeed(MotorSpeed);
  CalErrorBack();
  while (Error < 100) {  //ยังไม่เจอแยก
    TracPIDBackward();
    CalErrorBack();
  }
  Backward(MotorSpeed, Time);  //ถอยหลังไปอีกนิดตาม Time
}

void TracBackwardTime(int MotorSpeed, int Time) {   //แทรกเส้น PID แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {                   //ยังไม่ถึงเวลาที่กำหนดให้ทำต่อไป
    CalErrorBack();
    TracPIDBackward();
    ReadTimer0();
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
  }
}

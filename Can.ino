//void Can1() {  //สนาม WRG
//  Forward(Speed, 30);
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 1
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว 
//  TurnLeft();             //เลี้ยวซ้าย 2
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 3
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 4
//  TracJC(Speed, 30);       //เตรียมเลี้ยว
//  TurnLeft();             //เลี้ยวซ้าย 5
//  TracJC(Speed,50);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 6
//  TracJC(Speed,50);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 7
//  TracJC(Speed, 50);  //เดินข้ามแยก8
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
//  TurnRight();            //เลี้ยวขวา 9
//  TracJC(SlowSpeed,50);       //เตรียมเลี้ยว
//  TracJC(Speed, 50);  //เดินข้ามแยก10
//  TracJC(SlowSpeed,20);       //เตรียมเลี้ยว
//  TracJC(SlowSpeed,50);  //เดินข้ามแยก11
//  TracJC(SlowSpeed,30);       //เตรียมเลี้ยว
//  ao();
//  delay(500);
//  TurnLeft();             //เลี้ยวซ้าย 12
//  TracJC(ACCSpeed, 200);  //เดินข้ามแยก13
//  TracJC(ACCSpeed, 200);  //เดินข้ามแยก14
//  TracJC(0, 0);    //เตรียมหยุด ท้ายสุด
//  ao();
//}

//---------------------

void Can2(){
  Forward(Speed, 100);          //เดินจากจุดเริ่มต้น 10
  TracJC(Speed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnRight();
  TracTime(ACCSpeed, 2000);
  TracJC(Speed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnRight();
  TracJC(Speed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnRight();
  TracJC(SlowSpeed, 50);
  TurnRight();
  
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  
  TracJC(SlowSpeed, 50);
  MotorStop();
  Backward(SlowSpeed, 100);
  UTurnSlow();
  TracPos();
  GripCan();
  
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);//ข้ามแยก

  TracJC(Speed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();
  TracJC(SlowSpeed, 60);          //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();
  TracJC(SlowSpeed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();
  
  TracTime(ACCSpeed, 2000);
  TracJC(Speed, 50);          //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();
  TracJC(SlowSpeed, 50);
  UTurnSlow();
  PutCan();
  TracTime(Speed, 1000);
}

<<<<<<< HEAD
void ServoGrip() { //กำหนดองศาการคีบ
  for(int pos = 46; pos >= 6; pos -= 1) {
    servo(6, pos);
    delay(100);
  }
}

void ServoPut() { //กำหนดองศาการปล่อย
  for(int pos = 6; pos <= 46; pos += 1) {
    servo(6, pos);
    delay(20);
  }
}

void ServoGripUp() { //กำหนดองศาการยกลง
  for(int pos = 0; pos <= 91; pos += 1) {
    servo(5, pos);
    delay(20);
  }
}

void ServoGripDown() { //กำหนดองศาการยกขึ้น
  for(int pos = 91; pos >= 0; pos -= 1) {
    servo(5, pos);
    delay(20);
  }
}


void Grip() { //คีบหน่วงเวลา
  ao();
  ServoGrip();
  delay(200);
}

void Put() { //ปล่อยหน่วงเวลา
  ao();
  ServoPut();
  delay(200);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUp();
  delay(200);
}

void GripDown() { //ยกแขนลงหน่วงเวลา
  ao();
  ServoGripDown();
  delay(200);
}

void GripCan(){
  //Put();
  //GripDown();         //ยกแขนลง
  Grip();           //คีบ
  GripUp();       //ยกแขนขึ้น
}

void PutCan(){
  GripDown();     //ยกแขนลง
  Put();          //ปล่อย
  GripUp();    //ยกแขนขึ้น
}
=======
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd

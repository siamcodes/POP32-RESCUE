void TracPos() {
  if (pixy.updateBlocks() && pixy.sigSize[1]) {
    int x = pixy.sigInfo[1][0].x;
    int y = pixy.sigInfo[1][0].y;
    head_error = head_sp - x;
    dis_error = dis_sp - y;
    hI = hI + head_error;
    dI = dI + dis_error;    
    hI = constrain(hI, SlowerSpeed, SlowerSpeed);
    dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
    hD = head_error - hPrevError;
    dD = dis_error - dPrevError;
    head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
    dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
    int leftSpeed = constrain(-dis_spd - head_spd, -SlowerSpeed, SlowerSpeed);
    int rightSpeed = constrain(-dis_spd + head_spd, -SlowerSpeed, SlowerSpeed);
    fd2(leftSpeed, rightSpeed);
    if ((abs(head_error) < h_gap) && (abs(dis_error) < d_gap)){
      motor(1, 0);
      motor(2, 0);
      beep();
      delay(1000);
      GripCan();
      delay(2000);
    }
    hPrevError = head_error;
  }
  else{
    sr(20);
  }
}

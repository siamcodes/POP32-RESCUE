void TracPos1() {
  if (pixy.updateBlocks() && pixy.sigSize[1]) {
    int x = pixy.sigInfo[1][0].x;
    head_error = head_sp - x;
    hI = hI + head_error;
    hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
    hD = head_error - hPrevError;
    head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
    int leftSpeed = constrain(-head_spd, -SlowerSpeed, SlowerSpeed);
    int rightSpeed = constrain(head_spd, -SlowerSpeed, SlowerSpeed);
    motor(1, leftSpeed); motor(2, rightSpeed);
    hPrevError = head_error;
    if ((abs(head_error) < h_gap)) {
      int y = pixy.sigInfo[1][0].y;
      dis_error = dis_sp - y;
      dI = dI + dis_error;
      dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
      dD = dis_error - dPrevError;
      dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
      int leftSpeed = constrain(-dis_spd, -SlowerSpeed, SlowerSpeed);
      int rightSpeed = constrain(-dis_spd, -SlowerSpeed, SlowerSpeed);
      motor(1, leftSpeed); motor(2, rightSpeed);
      dPrevError = dis_error;
      if ((abs(head_error) < h_gap) && (abs(dis_error) < d_gap)) {
        motor(1, 0);
        motor(2, 0);
        beep();
        delay(1000);
        GripCan();
        delay(2000);
      }
    }
  }
  else {
    sr(20);
  }
}

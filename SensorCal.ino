void SensorCal() {
  int WhiteVal[5] = {0, 0, 0, 0, 0};
  int BlackVal[5] = {0, 0, 0, 0, 0};
  beep();
  waitSW_A();
  oled.clear();
  oled.text(0, 0, "White");
  oled.show();
  delay(2000);
  waitSW_OK_bmp();
  oled.clear();
  ReadADC();
  WhiteVal[0] = analog(4);
  WhiteVal[1] = analog(3);
  WhiteVal[2] = analog(2);
  WhiteVal[3] = analog(1);
  WhiteVal[4] = analog(0);
  beep();
  delay(1000);
  oled.text(0, 0, "L2 White = %d", WhiteVal[0]);
  oled.text(1, 0, "L1 White = %d", WhiteVal[1]);
  oled.text(2, 0, "C White = %d", WhiteVal[2]);
  oled.text(3, 0, "R1 White = %d", WhiteVal[3]);
  oled.text(4, 0, "R2 White = %d", WhiteVal[4]);
  oled.show();
  beep();
  waitSW_OK_bmp();
  oled.clear();
  oled.text(0, 0, "Black");
  oled.show();
  delay(2000);
  waitSW_OK_bmp();
  oled.clear();
  ReadADC();
  BlackVal[0] = analog(4);
  BlackVal[1] = analog(3);
  BlackVal[2] = analog(2);
  BlackVal[3] = analog(1);
  BlackVal[4] = analog(0);
  beep();
  delay(1000);
  oled.clear();
  oled.text(0, 0, "L2 Black = %d", BlackVal[0]);
  oled.text(1, 0, "L1 Black = %d", BlackVal[1]);
  oled.text(2, 0, "C Black = %d", BlackVal[2]);
  oled.text(3, 0, "R1 Black = %d", BlackVal[3]);
  oled.text(4, 0, "R2 Black = %d", BlackVal[4]);
  oled.show();
  beep();
  waitSW_OK_bmp();
  InitialADC();
  RefL2 = (WhiteVal[0] + BlackVal[0]) / 2;
  RefL1 = (WhiteVal[1] + BlackVal[1]) / 2;
  RefC = (WhiteVal[2] + BlackVal[2]) / 2;
  RefR1 = (WhiteVal[3] + BlackVal[3]) / 2;
  RefR2 = (WhiteVal[4] + BlackVal[4]) / 2;
  beep();
  delay(500);
  beep();
  delay(1000);
  oled.clear();
  oled.text(0, 0, "RefL2 = %d", RefL2);
  oled.text(1, 0, "RefL1 = %d", RefL1);
  oled.text(2, 0, "RefC = %d", RefC);
  oled.text(3, 0, "RefR1 = %d", RefR1);
  oled.text(4, 0, "RefL2 = %d", RefR2);
  oled.show();
  beep();
  delay(750);
  oled.text(6, 0, "Finished!");
  waitAnykey_bmp();
  if (SW_B()) {
    oled.show();
    oled.text(0, 0, "Exiting");
    beep();
    delay(2000);
  }
}

void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  oled.clear();
  oled.text(0, 0, "L2 = %d", L2);
  oled.text(1, 0, "L1 = %d", L1);
  oled.text(2, 0, "C = %d", C);
  oled.text(3, 0, "R1 = %d", R1);
  oled.text(4, 0, "R2 = %d", R2);
<<<<<<< HEAD
  oled.text(5, 0, "Dist = %d", Dist);
=======
  oled.text(0, 11, "Dist = %d", Dist); 
  oled.text(5, 0, "BL = %d", BL);
  oled.text(6, 0, "BC = %d", BC);
  oled.text(7, 0, "BR = %d", BR);
>>>>>>> 82b6c058a954de89a1cb70416bfec16374a5f2dd
  oled.show();
}

void ReadADC() {
  Dist = analog(5)/41;
  
  L2 = analog(4);
  L1 = analog(3);
  C = analog(2);
  R1 = analog(1);
  R2 = analog(0);
}

// PopBatteryInit 
 
int PopBatteryInit()
{
  int v0; // r2
  int *v1; // r3
  __int64 v2; // r0

  dword_61ED64 = 0;
  PopCB[0] = 0;
  dword_61ED78 = (int)&dword_61ED74;
  dword_61ED74 = (int)&dword_61ED74;
  dword_61ED80 = (int)&dword_61ED7C;
  dword_61ED7C = (int)&dword_61ED7C;
  dword_61EE70 = -1;
  qword_61EE80 = 0i64;
  dword_61E588 = (int)PopBatteryWorker;
  dword_61E58C = 0;
  PopBatteryWorkItem = 0;
  v0 = 4;
  v1 = PopCB;
  do
  {
    v1[52] = 2;
    v1 += 4;
    --v0;
  }
  while ( v0 );
  byte_61EE18 = 1;
  byte_61EE19 = 0;
  byte_61EE1A = 4;
  dword_61EE1C = 0;
  dword_61EE24 = (int)&dword_61EE20;
  dword_61EE20 = (int)&dword_61EE20;
  dword_61EE88 = 0;
  byte_61EDF8 = 19;
  byte_61EDF9 = 1;
  word_61EDFA = 0;
  dword_61EE04 = (int)PopBatteryWakeDpc;
  dword_61EE08 = 0;
  dword_61EE14 = 0;
  dword_61EE00 = 0;
  KeInitializeTimerEx(&dword_61EDC0[2], 0);
  byte_61ED70 = 0;
  KeInitializeTimer2((int)PopBatteryWakeTimer, (int)PopPoCoalescinCallback, 0, 2);
  PopBatteryLowLastState = 0;
  LODWORD(v2) = KeQueryInterruptTime();
  PopEstimateSpoiledUntilTime = v2 + 300000000;
  return v2;
}

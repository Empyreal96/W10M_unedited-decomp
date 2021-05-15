// KiSendClockInterruptToClockOwner 
 
int KiSendClockInterruptToClockOwner()
{
  __int16 v1[2]; // [sp+0h] [bp-18h] BYREF
  int v2; // [sp+4h] [bp-14h]
  int v3; // [sp+8h] [bp-10h]

  v1[0] = 1;
  v1[1] = 1;
  v2 = 0;
  v3 = 1 << KiClockTimerOwner;
  return HalRequestClockInterrupt(0, v1);
}

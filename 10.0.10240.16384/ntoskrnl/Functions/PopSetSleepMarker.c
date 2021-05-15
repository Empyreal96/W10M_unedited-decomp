// PopSetSleepMarker 
 
int __fastcall PopSetSleepMarker(char a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+8h] [bp-8h] BYREF

  v6 = a4;
  result = RtlLockBootStatusData(&v6);
  if ( result >= 0 )
  {
    PopSetLastReferenceTime();
    byte_637421 = a1;
    RtlGetSetBootStatusData(v6, 0, 7, (int)&PopBsdPowerTransition, 0x20u, 0);
    result = RtlUnlockBootStatusData();
  }
  return result;
}

// PoClearTransitionMarker 
 
int __fastcall PoClearTransitionMarker(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // [sp+8h] [bp-8h] BYREF

  v5 = a4;
  result = RtlLockBootStatusData(&v5);
  if ( result >= 0 )
  {
    PopBsdPowerTransition = 0;
    dword_63741C = 0;
    byte_637420 = 1;
    byte_637421 = 0;
    PopSetLastReferenceTime();
    RtlGetSetBootStatusData(v5, 0, 7, (int)&PopBsdPowerTransition, 0x20u, 0);
    result = RtlUnlockBootStatusData();
  }
  return result;
}

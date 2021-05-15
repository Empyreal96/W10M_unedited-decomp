// PopSetShutdownMarker 
 
void __fastcall __spoils<R2,R3,R12> PopSetShutdownMarker(int a1, int a2, int a3, int a4)
{
  int v4[2]; // [sp+8h] [bp-8h] BYREF

  v4[0] = a3;
  v4[1] = a4;
  if ( RtlLockBootStatusData(v4) >= 0 )
  {
    PopSetLastReferenceTime();
    byte_637420 = 0;
    RtlGetSetBootStatusData(v4[0], 0, 7, (int)&PopBsdPowerTransition, 0x20u, 0);
    RtlUnlockBootStatusData();
  }
}

// PopCheckShutdownMarker 
 
int __fastcall PopCheckShutdownMarker(int a1, int a2, int a3, int a4)
{
  int v6[4]; // [sp+8h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  if ( RtlLockBootStatusData(v6) >= 0 )
  {
    if ( RtlGetSetBootStatusData(v6[0], 1, 7, (int)&PopBsdPowerTransition, 0x20u, 0) >= 0 && byte_637420 )
      return sub_966A94();
    RtlUnlockBootStatusData();
  }
  return a1;
}

// KdPowerTransition 
 
int __fastcall KdPowerTransition(int a1)
{
  int v1; // r4
  unsigned int v2; // r2
  BOOL v3; // r0
  unsigned int v4; // r5

  v1 = 0;
  if ( !KdPitchDebugger )
  {
    v2 = a1 & 0x80000000 ^ a1;
    if ( v2 == 1 )
    {
      PpmCancelExitLatencyTrace(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
      v3 = KeAreInterruptsEnabled();
      if ( v3 )
        v4 = KeGetCurrentIrql(v3);
      else
        v4 = 15;
      if ( v4 >= 2 )
        ((void (__cdecl *)())off_617A44)();
      v1 = KdPower_0();
      if ( v4 >= 2 )
        ((void (__cdecl *)())off_617A44)();
    }
    else if ( v2 - 2 > 2 )
    {
      v1 = -1073741811;
    }
    else
    {
      v1 = KdPower_0();
    }
  }
  return v1;
}

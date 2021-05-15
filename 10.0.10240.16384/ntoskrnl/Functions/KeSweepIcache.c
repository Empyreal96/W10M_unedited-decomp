// KeSweepIcache 
 
int KeSweepIcache()
{
  int v0; // r0
  int v1; // r5
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r3
  int v5; // r3

  v0 = KfRaiseIrql(12);
  v1 = v0;
  v2 = KeNumberProcessors_0 - 1;
  if ( KeNumberProcessors_0 != 1 )
    v0 = KiIpiSendPacket(1, 0, KiSweepIcacheTarget, 0, 0, 0);
  KiSweepCurrentIcache(v0);
  if ( v2 )
  {
    v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v4 = *(_DWORD *)(v3 + 2944);
    __dmb(0xBu);
    if ( v4 )
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v5 = *(_DWORD *)(v3 + 2944);
        __dmb(0xBu);
      }
      while ( v5 );
    }
  }
  return KfLowerIrql(v1);
}

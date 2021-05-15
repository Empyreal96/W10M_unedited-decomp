// KeFlushQueuedDpcs 
 
int KeFlushQueuedDpcs()
{
  unsigned int v0; // r1
  unsigned int v2; // r2
  unsigned int v3; // [sp+0h] [bp-30h]
  char v4[16]; // [sp+8h] [bp-28h] BYREF
  char v5[8]; // [sp+18h] [bp-18h] BYREF
  unsigned int v6; // [sp+20h] [bp-10h]

  KiGetDeepIdleProcessors(v5, v4);
  v0 = v6;
  do
  {
    if ( !v0 )
      return KeGenericProcessorCallback(v4, KiFlushQueuedDpcsWorker, 0, 2, v3);
    v2 = __clz(__rbit(v0));
    v0 &= ~(1 << v2);
    v3 = v2;
  }
  while ( !*((_DWORD *)*(&KiProcessorBlock + v2) + 439) );
  return sub_51BBAC(&KiProcessorBlock, v0);
}

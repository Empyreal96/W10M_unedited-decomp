// ExpRefreshSystemTime 
 
int ExpRefreshSystemTime()
{
  int v0; // r0
  int v1; // r6
  int result; // r0
  unsigned int v3; // r1
  __int16 v4; // r3
  __int64 v5; // [sp+Ch] [bp-28h] BYREF
  __int16 v6[16]; // [sp+14h] [bp-20h] BYREF

  ExAcquireTimeRefreshLock(1);
  if ( HalQueryRealTimeClock(v6) )
  {
    v0 = RtlTimeFieldsToTime(v6, &v5);
    v1 = ExpLastTimeZoneBias;
    if ( ExpRefreshTimeZoneInformation(v0) )
    {
      if ( v1 != ExpLastTimeZoneBias )
        return sub_80B4D0();
    }
  }
  result = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_WORD *)(v3 + 0x134) + 1;
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}

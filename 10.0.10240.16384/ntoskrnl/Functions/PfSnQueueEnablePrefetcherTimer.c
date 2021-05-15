// PfSnQueueEnablePrefetcherTimer 
 
int __fastcall PfSnQueueEnablePrefetcherTimer(__int64 *a1)
{
  int v2; // r0

  v2 = PfSnAllocateEnablePrefetcherTimer(1);
  if ( !v2 )
    return -1073741670;
  KiSetTimerEx(v2, 0, *a1, 0, 0, v2 + 48);
  return 0;
}

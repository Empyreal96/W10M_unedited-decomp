// PfSnAllocateEnablePrefetcherTimer 
 
int __fastcall PfSnAllocateEnablePrefetcherTimer(int a1)
{
  _DWORD *v2; // r0
  int v3; // r4

  v2 = (_DWORD *)ExAllocatePoolWithTag(512, 88, 2001756995);
  v3 = (int)v2;
  if ( v2 )
  {
    KeInitializeTimerEx(v2, 0);
    KeInitializeDpc(v3 + 48, (int)PfSnEnablePrefetcherTimerRoutine, v3);
    *(_DWORD *)(v3 + 80) = a1;
  }
  return v3;
}

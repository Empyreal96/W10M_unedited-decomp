// PfSnBeginBootPhase 
 
int __fastcall PfSnBeginBootPhase(unsigned int a1)
{
  int v2; // r0
  int v3[4]; // [sp+10h] [bp-10h] BYREF

  if ( a1 >= 5 )
    return -1073741811;
  if ( a1 )
    return sub_69487C();
  v2 = EtwRegister(MS_Kernel_Prefetch_Provider, 0, 0);
  PfSnDetermineEnablePrefetcher(v2);
  PfSnUpdatePrefetcherFlags(3, 1);
  v3[0] = 1294967296;
  v3[1] = -1;
  PfSnQueueEnablePrefetcherTimer(v3);
  return 0;
}

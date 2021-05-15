// PfSnEnablePrefetcherTimerRoutine 
 
int __fastcall PfSnEnablePrefetcherTimerRoutine(int a1, int a2)
{
  PfSnUpdatePrefetcherFlags(*(_DWORD *)(a2 + 80), 0);
  return ExFreePoolWithTag(a2);
}

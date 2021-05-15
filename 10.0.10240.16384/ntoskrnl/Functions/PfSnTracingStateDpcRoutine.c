// PfSnTracingStateDpcRoutine 
 
int __fastcall PfSnTracingStateDpcRoutine(int a1, int a2)
{
  return ExQueueWorkItem((_DWORD *)(a2 + 80), 1);
}

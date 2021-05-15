// PopWakeSourceTimeoutDpc 
 
int __fastcall PopWakeSourceTimeoutDpc(_DWORD *a1)
{
  a1[2] = PopWakeSourceTimeoutWorker;
  a1[3] = a1 - 6;
  *a1 = 0;
  return ExQueueWorkItem(a1, 1);
}

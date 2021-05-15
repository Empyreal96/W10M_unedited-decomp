// ExpSvmDpcRoutine 
 
int __fastcall ExpSvmDpcRoutine(int a1, int a2)
{
  return ExQueueWorkItem((_DWORD *)(ExpSvmWorkQueues + 52 * a2), 2);
}

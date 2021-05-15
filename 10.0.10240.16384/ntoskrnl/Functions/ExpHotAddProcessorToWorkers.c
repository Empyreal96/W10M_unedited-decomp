// ExpHotAddProcessorToWorkers 
 
_DWORD *__fastcall ExpHotAddProcessorToWorkers(_DWORD *result)
{
  int v1; // r4
  int v2; // r3

  v1 = result[590];
  if ( *(&KeNodeBlock + *(unsigned __int16 *)(v1 + 266)) == (char *)&KiNodeInit + 384 * *(unsigned __int16 *)(v1 + 266) )
    v1 = 0;
  v2 = *(_DWORD *)(v1 + 1016);
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
  {
    result = (_DWORD *)ExAllocatePoolWithTag(512, 20);
    if ( result )
    {
      result[2] = ExpWorkerHotAddProcessor;
      result[3] = result;
      *result = 0;
      result[4] = v1;
      result = (_DWORD *)ExQueueWorkItemEx(result, 1, 0);
    }
  }
  return result;
}
